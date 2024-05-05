#include "model.h"

#include <iostream>
#include <filesystem>
#include <assimp/Exporter.hpp>

#include "mesh.h"

using std::string;
using std::vector;

Model::Model(string const &path): m_modelPath(path)
{
    directory = m_modelPath.substr(0, m_modelPath.find_last_of('/'));
}

Model::~Model()
{

}



void Model::loadModel()
{
    Assimp::Importer importer;
    const auto* scene = importer.ReadFile(m_modelPath, aiProcess_Triangulate);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "loadModel" << " :: " << importer.GetErrorString() << std::endl;
    }
    processNode(scene->mRootNode, scene);
}

void Model::convert()
{
    Assimp:: Importer importer;

    std::filesystem::path p_filename(m_modelPath);
    auto extension = p_filename.extension().string();;
    const aiScene * pScene;
    if (extension == ".obj")
    {
        pScene = importer.ReadFile(m_modelPath,
                                   aiProcess_Triangulate |
                                   aiProcess_ConvertToLeftHanded);

    }
    else if (extension == ".assbin")
    {
        std::ifstream ifs(m_modelPath, std::ios::binary);

        ifs.seekg(0, std::ios::end);
        size_t length_of_the_file = ifs.tellg();
        ifs.seekg(0, std::ios::beg);

        auto buffer = std::make_unique <char[]> (length_of_the_file);

        ifs.read(buffer.get(), (long) length_of_the_file);

        pScene = importer.ReadFileFromMemory(buffer.get(), length_of_the_file,
                                             aiProcess_Triangulate |
                                             aiProcess_ConvertToLeftHanded);
        ifs.close();

    }
    else if (extension == ".h3da")
    {
        std::ifstream ifs(filename, std::ios::binary);

        ifs.seekg(0, std::ios::end);
        size_t length_of_the_file = ifs.tellg();
        ifs.seekg(0, std::ios::beg);

        auto buffer = std::make_unique < char[] > (length_of_the_file);

        ifs.read(buffer.get(), (long) length_of_the_file);

        char *p_char = buffer.get();

        for (int i = 0; i < length_of_the_file; i++)
        {
            *p_char = ~ * p_char;
            p_char + +;
        }

        pScene = importer.ReadFileFromMemory(buffer.get(), length_of_the_file,
                                             aiProcess_Triangulate |
                                             aiProcess_ConvertToLeftHanded);
        ifs.close();

    }
    else
    {
        pScene = nullptr;
    }

    if (pScene == nullptr)
        return false;

    processNode(pScene->mRootNode, pScene);

    // save as h3da format file.
    {
        Assimp:: Exporter exporter;
        auto outTmpPath = p_filename.replace_extension().string() + ".tmp";
        auto rs = exporter.Export(pScene, "assbin", outTmpPath);
        switch(rs)
        {
            case aiReturn_SUCCESS:
                std::cout << ("Export result SUCCESS => ") << outTmpPath << std::endl;
                break;
            default:
                std::cout << ("Export result failed ") << exporter.GetErrorString() << std::endl;
                break;
        }


        std::ifstream ifsTmp(outTmpPath, std::ios::binary);

        ifsTmp.seekg(0, std::ios::end);
        size_t length_of_the_file = ifsTmp.tellg();
        ifsTmp.seekg(0, std::ios::beg);

        auto buffer = std::make_unique < char[] > (length_of_the_file);

        ifsTmp.read(buffer.get(), (long) length_of_the_file);

        char *p_char = buffer.get();

        for (int i = 0; i < length_of_the_file; i++)
        {
            *p_char = ~*p_char;
            p_char++;
        }

        auto outPath = p_filename.replace_extension().string() + ".h3da";
        std::ofstream ofs(outPath, std::ios::binary);
        ofs.write(buffer.get(), length_of_the_file);
        ofs.flush();
        ofs.close();
        ifsTmp.close();
        std::remove(outTmpPath.c_str());
    }
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
    for (int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }

    for (int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;

    for (int i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;
        vertex.Position[0] = mesh->mVertices[i].x;
        vertex.Position[1] = mesh->mVertices[i].y;
        vertex.Position[2] = mesh->mVertices[i].z;

        if (mesh->HasNormals())
        {
            vertex.Normal[0] = mesh->mNormals[i].x;
            vertex.Normal[1] = mesh->mNormals[i].y;
            vertex.Normal[2] = mesh->mNormals[i].z;
        }

        if (mesh->mTextureCoords[0])
        {
            vertex.TexCoords[0] = mesh->mTextureCoords[0][i].x;
            vertex.TexCoords[1] = mesh->mTextureCoords[0][i].y;
        }
        else
        {
            vertex.TexCoords[0] = 0.0f;
            vertex.TexCoords[1] = 0.0f;
        }
        vertices.push_back(vertex);
    }

    for (int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh ->mFaces[i];
        for (int j = 0; j < face.mNumIndices; j++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }

    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

    vector<Texture> albedoMap = loadMaterialTextures(material, aiTextureType_DIFFUSE, "floorTexture");
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string _typename)
{
    vector<Texture> textures;

    for (int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        Texture texture;
        texture.Type = _typename;
        texture.Path = str.C_Str();
        textures.push_back(texture);
        std::cout << "loadMaterialTextures" << texture.Path;
    }
    std::cout << std::endl;
    return textures;
}

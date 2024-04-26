#include "model.h"

#include <iostream>
#include "mesh.h"

using std::string;
using std::vector;

Model::Model(string const &path): m_modelPath(path)
{
    directory = m_modelPath.substr(0, m_modelPath.find_last_of('/'));
}

void Model::loadModel()
{
    Assimp::Importer importer;
    const auto* scene = importer.ReadFile(m_modelPath, aiProcess_Triangulate |
        aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace |
        aiProcess_EmbedTextures);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "loadModel" << " :: " << importer.GetErrorString() << std::endl;
    }
    processNode(scene->mRootNode, scene);
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

//    vector<Texture> albedoMap = loadMaterialTextures();
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType* type, std::string typename)
{
    vector<Texture> textures;
    return textures;
}

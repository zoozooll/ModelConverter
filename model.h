#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>

#include "assimp/Importer.hpp"
#include "assimp/code/Material/MaterialSystem.h"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

class Mesh;

struct Texture;

class Model
{
public:
    Model(std::string const &path);
    virtual ~Model();
    void loadModel();
    void convert();

private:
    void processNode(aiNode* node, const aiScene* scene);

    Mesh processMesh(aiMesh* mesh, const aiScene* scene);

    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string _typename);
    std::string m_modelPath;
    std::string directory;
    std::vector<Mesh> meshes;
};

#endif // MODEL_H

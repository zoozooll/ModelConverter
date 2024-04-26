#ifndef MESH_H
#define MESH_H

#include <string>
#include <vector>

class Model;

struct Vertex
{
    float Position[3];
    float Normal[3];
    float TexCoords[2];
};

struct Texture
{
    std::string Type;
    std::string Path;
    int nrComponents;
    int width;
    int height;
    unsigned char* data;
};

class Mesh
{
public:
    Mesh(Model* model, std::vector<Vertex> v, std::vector<unsigned int> i,
         std::vector<Texture> t);

    virtual ~Mesh();

    void setupTextures();

private:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    Model* model = nullptr;
};

#endif // MESH_H

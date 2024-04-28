#include "mesh.h"

Mesh::Mesh(Model* model, std::vector<Vertex> v, std::vector<unsigned int> i,
           std::vector<Texture> t): model(model), vertices(v), indices(i), textures(t)
{
    setupTextures();
}

Mesh::~Mesh()
{

}

void Mesh::setupTextures()
{

}

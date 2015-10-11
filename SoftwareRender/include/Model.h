#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "Vec3f.h"
#include "Vec2f.h"

// Информация о вершине треугольника, сожержит индексы
struct VertexInfo {
    int vi, uvi, ni;
};

class Model {
  private:
    std::vector<Vec3f> verts;
    std::vector<Vec3f> normals;
    std::vector<Vec2f> uvs;
    std::vector<std::vector<VertexInfo>> faces;

  public:
    Model(const char* filename);
    int vertsCount();
    int facesCount();
    Vec3f& vert(int face, int n);
    std::vector<VertexInfo>& face(int idx);
    ~Model();
};

#endif // MODEL_H

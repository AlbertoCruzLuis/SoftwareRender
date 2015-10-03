#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "geometry.h"

// Информация о вершине треугольника, сожержит индексы 
struct VertexInfo {
  int vi,uvi,ni;
};

class Model
{
private:
  std::vector<vec3f> verts;
  std::vector<vec3f> normals;
  std::vector<vec2f> uvs;
  std::vector<std::vector<VertexInfo>> faces;
public:
  Model(const char* filename);
  int vertsCount();
  int facesCount();
  vec3f vert(int face, int n);
  std::vector<VertexInfo>& face(int idx);
  ~Model();
};

#endif // MODEL_H

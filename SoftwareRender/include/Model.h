#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "Vec3f.h"
#include "Vec2f.h"

struct ModelVert {
    Vec3f pos;
    Vec3f normal;
    Vec2f uv;
};

class Model {
    std::vector<ModelVert> verts;
  public:
    Model(const char* filename);
    int vertsCount();
    ModelVert& vert(int idx);
    ~Model();
};

#endif // MODEL_H

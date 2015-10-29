#include "Model.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

Model::Model(const char* filename) {
    //Открываем файл
    std::ifstream in;
    in.open(filename, std::ifstream::in);
    std::string line;
    std::vector<Vec3f> tmpVerts;
    std::vector<Vec3f> tmpNormals;
    std::vector<Vec2f> tmpUVs;
    while(!in.eof()) {
        std::getline(in, line); // читаем строку
        // создаём поток, читающий из конкретнйо строки
        std::istringstream lineStream(line.c_str());
        char dummy; // пустышка, для отсекания лишнего
        if(!line.compare(0, 2, "v ")) {
            lineStream >> dummy;
            Vec3f v;
            for(int i = 0; i < 3; i++)
                lineStream >> v[i];
            tmpVerts.push_back(v);
        } else if(!line.compare(0, 3, "vn ")) {
            lineStream >> dummy >> dummy;
            Vec3f n;
            for(int i = 0; i < 3; i++)
                lineStream >> n[i];
            tmpNormals.push_back(n);
        } else if(!line.compare(0, 3, "vt ")) {
            lineStream >> dummy >> dummy;
            Vec2f uv;
            for(int i = 0; i < 2; i++)
                lineStream >> uv[i];
            tmpUVs.push_back(uv);
        } else if(!line.compare(0, 2, "f ")) {
            //std::vector<VertexInfo> face;
            //VertexInfo tmp;
            ModelVert tmp;
            int vi, uvi, ni , k = 0;
            lineStream >> dummy;
            while(lineStream >> vi >> dummy >> uvi >> dummy >> ni) {
                if (k < 3) {
                    // в *.obj индексы начинаются с 1
                    vi--;
                    uvi--;
                    ni--;
                    tmp.pos = tmpVerts[vi];
                    tmp.normal = tmpNormals[ni];
                    tmp.uv = tmpUVs[uvi];
                    verts.push_back(tmp);
                    k++;
                }
            }
        }
    }
}

Model::~Model() {
}

ModelVert& Model::vert(int idx) {
    return verts[idx];
}

int Model::vertsCount() {
    return verts.size();
}

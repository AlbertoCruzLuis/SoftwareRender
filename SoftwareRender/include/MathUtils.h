#ifndef MATHUTILS_H
#define MATHUTILS_H

#include "Vec3i.h"
#include "Vec3f.h"
#include "Vec2i.h"
#include <algorithm>

class MathUtils
{
public:
    static Vec3f Barycentric(const Vec3f& p1, const Vec3f& p2,const Vec3f& p3,const Vec3f & m) {
        /*
         *     Vec3f u = cross(Vec3f(pts[2][0]-pts[0][0], pts[1][0]-pts[0][0], pts[0][0]-P[0]), Vec3f(pts[2][1]-pts[0][1], pts[1][1]-pts[0][1], pts[0][1]-P[1]));
    if (std::abs(u[2])<1) return Vec3f(-1,1,1); // triangle is degenerate, in this case return smth with negative coordinates
    return Vec3f(1.f-(u.x+u.y)/u.z, u.y/u.z, u.x/u.z);*/
        Vec3f cross = Vec3i(p3.x-p1.x,p2.x-p1.x,p1.x-m.x)^Vec3i(p3.y-p1.y,p2.y-p1.y,p1.y-m.y);
        return { 1.0 - (cross.x+cross.y)/cross.z,cross.y/cross.z,cross.x/cross.z};
        /*
        Vec3f b;
        b[0] = (( m.y-p3.y)*(p2.x-p3.x)-( m.x-p3.x)*(p2.y-p3.y))/
               ((p1.y-p3.y)*(p2.x-p3.x)-(p1.x-p3.x)*(p2.y-p3.y));
        b[1] = (( m.y-p1.y)*(p3.x-p1.x)-( m.x-p1.x)*(p3.y-p1.y))/
               ((p2.y-p1.y)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.y-p1.y));
        b[2] = (( m.y-p1.y)*(p2.x-p1.x)-( m.x-p1.x)*(p2.y-p1.y))/
               ((p3.y-p1.y)*(p2.x-p1.x)-(p3.x-p1.x)*(p2.y-p1.y));
        return b;*/
    };
    static void SortVerts(Vec3f verts[3], int idx) {
        if (verts[0][idx]>verts[1][idx]) { 
            std::swap(verts[0], verts[1]);
        }
        if (verts[0][idx]>verts[2][idx])  {
            std::swap(verts[0], verts[2]);
        }
        if (verts[1][idx]>verts[2][idx]) {
            std::swap(verts[1], verts[2]);
        }
    }
};

#endif // MATHUTILS_H

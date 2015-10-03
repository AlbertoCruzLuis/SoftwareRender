
struct vec2f {
  float x, y;  
  inline float& operator[](const int i) { return (i==0)?x:y; }
};

struct vec3f {
  float x, y, z;  
  inline float& operator[](const int i) { return (i==0)?x:((i==1)?y:z); }
};

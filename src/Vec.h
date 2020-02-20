#ifndef MAZESOLVER_VEC_H
#define MAZESOLVER_VEC_H


// Class to hold a vector
class Vec {
public:
    int y;
    int x;

    Vec() = default;
    ~Vec() = default;
    
    bool operator!=(const Vec& comparator) const;
};


#endif //MAZESOLVER_VEC_H

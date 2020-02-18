#ifndef MAZESOLVER_VEC_H
#define MAZESOLVER_VEC_H


// Class to hold a vector
class Vec {
public:
    int y, x;

    bool operator==(const Vec& comparator) const;

    bool operator!=(const Vec& comparator) const;
};


#endif //MAZESOLVER_VEC_H

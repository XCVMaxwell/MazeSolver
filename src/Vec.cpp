#include "Vec.h"

bool Vec::operator==(const Vec& comparator) const {
    return this->y == comparator.y && this->x == comparator.x;
}

bool Vec::operator!=(const Vec& comparator) const {
    return this->y != comparator.y || this->x != comparator.x;
}
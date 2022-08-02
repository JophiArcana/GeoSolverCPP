//
// Created by Wentinn Liao on 7/31/22.
//

#ifndef GEOSOLVER_CPP_IMMUTABLEPIVOT_H
#define GEOSOLVER_CPP_IMMUTABLEPIVOT_H

#include "EqualityPivot.h"


class Immutable;


template<typename T, typename S, typename = EXTENDS(Entity, T), typename = EXTENDS(T, S), typename = EXTENDS(Immutable, S)>
class ImmutablePivot: EqualityPivot<T> {
public:
    const S *constantElement;

    explicit ImmutablePivot(S *constantElement);

    S *element() override;
};


#endif //GEOSOLVER_CPP_IMMUTABLEPIVOT_H

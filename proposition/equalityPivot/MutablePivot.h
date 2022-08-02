//
// Created by Wentinn Liao on 7/31/22.
//

#ifndef GEOSOLVER_CPP_MUTABLEPIVOT_H
#define GEOSOLVER_CPP_MUTABLEPIVOT_H

#include "EqualityPivot.h"


class Mutable;


template<typename T, typename S, typename = EXTENDS(Entity, T), typename = EXTENDS(T, S), typename = EXTENDS(Mutable, S)>
class MutablePivot: EqualityPivot<T> {
public:
    const S *variableElement;

    explicit MutablePivot(S *variableElement);

    S *element() override;
};


#endif //GEOSOLVER_CPP_MUTABLEPIVOT_H

//
// Created by Wentinn Liao on 7/31/22.
//

#ifndef GEOSOLVER_CPP_DEFINEDPIVOT_H
#define GEOSOLVER_CPP_DEFINEDPIVOT_H

#include "EqualityPivot.h"


template<typename T, typename = EXTENDS(Entity, T)>
class DefinedPivot: public EqualityPivot<T> {
public:
    T *simplestElement;

    explicit DefinedPivot(T *element);

    T *element() override;
};


#endif //GEOSOLVER_CPP_DEFINEDPIVOT_H

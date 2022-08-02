//
// Created by Wentinn Liao on 7/31/22.
//

#include "DefinedPivot.h"


template<typename T, typename S>
T *DefinedPivot<T, S>::element() {
    return this->simplestElement;
}


template<typename T, typename S>
DefinedPivot<T, S>::DefinedPivot(T *element) {
    this->simplestElement = element;
    this->elements.insert(this->simplestElement);
}



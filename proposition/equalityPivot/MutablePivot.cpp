//
// Created by Wentinn Liao on 7/31/22.
//

#include "MutablePivot.h"


template<typename T, typename S, typename UN1, typename UN2, typename UN3>
MutablePivot<T, S, UN1, UN2, UN3>::MutablePivot(S *variableElement) {
    this->variableElement = variableElement;
    this->elements.insert(this->variableElement);
}


template<typename T, typename S, typename UN1, typename UN2, typename UN3>
S *MutablePivot<T, S, UN1, UN2, UN3>::element() {
    return this->variableElement;
}



//
// Created by Wentinn Liao on 7/31/22.
//

#include "ImmutablePivot.h"


template<typename T, typename S, typename UN1, typename UN2, typename UN3>
ImmutablePivot<T, S, UN1, UN2, UN3>::ImmutablePivot(S *constantElement) {
    this->constantElement = constantElement;
    this->elements.insert(this->constantElement);
}


template<typename T, typename S, typename UN1, typename UN2, typename UN3>
S *ImmutablePivot<T, S, UN1, UN2, UN3>::element() {
    return this->constantElement;
}

//
// Created by Wentinn Liao on 7/27/22.
//

#ifndef GEOSOLVER_CPP_EQUALITYPIVOT_H
#define GEOSOLVER_CPP_EQUALITYPIVOT_H

#include <unordered_set>
#include <vector>
#include "../Proposition.h"
#include "../../Utils.h"


class Entity;
class Unicardinal;


/** Section: EqualityPivotBase ====================================================================================== */
class EqualityPivotBase: public Proposition {
public:
    virtual Entity* element() = 0;
};

using Comparator = std::function<bool(EqualityPivotBase *, EqualityPivotBase *)>;


/** Section: EqualityPivot ========================================================================================== */
template<typename T, typename = EXTENDS(Entity, T)>
class EqualityPivot: virtual public EqualityPivotBase {
public:
    T* element() override = 0;

    std::unordered_set<T *> elements;
    std::unordered_set<Entity *> reverseDependencies;
    /**
     *  std::vector<UnicardinalPivot<SymbolicExpression>> symbolic();
     */
    virtual EqualityPivot<T> *merge(EqualityPivot<T> *pivot) = 0;
};


/** Section: Unicardinal Template Specialization ==================================================================== */
class UnicardinalPivotBase: virtual public EqualityPivotBase {
public:
    std::unordered_set<Unicardinal *> reverseComputationalDependencies;

    double value();
};


template<typename T>
class EqualityPivot<T, EXTENDS(Unicardinal, T)>: public UnicardinalPivotBase {
};



#endif //GEOSOLVER_CPP_EQUALITYPIVOT_H

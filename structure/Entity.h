//
// Created by Wentinn Liao on 7/27/22.
//

#ifndef GEOSOLVER_CPP_ENTITY_H
#define GEOSOLVER_CPP_ENTITY_H

#include <set>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include "../Utils.h"


class Unicardinal;
class Multicardinal;

class Proposition;
class EqualityPivotBase;
using Comparator = std::function<bool(EqualityPivotBase *, EqualityPivotBase *)>;


class Entity {
public:
    /** Section: InputType ========================================================================================== */
    struct InputTypeBase {
        virtual std::multiset<EqualityPivotBase *, Comparator> createMultiset() = 0;
    };

    template<typename T, typename = EXTENDS(Entity, T)>
    struct InputType : public InputTypeBase {
        virtual std::function<int(T, T)> &comparator() = 0;

        std::multiset<EqualityPivotBase *, Comparator> createMultiset() override;
        int compareMultisets(std::multiset<EqualityPivotBase *> &t1, std::multiset<EqualityPivotBase *> &t2);
    };

    template<typename T, typename = EXTENDS(Unicardinal, T)>
    struct UnicardinalInputType : InputType<T> {
        std::function<int(T, T)> comparator();
    };

    template<typename T, typename = EXTENDS(Multicardinal, T)>
    struct MulticardinalInputType : InputType<T> {
        std::function<int(T, T)> comparator();
    };

    /** Section: Instance Variables ================================================================================= */
    std::unordered_map<InputTypeBase *, std::multiset<EqualityPivotBase *, Comparator>> inputs;
    std::unordered_set<Proposition *> constraints;
    EqualityPivotBase *equalityPivot;

    /** Section: Default Constructor ================================================================================ */
    Entity();

    /** Section: Virtual Functions ================================================================================== */
    // virtual std::vector<UnicardinalPivot<SymbolicExpression>> symbolic() = 0;
    virtual void deleteSymbolic() = 0;

    virtual void updateLocalVariables(EqualityPivotBase *consumedPivot, EqualityPivotBase *consumerPivot) = 0;

    virtual std::vector<InputTypeBase *> *getInputTypes() = 0;
};


#endif //GEOSOLVER_CPP_ENTITY_H

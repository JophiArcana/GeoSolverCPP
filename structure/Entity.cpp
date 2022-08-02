//
// Created by Wentinn Liao on 7/27/22.
//

#include <set>
#include "Entity.h"


/** Section: InputType ============================================================================================== */
template<typename T, typename S>
std::multiset<EqualityPivotBase *, Comparator> Entity::InputType<T, S>::createMultiset() {
    Comparator comparator = [this](EqualityPivotBase *p1, EqualityPivotBase *p2) {
        return this->comparator()(
                dynamic_cast<EqualityPivot<T> *>(p1)->element(),
                dynamic_cast<EqualityPivot<T> *>(p2)->element()
        ) < 0;
    };
    return std::multiset<EqualityPivotBase *, Comparator>(comparator);
}


template<typename T, typename S>
int Entity::InputType<T, S>::compareMultisets(std::multiset<EqualityPivotBase *> &t1, std::multiset<EqualityPivotBase *> &t2) {
    typename std::multiset<EqualityPivot<T> *>::iterator
            iter1 = t1.begin(),
            iter2 = t2.begin();
    while (iter1 != t1.end() && iter2 != t2.end()) {
        int comparison = this->comparator()(
                *(dynamic_cast<EqualityPivot<T> *>(*iter1)->element()),
                *(dynamic_cast<EqualityPivot<T> *>(*iter2)->element())
        );
        if (comparison != 0) {
            return comparison;
        }
    }
    if (iter1 == t1.end()) {
        return -1;
    } else if (iter2 == t2.end()) {
        return 1;
    } else {
        return 0;
    }
}


/** Section: Default Constructor ==================================================================================== */
Entity::Entity() {
    if (this->getInputTypes() != nullptr) {
        for (InputTypeBase *inputType : *(this->getInputTypes())) {
            this->inputs[inputType] = inputType->createMultiset();
        }
    }
}




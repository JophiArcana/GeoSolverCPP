//
// Created by Wentinn Liao on 7/30/22.
//

#ifndef GEOSOLVER_CPP_UNICARDINAL_H
#define GEOSOLVER_CPP_UNICARDINAL_H

#include <unordered_set>
#include "../Entity.h"


class UnicardinalPivotBase;


class Unicardinal: virtual public Entity {
public:
    // Possibly something like SimpleDoubleProperty
    double value;
    std::unordered_set<UnicardinalPivotBase *> computationalDependencies = {};
    // void createComputationalEdge(UnicardinalPivotBase &p);
    // void deleteComputationalEdges();

    virtual void computeValue() = 0;
};


#endif //GEOSOLVER_CPP_UNICARDINAL_H

//
// Created by Wentinn Liao on 7/31/22.
//

#ifndef GEOSOLVER_CPP_MUTABLE_H
#define GEOSOLVER_CPP_MUTABLE_H

#include "Entity.h"
#include <string>
#include <vector>


class Mutable: virtual public Entity {
public:
    std::string name;

    explicit Mutable(std::string n);

    std::vector<InputTypeBase *> *getInputTypes() override;
};


#endif //GEOSOLVER_CPP_MUTABLE_H

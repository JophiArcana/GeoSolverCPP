//
// Created by Wentinn Liao on 7/31/22.
//

#include "Mutable.h"
#include "Entity.h"

#include <utility>


Mutable::Mutable(std::string n): name(std::move(n)) {}


std::vector<Entity::InputTypeBase *> *Mutable::getInputTypes() {
    return nullptr;
}



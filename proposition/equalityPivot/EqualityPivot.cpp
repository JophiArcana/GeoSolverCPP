//
// Created by Wentinn Liao on 7/27/22.
//

#include "EqualityPivot.h"
#include "../../structure/unicardinal/Unicardinal.h"


/**
 *  template<class T>
 *  EqualityPivot<T>::symbolic() {
 *      return this.element().symbolic();
 *  }
 */


/** Section: Unicardinal Template Specialization ==================================================================== */
double UnicardinalPivotBase::value() {
    return dynamic_cast<Unicardinal *>(this->element())->value;
}





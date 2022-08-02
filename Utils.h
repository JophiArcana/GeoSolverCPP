//
// Created by Wentinn Liao on 7/31/22.
//

#ifndef GEOSOLVER_CPP_UTILS_H
#define GEOSOLVER_CPP_UTILS_H

#define EXTENDS(BaseClass, DerivedClass) std::enable_if_t<std::is_base_of_v<BaseClass, DerivedClass>>
#define EXTENDS_NULL(BaseClass, DerivedClass) std::enable_if_t<std::is_base_of_v<BaseClass, DerivedClass>, std::nullptr_t>


class Utils {

};


#endif //GEOSOLVER_CPP_UTILS_H

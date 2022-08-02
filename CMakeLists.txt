cmake_minimum_required(VERSION 3.22)
project(GeoSolver_CPP)

set(CMAKE_CXX_STANDARD 23)

add_executable(GeoSolver_CPP main.cpp structure/Entity.cpp structure/Entity.h proposition/equalityPivot/EqualityPivot.cpp proposition/equalityPivot/EqualityPivot.h proposition/Proposition.cpp proposition/Proposition.h structure/unicardinal/Unicardinal.cpp structure/unicardinal/Unicardinal.h structure/DefinedEntity.cpp structure/DefinedEntity.h structure/Mutable.cpp structure/Mutable.h structure/Immutable.cpp structure/Immutable.h proposition/equalityPivot/DefinedPivot.cpp proposition/equalityPivot/DefinedPivot.h Utils.cpp Utils.h proposition/equalityPivot/MutablePivot.cpp proposition/equalityPivot/MutablePivot.h proposition/equalityPivot/ImmutablePivot.cpp proposition/equalityPivot/ImmutablePivot.h)

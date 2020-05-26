cmake_minimum_required(VERSION 3.15)
project(exercise5)

set(CMAKE_CXX_STANDARD 14)

include_directories(binarytree)
include_directories(binarytree/lnk)
include_directories(binarytree/vec)
include_directories(bst)
include_directories(bst/avl)
include_directories(bst/rb)
include_directories(container)
include_directories(list)
include_directories(queue)
include_directories(queue/lst)
include_directories(queue/vec)
include_directories(stack)
include_directories(stack/lst)
include_directories(stack/vec)
include_directories(vector)
include_directories(zlasdtest)
include_directories(zmytest)
include_directories(zmytest/RandomGens)
include_directories(zmytest/TreeUtils)
include_directories(zmytest/TreeUtils/treeNavFunctions)
include_directories(zmytest/UtilityFunctions)
include_directories(zmytest/UtilityFunctions/commons)

add_executable(exercise5
        zlasdtest/test.cpp
        zmytest/RandomGens/RandomValues.cpp
        zmytest/test.cpp
        main.cpp)

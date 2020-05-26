//
// Created by Antonio on 15/04/2020.
//

#include <random>
#include "RandomValues.hpp"



std::default_random_engine RandGen(std::random_device{}());

int UnsignedIntValueGenerator(){
    std::uniform_int_distribution<> RandIntDistribution(1, 20);
    return (RandIntDistribution(RandGen));
}

int IntValueGenerator(){
    std::uniform_int_distribution<> RandIntDistribution(-500, 500);
    return (RandIntDistribution(RandGen));
}

float FloatValueGenerator(){
    std::uniform_real_distribution<> RandFloatDistribution(-500, 500);
    float temp = (RandFloatDistribution(RandGen));
    temp = round(temp*1000)/1000;
    return temp;
}

std::string CharValueGenerator(){
    std::string returnstring = "";
    std::uniform_int_distribution<> RandCharDistribution(33,126);
    for(int i=0; i<UnsignedIntValueGenerator(); i++) returnstring += (RandCharDistribution(RandGen));
    return returnstring;
}
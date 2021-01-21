#include <iostream>
#include <string>
#include "sea_otter.h"

Sea_otter::Sea_otter(){
    this->name_ = "sea_otter";
    this->age_ = 1;
    this->price_ = 5000;
    this->num_babies_ = 2;
    this->food_cost_ = 100;
    this->revenue_ = 250;
    this->sick_ = false;
}

Sea_otter::~Sea_otter(){

}
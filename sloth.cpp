#include <iostream>
#include <string>
#include "sloth.h"

Sloth::Sloth(){
    this->name_ = "sloth";
    this->age_ = 1;
    this->price_ = 2000;
    this->num_babies_ = 5;
    this->food_cost_ = 100;
    this->revenue_ = 100;
    this->sick_ = false;
}

Sloth::~Sloth(){

}
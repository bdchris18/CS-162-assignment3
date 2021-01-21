#include <iostream>
#include <string>
#include "monkey.h"

Monkey::Monkey() : Animal() {
    this->name_ = "monkey";
    this->age_ = 1;
    this->price_ = 15000;
    this->num_babies_ = 1;
    this->food_cost_ = 100;
    this->revenue_ = 1500;
    this->sick_ = false;
}

Monkey::~Monkey(){
    // ~Animal();
}
#include <iostream>
#include <string>
#include "animal.h"


Animal::Animal(){
    int age_ = 0;
    int price_ = 0;
    int num_babies_ = 0;
    float food_cost_ = 100;
    int revenue_ = 0;
    bool sick = false;
}

Animal::~Animal(){
}

void Animal::set_name(std::string name){
    this->name_ = name;
}

std::string Animal::get_name() const{
    return this->name_;
}

void Animal::set_age(int age){
    this->age_ = age;
}

int Animal::get_age() const{
    return this->age_;
}

void Animal::set_price(int price){
    this->price_ = price;
}

int Animal::get_price() const{
    return this->price_;
}

void Animal::set_num_babies(int num_babies){
    this->num_babies_ = num_babies;
}

int Animal::get_num_babies() const{
    return this->num_babies_;
}

void Animal::set_food_cost(float food_cost){
    this->food_cost_ = food_cost;
}

float Animal::get_food_cost() const{
    return this->food_cost_;
}

void Animal::set_revenue(int revenue){
    this->revenue_ = revenue;
}

int Animal::get_revenue() const{
    return this->revenue_;
}

void Animal::set_sick(bool sick){
    this->sick_ = sick;
}

bool Animal::get_sick() const{
    return this->sick_;
}

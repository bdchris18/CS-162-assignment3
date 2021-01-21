#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal{
protected:
    std::string name_;
    int age_;
    int price_;
    int num_babies_;
    float food_cost_;
    int revenue_;
    bool sick_;
public:
    Animal();
    ~Animal();
    void set_name(std::string);
    std::string get_name() const;
    void set_age(int);
    int get_age() const;
    void set_price(int);
    int get_price() const;
    void set_num_babies(int);
    int get_num_babies() const;
    void set_food_cost(float);
    float get_food_cost() const;
    void set_revenue(int);
    int get_revenue() const;
    void set_sick(bool);
    bool get_sick() const;
};

#endif
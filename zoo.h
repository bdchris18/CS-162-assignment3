#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <string>
#include "animal.h"


class Zoo{
private:
    int money_;
    int attendance_;
    int year_;
    int num_animals_;
    int month_;
    Animal** animals_;
public:
    Zoo();
    Zoo(const Zoo&);
    Zoo& operator=(const Zoo&);
    ~Zoo();
    void set_money(const int);
    int get_money() const;
    void set_attendance(const int);
    int get_attendance() const;
    void set_year(const int);
    int get_year() const;
    void set_num_animals(const int);
    int get_num_animals() const;
    void set_month(const int);
    int get_month() const;

    void new_month();
    void gain_revenue();
    bool random_animal_sick();
    bool random_animal_birth();
    void add_animals(const int, const int, const int);
    void attendance_boom();
    void buy_animals();
    void print_animals();
    void sell_animal();
    void pay_for_food();
    void cure_animal();
};

#endif
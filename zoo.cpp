

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "zoo.h"
#include "monkey.h"
#include "sea_otter.h"
#include "sloth.h"
#include "animal.h"

Zoo::Zoo(){
    this->money_ = 50000;
    this->attendance_ = 0;
    this->year_ = 1;
    this->num_animals_ = 0;
    this->month_ = 1;
    this->animals_ = NULL;
}

Zoo::Zoo(const Zoo& old_zoo){
    this->attendance_ = old_zoo.attendance_;
    this->year_ = old_zoo.year_;
    this->num_animals_ = old_zoo.num_animals_;
    this->month_ = old_zoo.month_;
    this->animals_ = new Animal*[num_animals_];
    for (int i = 0; i < num_animals_; ++i){
        this->animals_[i] = old_zoo.animals_[i];
    }
}

Zoo& Zoo::operator=(const Zoo& old_zoo){
    if (this != &old_zoo){
        this->attendance_ = old_zoo.attendance_;
        this->year_ = old_zoo.year_;
        this->num_animals_ = old_zoo.num_animals_;
        this->month_ = old_zoo.month_;
        if(this->animals_ != NULL){
            delete [] this->animals_;
        }
        this->animals_ = new Animal*[num_animals_];
        for (int i = 0; i < num_animals_; ++i){
            this->animals_[i] = old_zoo.animals_[i];
        }
    }
}

Zoo::~Zoo(){
    for (int i = 0; i < num_animals_; ++i){
        delete animals_[i];
        animals_[i] = NULL;
    }
    delete [] animals_;
}

void Zoo::set_money(const int money){
    this->money_ = money;
}

int Zoo::get_money() const{
    return this->money_;
}

void Zoo::set_attendance(const int attendance){
    this->attendance_ = attendance;
}

int Zoo::get_attendance() const{
    return this->attendance_;
}

void Zoo::set_year(const int year){
    this->year_ = year;
}

int Zoo::get_year() const{
    return this->year_;
}

void Zoo::set_num_animals(const int num_animal_types){
    this->num_animals_ = num_animal_types;
}

int Zoo::get_num_animals() const{
    return this->num_animals_;
}

void Zoo::set_month(int month){
    this->month_ = month;
}

int Zoo::get_month() const{
    return this->month_;
}

void Zoo::new_month(){
    if(get_month() == 12){
        set_month(0);
        set_year(get_year()+1);
    }
    if(get_month() != 12){
        set_month(get_month()+1);
    }
    printf("\033[0;33m");
    std::cout << "Year: " << get_year() << std::endl;
    std::cout << "Month: " << get_month() << std::endl;
    printf("\033[0;32m"); 
    std::cout << "Money: " << get_money() << std::endl;
    printf("\033[0m");
    gain_revenue();
    pay_for_food();
}

//justification for function size: unreasonable to make a function for each if statement
void Zoo::gain_revenue(){ 
    for (int i = 0; i < get_num_animals(); ++i){
        if (animals_[i]->get_name() == "monkey"){
            money_ = money_ + animals_[i]->get_revenue();
        }
        else if (animals_[i]->get_name() == "monkey" && animals_[i]->get_age() < 6){
            money_ = money_ + animals_[i]->get_revenue()*2;
        }
        if (animals_[i]->get_name() == "sea_otter"){
            money_ = money_ + animals_[i]->get_revenue();
        }
        else if (animals_[i]->get_name() == "sea_otter" && animals_[i]->get_age() < 6){
            money_ = money_ + animals_[i]->get_revenue()*2;
        }
        if (animals_[i]->get_name() == "sloth"){
            money_ = money_ + animals_[i]->get_revenue();
        }
        else if (animals_[i]->get_name() == "sloth" && animals_[i]->get_age() < 6){
            money_ = money_ + animals_[i]->get_revenue()*2;
        }
    }
}

bool Zoo::random_animal_sick(){
    srand(time(NULL));
    int sick_index = rand() % num_animals_;
    for (int i = 0; i < num_animals_; ++i){
        if (i == sick_index){
            animals_[i]->set_sick(true);
        }
    }
}

//Justificatioin for size: easier to manage in one function
bool Zoo::random_animal_birth(){
    bool valid = false;
    for (int i = 0; i < num_animals_; ++i){
        if(animals_[i]->get_age() >= 24){
            valid = true;
            break;
        }
        return false;
    }
    int animal_choice;
    srand(time(NULL));
    int birth_index = rand() % num_animals_;
    for (int i = 0; i < num_animals_; ++i){
        if (i == birth_index && animals_[i]->get_age() >= 24){
            std::string name = animals_[i]->get_name();
            if(name == "monkey"){
                animal_choice = 1;
            }
            else if (name == "sea_otter"){
                animal_choice = 2;
            }
            else {
                animal_choice = 3;
            }
            add_animals(animals_[i]->get_num_babies(), animal_choice, 2);
            return true;
        }
    }
}

//Justificatioin for size: easier to manage in one function
void Zoo::add_animals(const int num_animals_to_add, const int animal_choice, const int function_type){
    const int original_num_animals = get_num_animals();
    const int new_num_animals = get_num_animals() + num_animals_to_add;
    Animal** new_animals_ = new Animal* [new_num_animals];
    for (int i = 0; i < original_num_animals; ++i){
        new_animals_[i] = animals_[i];
    }
    delete [] animals_;
    animals_ = new_animals_;
    set_num_animals(new_num_animals);
    for (int i = original_num_animals; i < new_num_animals; ++i){
        if (animal_choice == 1){
            animals_[i] = new Monkey;
        }
        else if (animal_choice == 2){
            animals_[i] = new Sea_otter;
        }
        else if (animal_choice == 3){
            animals_[i] = new Sloth;
        }
        if(function_type == 1){
            animals_[i]->set_age(24);
        }
    }
}

void Zoo::attendance_boom(){
    srand(time(NULL));
    int rand_revenue = rand() % 400 + 300;
    for (int i = 0; i < num_animals_; ++i){
        if (animals_[i]->get_name() == "monkey"){
            set_money(get_money() + rand_revenue);
        }
    }
}

//Justificatioin for size: a lot easier to manage in one function
void Zoo::buy_animals(){
    bool valid = true;
    int animal_choice = 0;
    int num_animals_to_add = 0;
    while(valid){
        std::cout << "What animal would you like to add?" << std::endl;
        std::cout << "1) Monkey\n2) Sea Otter\n3) Sloth" << std::endl;
        std::cin >> animal_choice;
        if (animal_choice > 0 && animal_choice < 4){
            std::cout << "How many?" << std::endl;
            std::cin >> num_animals_to_add;
            if (animal_choice == 1 && num_animals_to_add*15000 < money_){
                valid = false;
            }
            else if (animal_choice == 2 && num_animals_to_add*5000 < money_){
                valid = false;
            }
            else if (animal_choice == 3 && num_animals_to_add*2000 < money_){
                valid = false;
            }
            else{
                std::cout << "You don't thave enough money to do that" << std::endl;
            }
        }
        else{
            std::cout << "Invalid animal choice" << std::endl;
        }
    }
    add_animals(num_animals_to_add, animal_choice, 1);
    for(int i = 0; i < num_animals_to_add; ++i){
        if(animal_choice == 1){
            set_money(get_money()-15000);
        }
        else if(animal_choice == 2){
            set_money(get_money()-5000);
        }
        else{
            set_money(get_money()-2000);
        }
    }
}

void Zoo::print_animals(){
    for(int i = 0; i < num_animals_; ++i){
        std::cout << "Animal " << i << " " << animals_[i]->get_name() << std::endl;
    }
}

//Justificatioin for size: easier to manage in one function
void Zoo::sell_animal(){
    print_animals();
    bool valid = false;
    int remove_choice = 0;
    int index_of_animal = 0;
    int revenue_of_animal = 0;
    while(!valid){
        valid = true;
        std::cout << "What animal would you like to remove?" << std::endl;
        std::cin >> remove_choice;
        if (remove_choice < 0 || remove_choice >= num_animals_){
            std::cout << "Invalid choice, your zoo only contains " << num_animals_ << " animals." << std::endl;
            valid = false;
        }
    }
    for (int i = 0; i < num_animals_; ++i){
        if (i == remove_choice){
            delete animals_[i];
            index_of_animal = i;
            revenue_of_animal = animals_[i]->get_price();
        }
    }
    Animal** new_animals_ = new Animal* [num_animals_-1];
    for (int i = 0; i < index_of_animal; ++i){
        new_animals_[i] = animals_[i];
    }
    for (int i = index_of_animal+1; i < num_animals_; ++i){
        new_animals_[i-1] = animals_[i];
    }
    delete [] animals_;
    animals_ = new_animals_;
    set_num_animals(num_animals_-1);
    print_animals();
    revenue_of_animal = revenue_of_animal/2;
    set_money(get_money()+revenue_of_animal);
}

void Zoo::pay_for_food(){
    srand(time(NULL));
    float rand_percent = rand() % 50 + 75;
    rand_percent = rand_percent / 100;
    if(month_ > 1 || year_ > 1){
        for (int i = 0; i < num_animals_; ++i){
            animals_[i]->set_food_cost(animals_[i]->get_food_cost()*rand_percent);
        }
    }
    for (int i = 0; i < num_animals_; ++i){
        int food_cost = animals_[i]->get_food_cost();
        set_money(get_money()-food_cost);
    }
}

void Zoo::cure_animal(){
    bool can_not_cure = false;
    int index_of_animal = 0;
    for (int i = 0; i < num_animals_; ++i){
        if (animals_[i]->get_sick() == true && animals_[i]->get_age() >= 24){
            int cure_cost = animals_[i]->get_price() / 2;
            if (get_money() < cure_cost){
                can_not_cure = true;
                break;
            }
            set_money(get_money()-cure_cost);
        }
        else if (animals_[i]->get_sick() == true && animals_[i]->get_age() <= 6){
            if (get_money() < animals_[i]->get_price()){
                can_not_cure = true;
                break;
            }
            set_money(get_money()-animals_[i]->get_price());
        }
    }
    if (can_not_cure == true){
        for (int i = 0; i < num_animals_; ++i){
            if (i == index_of_animal){
                delete animals_[i];
            }
        }
        Animal** new_animals_ = new Animal* [num_animals_-1];
        for (int i = 0; i < index_of_animal; ++i){
            new_animals_[i] = animals_[i];
        }
        for (int i = index_of_animal+1; i < num_animals_; ++i){
            new_animals_[i-1] = animals_[i];
        }
        delete [] animals_;
        animals_ = new_animals_;
        set_num_animals(num_animals_-1);
    }
}
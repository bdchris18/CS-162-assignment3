/*********************************************************************
** Program Filename: zoo_tycoon.cpp
** Author: Brandon Christensen
** Date: 4/10/2020
** Description: main
** Input: user input in main
** Output: none
*********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "zoo.h"

int main(){
    bool game = true;
    bool valid = true;
    bool sick = false;
    int choice;
    Zoo z1;

    printf("\033[0;33m");
    std::cout << "Year: 1\nMonth: 1" << std::endl;
    printf("\033[0;32m");
    std::cout << "Money: 50000" << std::endl;
    printf("\033[0;0m");

    while(game){
        valid = true;
        srand(time(NULL));
        int random_event = rand() % 6 + 1;
        if ((z1.get_year() != 0 && z1.get_month() == 0) || z1.get_num_animals() != 0){
            if (random_event == 1){
                sick = z1.random_animal_sick();
                printf("\033[0;31m");
                std::cout << "An animal is sick" << std::endl;
                printf("\033[0;0m");
            }
            else if (random_event == 2){
                bool birth = z1.random_animal_birth();
                if (birth = true){
                    printf("\033[0;34m");
                    std::cout << "An animal gave birth!" << std::endl;
                    printf("\033[0;0m");
                }
            }
            else if (random_event == 3){
                z1.attendance_boom();
                printf("\033[0;35m");
                std::cout << "There is an attendance boom!" << std::endl;
                printf("\033[0;0m");
            }
            else{
                std::cout << "No special event this month" << std::endl;
            }
        }
        while(valid){
            std::cout << "What would you like to do?" << std::endl;
            std::cout << "1) Buy animals\n2) Sell animals\n3) Go to the next month" << std::endl;
            std::cin >> choice;
            if (choice == 1){
                z1.buy_animals();
            }
            else if (choice == 2){
                if (z1.get_num_animals() == 0){
                    std::cout << "You have no animals, please select a different option" << std::endl;
                }
                else{
                    z1.sell_animal();
                } 
            }
            else if (choice == 3){
                valid = false;
            }
            else{
                std::cout << "Invalid input" << std::endl;
            }
        }
        z1.new_month();
        if (z1.get_money() > 500000){
            valid = false;
            game = false;
            std::cout << "You win the game!" << std::endl;
            std::cout << "You achieved over half a million in " << z1.get_year() << " years and " << z1.get_month() << " months" << std::endl;
        }
        else if(z1.get_money() <= 0 && z1.get_num_animals() == 0){
            valid = false;
            game = false;
            std::cout << "You lose!" << std::endl;
            std::cout << "You lasted for " << z1.get_year() << " years and " << z1.get_month() << " months" << std::endl;
        }
    }

    return 0;
}
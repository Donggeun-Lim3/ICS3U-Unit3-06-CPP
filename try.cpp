// Copyright (C) 2002 Donggeun Lim All rights reserved.
//
// Created by Donggeun Lim
// Created on December 2020
// This program is number guessing game

#include <iostream>
#include <random>
#include <string>

int main() {
    int someRandomNumber;
    std::string integerAsString;
    int integerAsNumber;

    // input
    std::cout << "Enter the number : ";
    std::cin >> integerAsString;
    std::cout << "" << std::endl;

    // process
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(1, 9);  // [1, 9]
    someRandomNumber = idist(rgen);

    try {
        integerAsNumber = std::stoi(integerAsString);

        if (integerAsNumber == someRandomNumber) {
            // output
            std::cout << "You are right!";
            std::cout << "" << std::endl;
            std::cout << "random number is " << someRandomNumber << std::endl;
        } else {
            std::cout << "you are wrong";
            std::cout << "" << std::endl;
            std::cout << "random number is " << someRandomNumber << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "That was not a valid integer";
    }
}

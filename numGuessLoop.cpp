// Copyright (c) 2026 Victor Victor-Calixte All rights reserved.
// .
// Created by: Victor Victor-Calixte
// Date: 11/17/26
// Write what this program does.


#include<iostream>
#include<string>
#include<random>


char const INPT_MSG[] = ("Guess a number between ");
char const ERR_MSG[] = (" isn't a valid input!\n (MUST BE AN INTEGER!)\n");

char const RANG_MSG[] = (" is out of range from: ");
char const ATTMP_MSG[] = ("Please try again!\n");

char const CRT_ANS[] = ("you guessed correctly!\n");
char const ICRT_ANS[] = ("you guessed incorrectly!\n");


int const LEAST_RANGE = 1;
int const MOST_RANGE = 10;

int main() {
    // Generating a random number
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(LEAST_RANGE, MOST_RANGE);
    int randNum = dist(gen);

    // Setting needed varables
    std::string guessNumStr;

    while (true) {
        // Asking the user to guess a number from a range
        std::cout
        << INPT_MSG
        << LEAST_RANGE
        << "-"
        << MOST_RANGE
        << "!: ";

        std::cin
        >> guessNumStr;
        // the try statement will make sure the
        // code safely with invalid user inputs
        try {
            // Converting the input from a string to a integer and decimal
            float guessNumFlo = std::stof(guessNumStr);
            int guessNum = std::stof(guessNumStr);

            // check if the number is outside the range
            if (guessNum < LEAST_RANGE || guessNum > MOST_RANGE) {
                std::cout
                << "Guess: "
                << guessNum
                << RANG_MSG
                << LEAST_RANGE
                << "-"
                << MOST_RANGE
                << "!\n";
                std::cout
                << ATTMP_MSG;

                // Check if the number is a decimal
            } else if (guessNumFlo != guessNum) {
                std::cout
                << guessNumFlo
                << ERR_MSG;

                std::cout
                << ATTMP_MSG;

                // Check if the number is wrong
            } else if (guessNum != randNum) {
                std::cout
                << ICRT_ANS;

                std::cout
                << ATTMP_MSG;

                // If the if statements fail,
                // it means that the guess is correct.
            } else {
                std::cout
                << CRT_ANS;
                break;
            }
        } catch(std::invalid_argument) {
            std::cout
                << "Guess: "
                << guessNumStr
                << RANG_MSG
                << LEAST_RANGE
                << "-"
                << MOST_RANGE
                << "!\n";
                std::cout
                << ATTMP_MSG;
        }
    }
}

#pragma once
#ifndef CRITTER_H
#define CRITTER_H

#include <string>

class Critter {
public:
    // Constructor
    Critter(std::string name, int hunger, int happiness, int energy);

    // Methods
    void feed(int amount);
    void play(int time);
    void talk();
    std::string getPhrase();
    void sleep(int hours);
    void passTime(int hours);
    void printStats();
    void playGuessingGame(); // New method for mini-game

    // Getters
    int getMood() const;
    int getEnergy() const;
    int getHunger() const;

private:
    std::string name;
    int hunger;
    int happiness;
    int energy;
};

#endif

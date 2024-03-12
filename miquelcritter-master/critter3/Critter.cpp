#include "critter.h"
#include <iostream>
#include <string>
#include <cstdlib> // For random number generation
#include <ctime>
using namespace std;

// Constructor que inicialitza els atributs del critter
Critter::Critter(std::string name, int hunger, int happiness, int energy) {
	this->name = name;
	this->hunger = hunger;
	this->happiness = happiness;
	this->energy = energy;
}

// Mètode que permet alimentar el critter
void Critter::feed(int amount) {
	hunger -= amount;
	if (hunger < 0) hunger = 0;
	cout << name << " ate " << amount << " units of food." << std::endl;
}

// Mètode que permet jugar amb el critter
void Critter::play(int time) {
	happiness += time;
	if (happiness > 100) happiness = 100;
	energy -= time;
	if (energy < 0) {
		cout << name << " has run out of energy and needs to rest!" << endl;
		cout << "Game over!" << endl;
		exit(0); // Terminate the program if critter runs out of energy
	}
	hunger -= time / 2; // Decrease hunger while playing
	if (hunger < 0) hunger = 0;
	cout << name << " played for " << time << " hours." << std::endl;

	// Check if critter died due to hunger or mood
	if (hunger >= 100 || happiness <= 0) {
		cout << name << " has died due to hunger or mood!" << endl;
		cout << "Game over!" << endl;
		exit(0); // Terminate the program if critter dies due to hunger or mood
	}
}

// Mètode que permet al critter parlar i mostrar el seu estat d'ànim
void Critter::talk() {
	cout << "I’m a " << name << " and I feel ";
	int mood = getMood();
	cout << getPhrase() << endl;
	hunger -= 10; // Decrease hunger when talking
	if (hunger < 0) hunger = 0;
	energy -= 5; // Decrease energy when talking
	if (energy < 0) {
		cout << name << " has run out of energy and needs to rest!" << endl;
		cout << "Game over!" << endl;
		exit(0); // Terminate the program if critter runs out of energy
	}
}

// Mètode auxiliar que retorna una frase segons l'estat d'ànim del critter
string Critter::getPhrase() {
	int mood = getMood();

	if (mood > 75) {
		return "happy! I could have some sleep.";
	}
	else if (mood > 50) {
		return "a bit bored. Can we do something fun?";
	}
	else if (mood > 25) {
		return "frustrated. I need a break.";
	}
	else {
		return "mad. Please leave me alone.";
	}
}

// Mètode que permet al critter dormir i recuperar energia
void Critter::sleep(int hours) {
	energy += hours;
	if (energy > 100) energy = 100;
	hunger += hours / 2;
	if (hunger > 100) hunger = 100;
	happiness += hours / 2;
	if (happiness > 100) happiness = 100;
	hunger -= hours; // Decrease hunger while sleeping
	if (hunger < 0) hunger = 0;
	cout << name << " slept for " << hours << " hours." << std::endl;

	// Check if critter died due to hunger or mood
	if (hunger >= 100 || happiness <= 0) {
		cout << name << " has died due to hunger or mood!" << endl;
		cout << "Game over!" << endl;
		exit(0); // Terminate the program if critter dies due to hunger or mood
	}
}

// Mètode que permet avançar el temps i actualitzar els atributs del critter en conseqüència
void Critter::passTime(int hours) {
	hunger += hours / 2;
	if (hunger > 100) hunger = 100;
	happiness -= hours / 2;
	if (happiness < 0) happiness = 0;
	energy -= hours / 2;
	if (energy < 0) energy = 0;
	cout << name << " passed " << hours << " hours." << std::endl;
	hunger -= hours / 2; // Decrease hunger while passing time
	if (hunger < 0) hunger = 0;
	energy -= hours / 2; // Decrease energy while passing time
	if (energy < 0) {
		cout << name << " has run out of energy and needs to rest!" << endl;
		cout << "Game over!" << endl;
		exit(0); // Terminate the program if critter runs out of energy
	}
}
// Mètode que mostra les estadístiques del critter
void Critter::printStats() {
	cout << "Name: " << name << std::endl;
	cout << "Hunger: " << hunger << std::endl;
	cout << "Happiness: " << happiness << std::endl;
	cout << "Energy: " << energy << std::endl;
}
void Critter::playGuessingGame() {
	cout << "Welcome to the Critter's Guessing Game!" << endl;
	cout << "I'm thinking of a number between 1 and 6. Can you guess it?" << endl;

	// Generate a random number
	srand(time(0));
	int randomNumber = rand() % 6 + 1;

	int guess;
	int attempts = 0;

	do {
		cout << "Enter your guess: ";
		cin >> guess;
		attempts++;

		if (guess < randomNumber) {
			cout << "Too low! Try again." << endl;
		}
		else if (guess > randomNumber) {
			cout << "Too high! Try again." << endl;
		}
		else {
			cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
			cout << "Oh no! It was a trap! *BANG* You've been shot by the Critter's revolver." << endl;
			cout << "Game over!" << endl;
			exit(0);
		}
	} while (guess != randomNumber && attempts < 3);

	// If the player fails to guess the number in 3 attempts, display a funny message
	cout << "Sorry, you failed to guess the number in 3 attempts. The Critter laughs at your misfortune!" << endl;
}

// Mètode accessor que retorna l'estat d'ànim energia i gana.
int Critter::getMood() const {
	return happiness;
}

int Critter::getEnergy() const {
	return energy;
}

int Critter::getHunger() const {
	return hunger;
}

#include "critter.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Mostra un missatge de benvinguda
    std::cout << "Welcome to critter!" << std::endl;
    // Demana al usuari que introdueixi el nom del seu critter
    std::string name;
    std::cout << "What would you like to name your critter?" << std::endl;
    std::cin >> name;

    // Demana el nivell de dificultat al usuari
    std::cout << "Choose a difficulty level:" << std::endl;
    std::cout << "1. Easy" << std::endl;
    std::cout << "2. Medium" << std::endl;
    std::cout << "3. Hard" << std::endl;
    int level;
    std::cin >> level;

    // Crea una instància de Critter amb els valors inicials depenent del nivell de dificultat escollit
    Critter critter(name, 50, 50, (level == 1 ? 70 : (level == 2 ? 50 : 30)));

    // Mostra un missatge amb el nom del nou critter
    std::cout << "You have a new critter named " << name << "." << std::endl;

    // Bucle infinit per permetre que l'usuari interactui amb el critter fins que decideixi sortir del joc
    while (true) {
        // Mostra les opcions disponibles
        std::cout << std::endl << "What would you like to do?" << std::endl;
        std::cout << "1. Feed" << std::endl;
        std::cout << "2. Play" << std::endl;
        std::cout << "3. Talk" << std::endl;
        std::cout << "4. Sleep" << std::endl;
        std::cout << "5. Pass time" << std::endl;
        std::cout << "6. Check stats" << std::endl;
        std::cout << "7. Guess Game" << std::endl;
        std::cout << "8. Quit" << std::endl;
        // Llegeix la opció escollida per l'usuari
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            // Demana a l'usuari la quantitat de menjar que vol donar al critter i el menja
            std::cout << "How much would you like to feed " << name << "?" << std::endl;
            int amount;
            std::cin >> amount;
            critter.feed(amount);
            break;
        case 2:
            // Demana a l'usuari la quantitat de temps que vol jugar amb el critter i el joca
            std::cout << "How long would you like to play with " << name << "?" << std::endl;
            int time;
            std::cin >> time;
            critter.play(time);
            break;
        case 3:
            // Fa que el critter parli
            critter.talk();
            break;
        case 4:
            // Demana a l'usuari la quantitat d'hores que vol fer dormir al critter i el fa dormir
            std::cout << "How long would you like " << name << " to sleep?" << std::endl;
            int hours;
            std::cin >> hours;
            critter.sleep(hours);

            break;
        case 5:
            cout << "How many hours would you like to pass?" << std::endl;
            cin >> hours;
            critter.passTime(hours);

            // Afegim un missatge per indicar que ha passat el temps
            cout << "Time has passed..." << std::endl;

            // Si el critter s'ha quedat sense energia o ha mort de gana o tristesa, el joc acaba
            if (critter.getEnergy() <= 0) {
                cout << name << " has run out of energy and needs to rest!" << std::endl;
                cout << "Game over!" << std::endl;
                return 0;
            }
            else if (critter.getHunger() >= 100) {
                cout << name << " has starved to death!" << std::endl;
                cout << "Game over!" << std::endl;
                return 0;
            }
            else if (critter.getMood() <= 0) {
                cout << name << " has become too sad and needs some attention!" << std::endl;
                cout << "Game over!" << std::endl;
                return 0;
            }
            break;
        case 6:
            cout << name << "'s stats:" << std::endl;
            cout << "Energy: " << critter.getEnergy() << std::endl;
            cout << "Hunger: " << critter.getHunger() << std::endl;
            cout << "Mood: " << critter.getMood() << std::endl;
            break;
        case 7:
            // Play the mini-game
            critter.playGuessingGame();
            break;

        case 8:
            cout << "Goodbye!" << std::endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }
    return 0;
}
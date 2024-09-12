#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <ctime>

int random(int low, int high) {
    return (std::rand() / (double) RAND_MAX) * (high + 1);
}

enum class Suit:short { 
    SPADES, 
    HEARTS, 
    DIAMONDS, 
    CLUBS 
};

class Pips {
    /* Pips represent the small symbols on the front side of the card.
     * In this program they represent the number of the card */
    
    int value;

    public:
        // Constructor
        Pips(int value) : value(value) { assert(value > 0 && value <14); }

        friend std::ostream& operator<<(std::ostream& out, const Pips& p);
        
        // Getter
        int get_pips() { return value; }
};

class Card {
    Suit suit;
    Pips pips;

    public:
        // Constructor
        Card(int val = 1, Suit s = Suit::SPADES) : pips(val), suit(s) {}
        
        friend std::ostream& operator<<(std::ostream& out, const Card& c);
        
        // Getters
        Suit get_suit() { return suit; }
        Pips get_pips() { return pips; }
};

//// OVERLOADS ////

std::ostream& operator<<(std::ostream& out, const Suit& s) {
    switch(s) {
        case Suit::SPADES: out << "SPADES"; break;
        case Suit::HEARTS: out << "HEARTS"; break;
        case Suit::DIAMONDS: out << "DIAMONDS"; break;
        case Suit::CLUBS: out << "CLUBS"; break;
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const Pips& p) {
    out << p.value;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Card& c) {
    out << c.pips << " of " << c.suit;
    return out;
}

//// MAIN ////

int main() {
    std::srand(std::time(0));
    std::vector<Card> deck;
    
    for (int i = 1; i < 14; i++) {
        deck.push_back(Card(i, Suit::CLUBS));
        deck.push_back(Card(i, Suit::HEARTS));
        deck.push_back(Card(i, Suit::DIAMONDS));
        deck.push_back(Card(i, Suit::SPADES));
    }

    for (Card c : deck) {
        std::cout << c << "\n";
    }

    return 0;
}



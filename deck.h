#ifndef DECK_H_
#define DECK_H_
#include <memory>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include "cards.h"
class Deck{
	std::vector<std::shared_ptr<Card>> deck;
	public:
	//creates a deck of 52 cards
	Deck();
	void shuffle(unsigned seed = std::chrono::system_clock::now().time_since_epoch().count());
	void display();
	std::shared_ptr<Card> getCard(int i) const;
};
#endif

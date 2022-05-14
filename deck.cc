#include "deck.h"
#include "cards.h"
#include <iostream>
using namespace std;

Deck::Deck(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 13; j++){
			deck.emplace_back(make_shared<Card>(Suit(i), Rank(j)));
		}
	}
}

void Deck::shuffle(unsigned seed){
	default_random_engine rng{seed};
	for(int i = 0; i < 1000; i++){
		std::shuffle( deck.begin(), deck.end(), rng );
	}
}
void Deck::display(){
	for(int i = 1; i < deck.size() + 1; i++){
		cout << " "<<*deck[i-1];
		if(i%13 == 0){
			cout << endl;
		}
	}
	cout << endl;
}
shared_ptr<Card> Deck::getCard(int i) const{
	 std::shared_ptr<Card> c = make_shared<Card>(deck[i]->getSuit(), deck[i]->getRank());
	 return c;
}

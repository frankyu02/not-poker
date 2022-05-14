#ifndef CARD_H
#define CARD_H
#include <iostream>
enum Suit{CLUB = 0, DIAMOND, HEART, SPADE};
enum Rank{ ACE = 0, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

class Card{
	friend std::istream &operator>>(std::istream &, Card &c);
	Suit suit;
	Rank rank;
	public:
	//constructor
	Card(Suit s = CLUB, Rank r = ACE);
	//gets suit
	Suit getSuit() const;
	//gets rank
	Rank getRank() const;
};
//compares card by suit and rank
//Both cards must be valid. 
bool operator==(const Card & c1, const Card & c2);
std::ostream & operator <<(std::ostream & out, const Card & c); 
std::istream & operator >>(std::istream & in, Card & c);
#endif

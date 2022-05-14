#include "player.h"
#include <iostream>
using namespace std;
Player::Player(shared_ptr<Table> table, shared_ptr<Deck> deck, int id, shared_ptr<Strategy> strategy)
	:table{table}, deck{deck}, strategy{strategy}, id{id}{
	}
int Player::findCard(Card c) const{
	for(int i = 0; i < hand.size(); i++){
		if(*hand[i] == c){
			return i;
		}
	}
	return -1;
}
void Player::play(const Card c){
	int idx = findCard(c); //find location of card in hand
	Suit suit = c.getSuit();
	table->add_card(hand[idx]); //add card to table
	hand.erase(hand.begin()+idx); //remove card from hand
}
void Player::discard_card(const Card c){
	int idx = findCard(c);
	discard.emplace_back(hand[idx]);
	hand.erase(hand.begin() + idx);
}
bool Player::is_starter() const{
	for(int i = 0; i < hand.size(); i++){
		if(hand[i]->getRank() == Rank::SEVEN && hand[i]->getSuit() == Suit::SPADE){
			return true;
		}
	} 
	return false;
}
bool Player::empty_hand() const{
	return hand.size() == 0;
}
bool Player::legal_move(const Card c) const{
	for(int i = 0; i < legalPlays.size(); i++){
		if(*legalPlays[i] == c){
			return true;
		}
	}
	return false;
}
void Player::reset_player(){
	hand.clear();
	discard.clear();
	legalPlays.clear();
}
int Player::get_score() const{
	return score;
}
void Player::get_legal_play(){
	//reset previous legal plays
	legalPlays.clear();
	//check if it is first turn
	if(table->empty_table()){
		for(int i = 0; i < hand.size(); i++){
			if(hand[i]->getRank() == Rank::SEVEN && hand[i]->getSuit() == Suit::SPADE){
				legalPlays.emplace_back(hand[i]);
				return;
			}
		}
	}
	for(int i = 0; i < hand.size(); i++){
		if(table->check_legal(hand[i])){
			legalPlays.emplace_back(hand[i]);
		}
	}
}
Card Player::get_first_card() const{
	return *hand[0];
}
Card Player::get_first_legal() const{
	return *legalPlays[0];
}
int Player::get_legal_size() const{
	return legalPlays.size();
}
int Player::get_sum(){
	int ret = 0;
	for(int i = 0; i < discard.size(); i++){
		ret += discard[i]->getRank() + 1;
	}
	return ret;
}
void Player::calculate_score(){
	cout << "Player" << id << "'s discards:";
	for(int i = 0; i < discard.size(); i++){
		cout << " " << *discard[i];
	}
	cout << endl;
	int new_score = get_sum();
	cout << "Player" << id << "'s score: " << score << " + " << new_score << " = " <<score + new_score << endl;
	score+= new_score;
}
void Player::display() const{
	cout << "Your hand:";
	for(int i = 0; i < hand.size(); i++){
		cout << " " << *hand[i];
	} 
	cout << endl;
	cout << "Legal plays:";
	for(int i = 0; i < legalPlays.size(); i++){
		cout << " " << *legalPlays[i];
	}
	cout << endl;
}
void Player::get_deck() const{
	deck->display();
}
void Player::set_strategy(shared_ptr<Strategy> s){
	strategy = s;
}
void Player::play_round(){
	strategy->play(*this);
}
int Player::get_id(){
	return id;
}
void Player::add_card(shared_ptr<Card> c){
	hand.emplace_back(c);
}

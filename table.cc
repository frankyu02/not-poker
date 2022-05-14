#include "table.h"
#include "cards.h"
#include <iostream>
using namespace std;

Table::Table(){
	vector<shared_ptr<Card>> tmp;
	for(int i = 0 ; i < 4; i ++){
		table.emplace_back(tmp);
	}
}

void Table::display(){
	for(int i = 0; i < 4; i++){
		if(i == 0){
			cout << "Clubs:";
		} 
		else if(i == 1){
			cout << "Diamonds:";
		}
		else if(i == 2){
			cout << "Hearts:";
		} else{
			cout << "Spades:";
		}
		for(int j = 0; j < table[i].size(); j++){
			cout << " " <<ranks[table[i][j]->getRank()]<< " ";
		}
		cout << endl;
	}
}
bool Table::check_legal(shared_ptr<Card> card){
	//any rank 7 is a legal play
	if(card->getRank() == Rank::SEVEN){
		return true;
	}
	for(int i = 0; i < table[card->getSuit()].size(); i++){
		if(table[card->getSuit()][i]->getRank() == card->getRank() + 1 || table[card->getSuit()][i]->getRank() == card->getRank() - 1){
			return true;
		}
	}
	return false;
}
bool Table::empty_table(){
	for(int i = 0; i < 4; i++){
		if(table[i].size() > 0){
			return false;
		}
	}
	return true;
}
void Table::add_card(shared_ptr<Card> card){
	table[card->getSuit()].emplace_back(card);
	sort(table[card->getSuit()].begin(), table[card->getSuit()].end(), []( const shared_ptr<Card> & lhs, const std::shared_ptr<Card> & rhs ){
			return lhs->getRank() < rhs->getRank();});
}
void Table::clear(){
	for(int i = 0; i < 4; i++){
		table[i].clear();
	}
}

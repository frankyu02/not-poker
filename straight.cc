#include <iostream>
#include <memory>
#include "deck.h"
#include "cards.h"
#include "strategy.h"
#include "computer.h"
#include "human.h"
#include "player.h"
#include "table.h"
#include <vector>
using namespace std;
int main( int argc, char * argv[] ){
	vector<shared_ptr<Player>> players;
	shared_ptr<Deck> deck = make_shared<Deck>();
	shared_ptr<Table> table = make_shared<Table>();
	//initialize players
	for(int i = 0; i < 4; i++){
		char c;
		cout << "Is Player" << i+1 << " a human (h) or a computer (c)?" << endl;
		cin >> c;
		if(c == 'h'){
			shared_ptr<Human> h = make_shared<Human>();
			shared_ptr<Player>p = make_shared<Player>(table, deck, i + 1, h);
			players.push_back(p);
		} else{
			shared_ptr<Computer> c = make_shared<Computer>();
			shared_ptr<Player>p = make_shared<Player>(table, deck, i+1, c);
			players.push_back(p);
		}
	}
	//set hand
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	if( argc > 1 ){
		try{
			 seed = std::stoi( std::string{ argv[1] });
		} catch( std::invalid_argument & e){
			std::cerr << e.what() << std::endl;
			return 1;
		} catch( std::out_of_range & e ){
			std::cerr << e.what() << std:: endl;
			return -1;
		}
	}
	while(players[0]->get_score() < 80 && players[1]->get_score() < 80 && players[2]->get_score() < 80 && players[3]->get_score() < 80){
		deck->shuffle(seed);
		for(int i = 0; i < players.size(); i++){
			players[i]->reset_player();
		}
		table->clear();
		for(int i = 0; i < players.size(); i++){
			int k = i * 13;
			for(int j = k; j < k + 13; j++){
				players[i]->add_card(deck->getCard(j));
			}
		}
		int starter;
		for(int i = 0; i < players.size(); i++){
			if(players[i]->is_starter()){
				starter = i;
				break;
			}
		}
		cout << "A new round begins. It's Player" << starter + 1 <<"'s turn to Play" << endl;
		while(!players[0]->empty_hand() || !players[1]->empty_hand() || !players[2]->empty_hand() || !players[3]->empty_hand()){
			table->display();
			players[starter]->get_legal_play();
			players[starter]->display();
			players[starter]->play_round();
			++starter;
			if(starter > 3){
				starter = 0;
			}
		}
		for(int i = 0; i < players.size(); i++){
			players[i]->calculate_score();
		}
	}
	//get winner
	int lowest = 80;
	for(int i = 0; i < players.size(); i++){
		if(players[i]->get_score() < lowest){
			lowest = players[i]->get_score();
		}
	}
	for(int i = 0; i < players.size(); i++){
		if(players[i]->get_score() == lowest){
			cout << "Player" << players[i]->get_id() <<" wins!" << endl;
		}
	}
}

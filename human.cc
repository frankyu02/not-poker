#include "human.h"
#include "card.h"
#include "computer.h"
#include <iostream>
using namespace std;
void Human::play(Player & p){
	while(true){
		cout << "Please Enter Play" << endl;
		string command;
		Card c;
		cin >> command;
		if(command == "play"){
			cin >> c;
			if (!p.legal_move(c)){
				cout << "This is not a legal play." << endl;
				continue;
			}
			if(p.findCard(c) == -1){
				cout << c <<" is not in your hand. " << endl;
				continue;
			}
			cout << "Player" << p.get_id() << " plays " << c << endl;
			p.play(c);
			return;
		}
		else if(command == "discard"){
			cin >> c;
			if(p.get_legal_size() > 0){
				cout << "You have a legal play. You may not discard." << endl;
				continue;
			}
			if(p.findCard(c) == -1){
				cout << c <<" is not in your hand." << endl;
				continue;
			}
			cout << "Player" << p.get_id() << " discards " << c << endl;
			p.discard_card(c);
			return;
		}
		else if(command == "deck"){
			p.get_deck();
			continue;
		}
		else if(command == "quit"){
			exit(EXIT_SUCCESS);
		}
		else if(command == "ragequit"){
			cout<< "Player" << p.get_id() << " ragequits. A computer will now take over."<< endl;
			shared_ptr<Computer> comp = make_shared<Computer>();
			p.set_strategy(comp);
			p.play_round();
			return;
		} else{
			cout << "invalid command" << endl;
			cin.ignore(1000, '\n');
		}
	}
}

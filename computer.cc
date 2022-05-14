#include <iostream>
#include "player.h"
#include "strategy.h"
#include "computer.h"
using namespace std;
void Computer::play(Player & p){
	if(p.get_legal_size() > 0){
		cout << "Player" << p.get_id() << " plays " << p.get_first_legal() << endl;
		p.play(p.get_first_legal());
		return;
	} else{
		cout << "Player" << p.get_id() << " discards " << p.get_first_card() << endl;
		p.discard_card(p.get_first_card());
		return;
	}
}

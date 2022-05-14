#ifndef COMPUTER_H_
#define COMPUTER_H_
#include "strategy.h"
#include "player.h"
class Computer : public Strategy{
	void play(Player & p) override;
};
#endif

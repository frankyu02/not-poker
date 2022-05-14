#ifndef HUMAN_H_
#define HUMAN_H_
#include "strategy.h"
#include "player.h"
#include <memory>
class Human : public Strategy{
	void play(Player & p) override;
};
#endif

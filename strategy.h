#ifndef STRATEGY_H_
#define STRATEGY_H_
#include "player.h"
#include <memory>
class Player;
class Strategy{
	public:
		virtual ~Strategy(){}
		virtual void play(Player & p) = 0;
};
#endif

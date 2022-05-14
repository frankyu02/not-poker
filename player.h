#ifndef PLAYER_H_
#define PLAYER_H_
#include "cards.h"
#include "deck.h"
#include "table.h"
#include <vector>
#include <memory>
#include "strategy.h"
class Strategy;
class Player{
	int score = 0;
	int id;
	std::vector<std::shared_ptr<Card>> discard;
	std::vector<std::shared_ptr<Card>> hand;
	std::vector<std::shared_ptr<Card>> legalPlays;
	std::shared_ptr<Table> table;
	std::shared_ptr<Deck> deck;
	std::shared_ptr<Strategy> strategy;
	int get_sum();
	public:
	Player(std::shared_ptr<Table> table, std::shared_ptr<Deck> deck, int id, std::shared_ptr<Strategy> strategy = nullptr);
	int findCard(Card c) const;
	void play(const Card c);
	void discard_card(const Card c);
	bool is_starter() const;
	bool empty_hand() const;
	bool legal_move(const Card c) const;
	void reset_player(); //clears hand and discard
	int get_score() const;
	void get_legal_play();
	Card get_first_card() const;
	Card get_first_legal() const;
	int get_legal_size() const;
	void calculate_score();
	void display() const;
	void set_strategy(std::shared_ptr<Strategy> strategy);
	void get_deck() const;
	void play_round();
	int get_id();
	void add_card(std::shared_ptr<Card> c);
};
#endif

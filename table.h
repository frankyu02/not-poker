#ifndef TABLE_H_
#define TABLE_H_
#include "cards.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
class Table{
	std::vector<std::vector<std::shared_ptr<Card>>> table;
	std::string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q","K"};
	public:
	Table();
	void display();
	bool check_legal(std::shared_ptr<Card> card);
	bool empty_table();
	void add_card(std::shared_ptr<Card> card);
	void clear();

};
#endif

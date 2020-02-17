#pragma once
#ifndef __SLOT_MACHINE__
#define __SLOT_MACHINE__

#include <vector>
#include "DisplayObject.h"
#include "Label.h"
#include "SlotWheel.h"

class SlotMachine : public DisplayObject
{
public:
	SlotMachine();
	~SlotMachine();
	void draw() override;
	void update() override;
	void clean() override;
	int getMoney();
	void placeABet(int bet);
	int getBet();
	void spin();
	std::string getMessage();
	int jackPot = 5000;
	int grapes = 0;
	int crowns = 0;
	int lemons = 0;
	int cherries = 0;
	int dices = 0;
	int coins = 0;
	int sevens = 0;
	int blanks = 0;
	std::string fruits = "";
	

private:
	SlotWheel* top[3];
	SlotWheel* middle[3];
	SlotWheel* bottom[3];
	int m_money = 1000;
	int m_bet = 10;
	std::string m_message = "";
	std::string m_defaultMessage = "Your money: " + m_money;
	int m_winnings = 0;
	int check_range(int value, int minValue, int maxValue);
	void checkJackPot();
	void determineWinnings();
	void resetWheel();
};
	


#endif
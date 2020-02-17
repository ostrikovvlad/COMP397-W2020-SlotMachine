#include "SlotMachine.h"
#include "Game.h"

SlotMachine::SlotMachine()
{
	TheTextureManager::Instance()->load("../Assets/textures/slote-machine.png", "slotMachine",
		 TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("slotMachine");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(0.0f, 0.0f));
	setType(SLOT_MACHINE);

	for(int i = 0; i < 3; i++)
	{
		float xPosition = 256.0f;
		if(i == 0)
		{
			xPosition = 256.0f;
		} else if(i == 1)
		{
			xPosition = 420.0f;
		}else if(i == 2)
		{
			xPosition = 584.0f;
		}

		int randNum = rand() % 8;
		switch(randNum)
		{
		case 7:
			top[i] = new SlotWheel("spades", 128, glm::vec2(xPosition, 150.0));
			middle[i] = new SlotWheel("cherries", 255, glm::vec2(xPosition, 290));
			bottom[i] = new SlotWheel("coins", 128, glm::vec2(xPosition, 430.0f));
			break;
		case 6:
			top[i] = new SlotWheel("sevens", 128, glm::vec2(xPosition, 150.0));
			middle[i] = new SlotWheel("spades", 255, glm::vec2(xPosition, 290));
			bottom[i] = new SlotWheel("cherries", 128, glm::vec2(xPosition, 430.0f));
			break;
		case 5:
			top[i] = new SlotWheel("lemon", 128, glm::vec2(xPosition, 150.0));
			middle[i] = new SlotWheel("sevens", 255, glm::vec2(xPosition, 290));
			bottom[i] = new SlotWheel("spades", 128, glm::vec2(xPosition, 430.0f));
			break;
		case 4:
			top[i] = new SlotWheel("grapes", 128, glm::vec2(xPosition, 150.0));
			middle[i] = new SlotWheel("lemon", 255, glm::vec2(xPosition, 290));
			bottom[i] = new SlotWheel("sevens", 128, glm::vec2(xPosition, 430.0f));
			break;
		case 3:
			top[i] = new SlotWheel("dice", 128, glm::vec2(xPosition, 150.0));
			middle[i] = new SlotWheel("grapes", 255, glm::vec2(xPosition, 290));
			bottom[i] = new SlotWheel("lemon", 128, glm::vec2(xPosition, 430.0f));
			break;
		case 2:
			top[i] = new SlotWheel("crown", 128, glm::vec2(xPosition, 150.0));
			middle[i] = new SlotWheel("dice", 255, glm::vec2(xPosition, 290));
			bottom[i] = new SlotWheel("grapes", 128, glm::vec2(xPosition, 430.0f));
			break;
		case 1:
			top[i] = new SlotWheel("coins", 128, glm::vec2(xPosition, 150.0));
			middle[i] = new SlotWheel("crown", 255, glm::vec2(xPosition, 290));
			bottom[i] = new SlotWheel("dice", 128, glm::vec2(xPosition, 430.0f));
			break;
		case 0:
			top[i] = new SlotWheel("cherries", 128, glm::vec2(xPosition, 150.0));
			middle[i] = new SlotWheel("coins", 255, glm::vec2(xPosition, 290));
			bottom[i] = new SlotWheel("crown", 128, glm::vec2(xPosition, 430.0f));
			break;
		}
	}
}

SlotMachine::~SlotMachine()
{
}

void SlotMachine::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("slotMachine", xComponent, yComponent, TheGame::Instance()->getRenderer(), 0, 255, false);
	for (int i = 0; i < 3; i++)
	{
		top[i]->draw();
		middle[i]->draw();
		bottom[i]->draw();
	}
}

void SlotMachine::update()
{
}

void SlotMachine::clean()
{
}

int SlotMachine::getMoney()
{
	return m_money;
}

void SlotMachine::placeABet(int bet)
{
	m_bet += bet;
}

int SlotMachine::getBet()
{
	return m_bet;
}

int SlotMachine::check_range(int value, int minValue, int maxValue)
{
	if (value >= minValue && value <= maxValue)
	{
		return value;
	}
	else
	{
		return !value;
	}
}

void SlotMachine::spin()
{
	std::string betLine[3] = { " ", " ", " " };
	int outCome[3] = { 0, 0, 0 };

	for(int spin = 0; spin < 3; spin++)
	{
		outCome[spin] = floor((rand() % 65) + 1);
		if(outCome[spin] == check_range(outCome[spin], 1, 27))
		{
			betLine[spin] = "spades";
			top[spin]->setId("sevens");
			middle[spin]->setId("spades");
			bottom[spin]->setId("cherries");
			blanks++;
		}
		else if(check_range(outCome[spin], 28, 37))
		{
			betLine[spin] = "grapes";
			top[spin]->setId("dice");
			middle[spin]->setId("grapes");
			bottom[spin]->setId("lemon");
			grapes++;
		}
		else if (check_range(outCome[spin], 38, 46))
		{
			betLine[spin] = "crown";
			top[spin]->setId("coins");
			middle[spin]->setId("crown");
			bottom[spin]->setId("dice");
			crowns++;
		}
		else if (check_range(outCome[spin], 47, 54))
		{
			betLine[spin] = "lemon";
			top[spin]->setId("grapes");
			middle[spin]->setId("lemon");
			bottom[spin]->setId("sevens");
			lemons++;
		}
		else if (check_range(outCome[spin], 55, 59))
		{
			betLine[spin] = "cherries";
			top[spin]->setId("spades");
			middle[spin]->setId("cherries");
			bottom[spin]->setId("coins");
			cherries++;
		}
		else if (check_range(outCome[spin], 60, 62))
		{
			betLine[spin] = "dice";
			top[spin]->setId("crown");
			middle[spin]->setId("dice");
			bottom[spin]->setId("grapes");
			dices++;
		}
		else if (check_range(outCome[spin], 63, 64))
		{
			betLine[spin] = "coins";
			top[spin]->setId("cherries");
			middle[spin]->setId("coins");
			bottom[spin]->setId("crown");
			coins++;
		}
		else if (check_range(outCome[spin], 65, 65))
		{
			betLine[spin] = "sevens";
			top[spin]->setId("lemon");
			middle[spin]->setId("sevens");
			bottom[spin]->setId("spades");
			sevens++;
		}
	}
	//fruits = betLine[0] + " - " + betLine[1] + " - " + betLine[2];
	determineWinnings();
	checkJackPot();
}

std::string SlotMachine::getMessage()
{
	return m_message;
}


void SlotMachine::checkJackPot()
{
	int jackPotTry = floor(rand() % 51 + 1);
	int jackPotWin = floor(rand() % 51 + 1);
	if(jackPotTry == jackPotWin)
	{
		//std::cout << "You won the $" << jackPot << " Jackpot!" << std::endl;
		m_money += jackPot;
		m_message = '$' + std::to_string(jackPot) + " Jackpot!";
		jackPot = 1000;
	}
}

void SlotMachine::determineWinnings()
{
	if(blanks == 0)
	{
		if(grapes == 3)
		{
			m_winnings = m_bet * 10;
		}
		else if(crowns == 3)
		{
			m_winnings = m_bet * 20;
		}
		else if(lemons == 3)
		{
			m_winnings = m_bet * 30;
		}
		else if(cherries == 3)
		{
			m_winnings = m_bet * 40;
		}
		else if(dices == 3)
		{
			m_winnings = m_bet * 50;
		}
		else if (coins == 3) {
			m_winnings = m_bet * 75;
		}
		else if (sevens == 3) {
			m_winnings = m_bet * 100;
		}
		else if (grapes == 2) {
			m_winnings = m_bet * 2;
		}
		else if (crowns == 2) {
			m_winnings = m_bet * 2;
		}
		else if (lemons == 2) {
			m_winnings = m_bet * 3;
		}
		else if (cherries == 2) {
			m_winnings = m_bet * 4;
		}
		else if (dices == 2) {
			m_winnings = m_bet * 5;
		}
		else if (coins == 2) {
			m_winnings = m_bet * 10;
		}
		else if (sevens == 2) {
			m_winnings = m_bet * 20;
		}
		else if (sevens == 1) {
			m_winnings = m_bet * 5;
		}
		else {
			m_winnings = m_bet * 1;
		}
		m_money += m_winnings;
		m_message = "You won $" + std::to_string(m_winnings);
	}
	else
	{
		m_money -= m_bet;
		m_message = "You lost $" + std::to_string(m_bet);
	}
	resetWheel();
}

void SlotMachine::resetWheel()
{
	grapes = 0;
	crowns = 0;
	lemons = 0;
	cherries = 0;
	dices = 0;
	coins = 0;
	sevens = 0;
	blanks = 0;
}


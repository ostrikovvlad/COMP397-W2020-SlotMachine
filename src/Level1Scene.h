#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "SlotMachine.h"
#include "SpinButton.h";
#include "BetButton.h"
#include "UnBetButton.h"
#include "SlotWheel.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects

	SlotMachine* m_pSlotmachine;
	SpinButton* m_pSpinButton;
	BetButton* m_pBetButton;
	UnbetButton* m_pUnbetButton;
	SlotWheel* m_pSlotWheel;
	bool canSpin;

	Label* m_pSlotLabel;
	Label* m_pMoneyLabel;
	Label* m_pBetLabel;
	Label* m_pJackbotLabel;
	Label* m_pWinningslabel;
	

	// private data member
	glm::vec2 m_mousePosition;
	
	
};

#endif /* defined (__LEVEL_1_SCENE__) */

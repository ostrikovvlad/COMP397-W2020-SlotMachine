#include "Level1Scene.h"
#include "Game.h"
#include <iostream>

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pSlotmachine->draw();
	m_pBetButton->draw();
	m_pUnbetButton->draw();
	m_pSpinButton->draw();
	//m_pSlotLabel->draw();
	m_pMoneyLabel->draw();
	m_pBetLabel->draw();
	m_pWinningslabel->draw();
	//m_pSlotWheel->draw();
}

void Level1Scene::update()
{
	m_pSpinButton->setMousePosition(m_mousePosition);
	m_pBetButton->setMousePosition(m_mousePosition);
	m_pUnbetButton->setMousePosition(m_mousePosition);
	m_pBetButton->ButtonClick();
	m_pUnbetButton->ButtonClick();
	m_pSpinButton->ButtonClick();
	if(m_pSlotmachine->getMoney() == 0)
	{
		TheGame::Instance()->changeSceneState(START_SCENE);
	}
}

void Level1Scene::clean()
{
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSpinButton->setMouseButtonClicked(true);
				if(m_pSpinButton->getMouseOver() && m_pSlotmachine->getBet() != 0 && m_pSlotmachine->getBet() <= m_pSlotmachine->getMoney())
				{
					m_pSlotmachine->spin();
					//m_pSlotWheel->draw();
					//m_pSlotLabel->setText(m_pSlotmachine->fruits);
					m_pMoneyLabel->setText("Money: " + std::to_string(m_pSlotmachine->getMoney()));
					m_pWinningslabel->setText(m_pSlotmachine->getMessage());
				}

				if(m_pBetButton->getMouseOver())
				{
					m_pSlotmachine->placeABet(10);
					m_pBetLabel->setText("Bet: " + std::to_string(m_pSlotmachine->getBet()));
				}

				if(m_pUnbetButton->getMouseOver() && m_pSlotmachine->getBet() > 0)
				{
					m_pSlotmachine->placeABet(-10);
					m_pBetLabel->setText("Bet: " + std::to_string(m_pSlotmachine->getBet()));
				}
				

				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSpinButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:
				
				break;
			case SDLK_d:
				
				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:
				
				break;
			case SDLK_d:
				
				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{

	SDL_Color green = { 0, 255, 50, 255 };
	SDL_Color blue = { 0, 50, 255, 255 };
	SDL_Color white = { 255, 255, 255, 255 };

	//m_pSlotWheel = new SlotWheel("crown", 128, glm::vec2(584.0f, 150.0f));
	
	m_pSlotmachine = new SlotMachine();
	m_pSlotmachine->setParent(this);
	addChild(m_pSlotmachine);

	m_pSpinButton = new SpinButton;
	m_pSpinButton->setParent(this);
	addChild(m_pSpinButton);
	m_pSpinButton->setMouseButtonClicked(false);

	m_pBetButton = new BetButton;
	m_pBetButton->setParent(this);
	addChild(m_pBetButton);
	m_pBetButton->setMouseButtonClicked(false);

	m_pUnbetButton = new UnbetButton;
	m_pUnbetButton->setParent(this);
	addChild(m_pUnbetButton);
	m_pUnbetButton->setMouseButtonClicked(false);

	m_pSlotLabel = new Label(m_pSlotmachine->fruits, "Consolas", 80, green, glm::vec2(500.0f, 360.0f));
	m_pSlotLabel->setParent(this);
	addChild(m_pSlotLabel);

	m_pWinningslabel = new Label(std::to_string(m_pSlotmachine->getMoney()), "Consolas", 30, white, glm::vec2(480.0f, 56.0f));
	m_pWinningslabel->setParent(this);
	addChild(m_pWinningslabel);

	m_pMoneyLabel = new Label("Money: " + std::to_string(m_pSlotmachine->getMoney()), "Consolas", 30, white, glm::vec2(150.0f, 56.0f));
	m_pMoneyLabel->setParent(this);
	addChild(m_pMoneyLabel);

	m_pBetLabel = new Label("Bet: " + std::to_string(m_pSlotmachine->getBet()), "Consolas", 30, white, glm::vec2(320.0f, 660.0f));
	m_pBetLabel->setParent(this);
	addChild(m_pBetLabel);
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}


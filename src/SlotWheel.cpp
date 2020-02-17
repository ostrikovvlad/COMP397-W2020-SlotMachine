#include "SlotWheel.h"
#include "Game.h"

SlotWheel::SlotWheel(std::string id, int alpha, glm::vec2 position)
{
	m_id = id;
	m_alpha = alpha;
	m_position = position;
	
	TheTextureManager::Instance()->load("../Assets/textures/cherries.png", "cherries",
		TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/coins.png", "coins",
		TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/crown.png", "crown",
		TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/dice.png", "dice",
		TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/grapes.png", "grapes",
		TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/lemon.png", "lemon",
		TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/sevens.png", "sevens",
		TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/spades.png", "spades",
		TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_id);
	setWidth(size.x);
	setHeight(size.y);
	setPosition(m_position);

	setType(SLOT_WHEEL);
}

SlotWheel::~SlotWheel()
{
	//SDL_DestroyTexture(TheTextureManager::Instance()->getTexture("crown"));
}

void SlotWheel::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw(m_id, xComponent, yComponent, TheGame::Instance()->getRenderer(), 0, m_alpha, false);
}

void SlotWheel::update()
{
}

void SlotWheel::clean()
{
}

void SlotWheel::setId(std::string id)
{
	m_id = id;
}

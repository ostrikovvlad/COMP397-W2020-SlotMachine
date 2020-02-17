#include "BetButton.h"

BetButton::BetButton() : Button("../Assets/textures/plusButton.png",
	"bet", BET_BUTTON, glm::vec2(181.0f, 660.0f))
{
}

BetButton::~BetButton()
{
}

bool BetButton::getMouseOver()
{
	return m_mouseOver();
}

bool BetButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			//std::cout << "Mouse Button Clicked!" << std::endl;
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}

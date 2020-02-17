#include "UnbetButton.h"

UnbetButton::UnbetButton() : Button("../Assets/textures/minusButton.png",
	"unbet", UNBET_BUTTON, glm::vec2(469.0f, 661.0f))
{
}

UnbetButton::~UnbetButton()
{
}

bool UnbetButton::getMouseOver()
{
	return m_mouseOver();
}

bool UnbetButton::ButtonClick()
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

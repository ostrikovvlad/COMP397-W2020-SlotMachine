#include "SpinButton.h"

SpinButton::SpinButton() : Button("../Assets/textures/spinButton.png",
		"spin", SPIN_BUTTON, glm::vec2(722, 660.0f))
{
	m_isClicked = false;
}

SpinButton::~SpinButton()
{
}

bool SpinButton::getMouseOver()
{
	return m_mouseOver();
}

bool SpinButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			std::cout << "Mouse Button Clicked!" << std::endl;
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

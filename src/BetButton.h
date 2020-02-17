#pragma once
#ifndef __BET_BUTTON__
#define __BET_BUTTON__

#include "Button.h"

class BetButton : public Button
{
public:
	BetButton();
	~BetButton();
	bool getMouseOver();
	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif

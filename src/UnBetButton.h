#pragma once
#ifndef __UNBET_BUTTON__
#define __UNBET_BUTTON__

#include "Button.h"

class UnbetButton : public Button
{
public:
	UnbetButton();
	~UnbetButton();
	bool getMouseOver();
	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif


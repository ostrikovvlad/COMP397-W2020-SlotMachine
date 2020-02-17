#pragma once
#ifndef __SPIN_BUTTON__
#define __SPIN_BUTTON_

#include "Button.h"

class SpinButton : public Button
{
public:
	SpinButton();
	~SpinButton();
	bool getMouseOver();
	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif

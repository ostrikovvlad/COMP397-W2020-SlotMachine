#pragma once
#ifndef __SLOT_WHEEL__
#define __SLOT_WHEEL__

#include "DisplayObject.h"

class SlotWheel : public DisplayObject
{
public:
	SlotWheel(std::string id, int alpha, glm::vec2 position);
	~SlotWheel();
	void draw() override;
	void update() override;
	void clean() override;
	void setId(std::string id);

private:
	std::string m_id;
	int m_alpha = 255;
	glm::vec2 m_position;
};

#endif

#pragma once

#include "Camera.h"

class FixedCamera : public Camera {
public:
	virtual void keyboardInput() override;
	virtual void mouseInput(float xPos, float yPos) override;
	virtual void mouseButtonInput(int button, int action, int mods) override;
	virtual void mouseScrollInput(float xOffset, float yOffset) override;
};

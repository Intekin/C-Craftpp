#pragma once

#include <vector>
#include <memory>

#include "States/GameState.h"
#include "Render/RenderMaster.h"

#include "Context.h"
#include "Camera.h"
#include "GlobalInfo.h"

class Application
{

public:
	Application(const Config& config);

	void runLoop();

private:
	std::vector<std::unique_ptr<GameState>> m_states;

};


#pragma once

class Application;

namespace State
{
	class GameState
	{
	public:
		GameState(Application& application);

		virtual void Input() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;

	protected:
		Application* m_application;
	};

}


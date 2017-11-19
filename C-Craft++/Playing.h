#pragma once
#include "GameState.h"
#include "Model.h"

class Application;

namespace State {

	class Playing :
		public GameState
	{
	public:
		Playing(Application& application);

		void Input() override;
		void Update() override;
		void Draw() override;

	private:
		Model m_model;
	};

}
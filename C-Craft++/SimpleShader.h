#pragma once

#include "ShaderProgram.h"

namespace Shader
{

	class SimpleShader : public ShaderProgram
	{
	public:
		SimpleShader();
		~SimpleShader();

	private:
		void BindAttributes() override;
	};
}

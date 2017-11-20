#include "SimpleShader.h"

namespace Shader
{

	SimpleShader::SimpleShader()
		: ShaderProgram("Simple_Vertex", "Simple_Fragment")
	{
	}


	SimpleShader::~SimpleShader()
	{
	}

	void SimpleShader::BindAttributes()
	{
		BindAttribute(0, "inVertexPosition");
	}
}
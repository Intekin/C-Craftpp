#pragma once
#include "BasicShader.h"

class FloraShader : public BasicShader
{
    public:
        FloraShader();
        void loadTime (const float& time);
        void loadLight (float lighting);
    private:
        void getUniforms() override;
        GLuint m_time;
        GLuint m_light;
};

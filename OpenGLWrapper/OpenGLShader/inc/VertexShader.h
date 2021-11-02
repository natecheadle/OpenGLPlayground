#pragma once

#include "Shader.h"

namespace OpenGLWrapper {
    class VertexShader : public Shader {

      public:
        VertexShader(const std::string& shaderFileLoc);
    };
} // namespace OpenGL
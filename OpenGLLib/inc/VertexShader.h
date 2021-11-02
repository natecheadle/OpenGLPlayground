#pragma once

#include "Shader.h"

namespace OpenGL {
    class VertexShader : public Shader {

      public:
        VertexShader(const std::string& shaderFileLoc);
    };
} // namespace OpenGL
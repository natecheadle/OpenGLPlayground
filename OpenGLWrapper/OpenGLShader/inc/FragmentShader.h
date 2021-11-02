#pragma once

#include "Shader.h"

namespace OpenGLWrapper {
    class FragmentShader : public Shader {
      
      public:
        FragmentShader(const std::string& shaderFileLoc);
    };
} // namespace OpenGL
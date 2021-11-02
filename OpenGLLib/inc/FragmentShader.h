#pragma once

#include "Shader.h"

namespace OpenGL {
    class FragmentShader : public Shader {
      
      public:
        FragmentShader(const std::string& shaderFileLoc);
    };
} // namespace OpenGL
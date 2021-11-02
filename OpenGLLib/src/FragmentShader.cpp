#include "FragmentShader.h"

#include <glad/glad.h>

namespace OpenGL {
    FragmentShader::FragmentShader(const std::string& shaderFileLoc)
        : Shader(shaderFileLoc, Shader::Type::Fragment, glCreateShader(GL_FRAGMENT_SHADER))
    {
    }
} // namespace OpenGL

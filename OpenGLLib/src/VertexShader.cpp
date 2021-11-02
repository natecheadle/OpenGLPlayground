#include "VertexShader.h"

#include <glad/glad.h>

namespace OpenGL {
    VertexShader::VertexShader(const std::string& shaderFileLoc)
        : Shader(shaderFileLoc, Shader::Type::Vertex, glCreateShader(GL_VERTEX_SHADER))
    {
    }
} // namespace OpenGL

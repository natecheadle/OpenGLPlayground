#include "Shader.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>

#ifndef SHADER_ROOT_DIR

#endif // !SHADER_ROOT_DIR

namespace OpenGLWrapper {
    Shader::Shader(const std::string& shaderFileLoc, Type type, unsigned int id)
        : m_pShaderCode(nullptr)
        , m_ShaderCode(InitializeShaderFromFile(shaderFileLoc))
        , m_Type(type)
        , m_ID(id)
    {
        Initialize();
    }

    Shader::~Shader() { glDeleteShader(m_ID); }

    bool Shader::Compile()
    {
        std::stringstream error;

        glShaderSource(m_ID, 1, &m_pShaderCode, NULL);
        glCompileShader(m_ID);

        int  success{0};
        char infoLog[512];
        glGetShaderiv(m_ID, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            error << "Comilation Failed: " << infoLog;
            m_Error = error.str();
            return false;
        }

        return true;
    }

    void Shader::Initialize()
    {
        if (!m_ShaderCode.empty())
        {
            m_pShaderCode = m_ShaderCode.c_str();
            m_IsValid     = Compile();
        }
        else
        {
            m_IsValid = false;
            m_Error   = "Cannot compile empty shader.";
        }
    }

    std::string Shader::InitializeShaderFromFile(const std::string& shaderFileLoc)
    {
#ifdef PROJECT_SHADER_ROOT_DIR
        std::string path = std::string(PROJECT_SHADER_ROOT_DIR) + shaderFileLoc;
#else
        std::string path = shaderFileLoc;
#endif
        std::ifstream shaderFile1(path);
        if (shaderFile1.is_open())
        {
            std::ostringstream sstream;
            sstream << shaderFile1.rdbuf();
            return sstream.str();
        }

        return std::string();
    }

} // namespace OpenGL
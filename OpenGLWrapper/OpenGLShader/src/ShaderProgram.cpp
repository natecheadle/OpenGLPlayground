#include "ShaderProgram.h"

#include <glad/glad.h>

#include <sstream>

namespace OpenGLWrapper {
    ShaderProgram::ShaderProgram(const Shader* pFragmentShader, const Shader* pVertexShader)
        : m_ID(glCreateProgram())
        , m_pFragmentShader(pFragmentShader)
        , m_pVertexShader(pVertexShader)
    {
        if (m_pFragmentShader && m_pVertexShader && m_pFragmentShader->IsValid() && m_pVertexShader->IsValid())
        {
            std::stringstream error;
            int               success{0};
            char              infoLog[512];

            glAttachShader(m_ID, pVertexShader->GetID());
            glAttachShader(m_ID, pFragmentShader->GetID());
            glLinkProgram(m_ID);

            glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(m_ID, sizeof(infoLog), NULL, infoLog);
                error << "Linking Shader Program Failed: " << infoLog;
                m_Error   = error.str();
                m_IsValid = false;
            }
            else
            {
                m_IsValid = true;
            }
        }
        else
        {
            m_Error   = "Provided an invalid shader";
            m_IsValid = false;
        }
    }

    ShaderProgram::~ShaderProgram() { glDeleteProgram(m_ID); }

    void ShaderProgram::Use() { glUseProgram(m_ID); }

    void ShaderProgram::SetShaderVar(const std::string& name, bool value)
    {
        glUniform1i(glGetUniformLocation(m_ID, name.c_str()), static_cast<int>(value));
    }

    void ShaderProgram::SetShaderVar(const std::string& name, int value)
    {
        glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value);
    }

    void ShaderProgram::SetShaderVar(const std::string& name, float value)
    {
        glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value);
    }
} // namespace OpenGL

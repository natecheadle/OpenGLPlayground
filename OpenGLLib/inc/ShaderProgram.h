#pragma once

#include "Shader.h"

namespace OpenGL {
    class ShaderProgram {
        const unsigned int m_ID;
        const Shader*      m_pFragmentShader;
        const Shader*      m_pVertexShader;

        bool        m_IsValid;
        std::string m_Error;

      public:
        ShaderProgram(const Shader* pFragmentShader, const Shader* pVertexShader);
        ~ShaderProgram();

        void Use();

        void SetShaderVar(const std::string& name, bool value);
        void SetShaderVar(const std::string& name, int value);
        void SetShaderVar(const std::string& name, float value);

        bool        IsValid() const { return m_IsValid; }
        std::string GetError() const { return m_Error; }
    };
} // namespace OpenGL
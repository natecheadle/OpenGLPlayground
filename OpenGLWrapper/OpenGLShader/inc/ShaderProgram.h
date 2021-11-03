#pragma once

#include "Shader.h"

#include "glm/fwd.hpp"

namespace OpenGLWrapper {
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
        unsigned int GetID() const { return m_ID; }

        void SetShaderVar(const std::string& name, bool value);
        void SetShaderVar(const std::string& name, int value);
        void SetShaderVar(const std::string& name, float value);        
        void SetShaderVar(const std::string& name, const glm::vec2& value);
        void SetShaderVar(const std::string& name, float x, float y);
        void SetShaderVar(const std::string& name, const glm::vec3& value);
        void SetShaderVar(const std::string& name, float x, float y, float z);
        void SetShaderVar(const std::string& name, const glm::vec4& value);
        void SetShaderVar(const std::string& name, float x, float y, float z, float w);
        void SetShaderVar(const std::string& name, const glm::mat2& mat);
        void SetShaderVar(const std::string& name, const glm::mat3& mat);
        void SetShaderVar(const std::string& name, const glm::mat4& mat);


        bool        IsValid() const { return m_IsValid; }
        std::string GetError() const { return m_Error; }
    };
} // namespace OpenGL
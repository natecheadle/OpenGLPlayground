#pragma once


#include <string>

namespace OpenGL {
    class Shader {
      public:
        enum class Type
        {
            Vertex,
            Fragment,
        };

      private:
        const char*        m_pShaderCode;
        const std::string  m_ShaderCode;
        const Type         m_Type;
        const unsigned int m_ID;

        bool        m_IsValid;
        std::string m_Error;

      public:
        bool        IsValid() const { return m_IsValid; }
        std::string GetError() const { return m_Error; }

        Type         GetType() const { return m_Type; }
        unsigned int GetID() const { return m_ID; }

        virtual ~Shader();

      protected:
        Shader(const std::string& shaderFileLoc, Type type, unsigned int id);

      private:
        static std::string InitializeShaderFromFile(const std::string& shaderFileLoc);
        bool               Compile();
        void               Initialize();
    };
} // namespace OpenGL
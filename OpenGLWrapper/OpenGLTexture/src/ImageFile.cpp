#include "ImageFile.h"

#include <glad/glad.h>
#include <stb_image.h>

#include <GLFW/glfw3.h>

#include <cassert>

namespace OpenGLWrapper {
    ImageFile::ImageFile(const std::string& path, bool flipVerticallyOnLoad)
        : m_Width(0)
        , m_Height(0)
        , m_Channels(0)
        , m_pData(nullptr)
    {
        stbi_set_flip_vertically_on_load(flipVerticallyOnLoad);

        std::string absPath = std::string(PROJECT_TEXTURES_ROOT_DIR) + path;
        m_pData             = stbi_load(absPath.c_str(), &m_Width, &m_Height, &m_Channels, 0);

        if (m_Channels == 3)
            m_Format = GL_RGB;
        else if (m_Channels == 4)
            m_Format = GL_RGBA;
        else
            assert(false);

        assert(m_pData);
    }

    ImageFile::~ImageFile() { stbi_image_free(m_pData); }

} // namespace OpenGLWrapper

#pragma once
#include "ImageFile.h"

#include <string>

namespace OpenGLWrapper {
	class Texture {
	public:
		enum class TextureUnit : unsigned int
		{
			Texture0,
			Texture1,
			Texture2,
			Texture3,
			Texture4,
			Texture5,
			Texture6,
			Texture7,
			Texture8,
			Texture9,
			Texture10,
			Texture11,
			Texture12,
			Texture13,
			Texture14,
			Texture15,
			Texture16,
		};

	private:
		const unsigned int m_ID;
		const TextureUnit  m_Unit;
        const unsigned int m_UnitID;

	public:
		Texture(const std::string& path, TextureUnit unit);
		Texture(const ImageFile& image, TextureUnit unit);

		~Texture();

		unsigned int GetID() const { return m_ID; }

		void Activate();
        void Bind();

	protected:
		static unsigned int CreateTexture();
		void                InitializeFromImage(const ImageFile& image);

	private:
		static unsigned int TranslateTextureUnit(TextureUnit unit);
	};
} // namespace OpenGLWrapper

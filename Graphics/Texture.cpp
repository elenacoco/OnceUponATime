#include "Texture.h"
#include "stb_image.h"

Texture::Texture(const char* image, GLenum type, GLuint unit, GLenum format, GLenum pixelType) // Controllare format(va tolta?)
{
	this->type = type;
	this->unit = unit;

	glGenTextures(1, &id);

	glBindTexture(type, id);

	glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT); // altri modi per wrappare la texture GL_MIRRORED_REPEAT, GL_CLAMP_TO_BORDER, GL_CLAMP_TO_EDGE
	glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT); // altri modi per wrappare la texture GL_MIRRORED_REPEAT, GL_CLAMP_TO_BORDER, GL_CLAMP_TO_EDGE

	glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //quando lo minimizzo non mi fa il filtro sfocamento
	glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //quando lo massimizzo mi usa un filtro sfocamento

	int width, height, numCh;

	unsigned char* data = stbi_load(image, &width, &height, &numCh, 0);

	std::cout << "Texture, image:  " << ": " << image << " size: " << width << "x" << height << " channels: " << numCh << std::endl;

	if (data)
	{
		GLenum format;
		if (numCh == 1) {
			format = GL_RED; // OpenGL core profile usa GL_RED per grayscale
		}
		else if (numCh == 3) {
			format = GL_RGB;
		}
		else if (numCh == 4) {
			format = GL_RGBA;
		}
		else {
			std::cerr << "Formato immagine non supportato: " << numCh << " canali.\n";
			stbi_image_free(data);
		}
		glTexImage2D(type, 0, format, width, height, 0, format, pixelType, data);  //ho messo 0 al posto di unit
		glGenerateMipmap(type);
		std::cout << "CLASSE TEXTURE::Texture caricata con successo. ID: " << id << std::endl;
	}
	else
	{
		std::cout << "Errore nel caricamento della texture" << std::endl;
	}

	stbi_image_free(data);
}

Texture::~Texture()
{
}

void Texture::bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(type, id);
}

void Texture::unbind()
{
	glBindTexture(type, 0);
}

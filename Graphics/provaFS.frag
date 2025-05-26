#version 330 core
out vec4 FragColor;

in vec4 vertexColor; //è esattamente la variabile di uscita del vertex shader
in vec2 coordTex; 

uniform sampler2D texture; //non viene modificata dallo shader

void main()
{
	FragColor = texture(texture, coordTex);
}
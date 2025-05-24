#version 330 core
out vec4 FragColor;

in vec4 vertexColor; //è esattamente la variabile di uscita del vertex shader

void main()
{
	FragColor = vertexColor;
}
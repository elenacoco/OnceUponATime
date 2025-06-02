#version 330 core 
layout (location = 0) in vec3 aPos; //vettore 3 di posizione in ingresso nel vertex shader
layout (location = 1) in vec3 aColor; //vettore 3 con i colori in ingresso nel vertex shader
layout (location = 2) in vec2 aTexCoord; //vettore 2 con coordinate di texture 2D

out vec4 vertexColor; //questo vettore di 4 elementi verrà passato al fragment shader (è il colore del vertice)
out vec2 coordTex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	gl_Position = proj * view * model * vec4(aPos, 1.0); 
	coordTex = vec2(aTexCoord.x, aTexCoord.y);
	vertexColor = vec4(aColor, 1.0); //passa il colore del vertice al fragment shader
}
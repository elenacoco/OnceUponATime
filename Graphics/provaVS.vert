#version 330 core 
layout (location = 0) in vec3 aPos; //vettore 3 di posizione in ingresso nel vertex shader
layout (location = 1) in vec2 aTexCoord; //vettore 2 con coordinate di texture 2D

out vec4 vertexColor; //questo vettore di 4 elementi verrà passato al fragment shader (è il colore del vertice)
out vec2 coordTex;

void main()
{
	gl_Position = vec4(aPos, 1.0); 
	coordTex = vec2(aTexCoord.x, aTexCoord.y);
	vertexColor = vec4(0.5, 0.0, 0.5, 1.0); //passa il colore del vertice al fragment shader
}
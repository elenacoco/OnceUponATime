#version 330 core 
layout (location = 0 ) in vec3 aPos; //vettore 3 di posizione in ingresso nel vertex shader

out vec4 vertexColor; //questo vettore di 4 elementi verrà passato al fragment shader (è il colore del vertice)

void main()
{
	gl_Position = vec4(aPos, 1.0); 
	vertexColor = vec4(0.5, 0.0, 0.5, 1.0); //passa il colore del vertice al fragment shader
}
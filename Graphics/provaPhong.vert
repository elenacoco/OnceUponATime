#version 330 core 
layout (location = 0) in vec3 aPos; //vettore 3 di posizione in ingresso nel vertex shader
//layout (location = 1) in vec3 aColor; //vettore 3 con i colori in ingresso nel vertex shader
layout (location = 2) in vec2 aTexCoord; //vettore 2 con coordinate di texture 2D
layout (location = 3) in vec3 aNormal; //vettore 3 con coordinate delle normnali

//out vec4 vertexColor; //questo vettore di 4 elementi verrà passato al fragment shader (è il colore del vertice)
out vec2 coordTex;
out vec3 normal; //passa le normali al fragment shader
out vec3 fragPos; //passa la posizione nel mondo del vertice al fragment shader

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	fragPos = vec3(model * vec4(aPos, 1.0)); //calcola la posizione del vertice nel mondo
	normal = mat3(transpose(inverse(model))) * aNormal; //calcola le normali trasformate
	gl_Position = proj * view * vec4(fragPos,1); 
	coordTex = vec2(aTexCoord.x, aTexCoord.y);
	//vertexColor = vec4(aColor, 1.0); //passa il colore del vertice al fragment shader
}
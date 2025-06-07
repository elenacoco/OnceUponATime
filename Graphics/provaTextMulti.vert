#version 330 core 
layout (location = 0) in vec3 aPos; //vettore 3 di posizione in ingresso nel vertex shader
layout (location = 2) in vec2 aTexCoord; //vettore 2 con coordinate di texture 2D
layout (location = 3) in vec3 aNormal; //vettore 3 con coordinate delle normnali
layout (location = 4) in vec3 aTangent; //vettore 3 con coordinate delle tangenti
layout (location = 5) in vec3 aBitangent; //vettore 3 con coordinate delle bitangenti

out vec2 coordTex;
//out vec3 normal; //passa le normali al fragment shader
out vec3 fragPos; //passa la posizione nel mondo del vertice al fragment shader
out mat3 TBN; //matrice TBN (Tangent, Bitangent, Normal) per il calcolo delle normali

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	fragPos = vec3(model * vec4(aPos, 1.0)); //calcola la posizione del vertice nella camera

	vec3 normal = mat3(transpose(inverse(model))) * aNormal; //calcola le normali trasformate
	vec3 tangent = mat3(transpose(inverse(model))) * aTangent; //calcola la tangente trasformata
	vec3 bitangent = mat3(transpose(inverse(model))) * aBitangent; //calcola la bitangente trasformata

	//vec3 normal = mat3(model) * aNormal; //calcola le normali trasformate
	//vec3 tangent = mat3(model) * aTangent; //calcola la tangente trasformata
	//vec3 bitangent = mat3(model) * aBitangent; //calcola la bitangente trasformata

	TBN = (mat3(normalize(tangent), normalize(bitangent), normalize(normal))); //calcola la matrice TBN

	gl_Position = proj * view * vec4(fragPos, 1); 
	coordTex = vec2(aTexCoord.x, aTexCoord.y);

}
	
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in vec3 aNormal; //vettore 3 con coordinate delle normnali

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

uniform float time;
uniform float curlAmplitude; //ampiezza massima della piegatura
uniform float curlAmount; //più è grande più il seno oscilla, più ci sono curve sulla pagina
uniform float animationSpeed; //velocità dell'animazione

out vec2 TexCoord;
out vec3 normal; //passa le normali al fragment shader
out vec3 fragPos; //passa la posizione nel mondo del vertice al fragment shader

void main()
{
    vec3 pos = aPos;
    
    //assumiamo che la pagina inizia in x=0, quindi curva tutta la parte destra
    if (pos.x > 0.0) { 
        
        //Curvatura in funzione di x e oscillazione temporale
        pos.z += sin(time * animationSpeed) * sin(curlAmount * pos.x) * curlAmplitude;
    }
    
    gl_Position = proj * view * model * vec4(pos, 1.0);

    TexCoord = aTexCoord;

    fragPos = vec3(model * vec4(aPos, 1.0)); //calcola la posizione del vertice nel mondo
	
	normal = mat3(transpose(inverse(model))) * aNormal; //calcola le normali trasformate
}
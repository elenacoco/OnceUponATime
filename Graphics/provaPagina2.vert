#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

uniform float time;
uniform float curlAmplitude; //ampiezza massima della piegatura
uniform float curlAmount; //più è grande più il seno oscilla, più ci sono curve sulla pagina
uniform float animationSpeed; //velocità dell'animazione

out vec2 TexCoord;

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
}
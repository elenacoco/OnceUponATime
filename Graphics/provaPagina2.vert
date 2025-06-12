#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
uniform float time;
uniform float curlRadius;
uniform float curlAmount;

out vec2 TexCoord;

void main()
{
    vec3 pos = aPos;
    
    // Calcola la distanza dalla linea di "piega"
    float distanceFromFold = pos.x; // assumendo piegatura lungo asse Y
    
    if (distanceFromFold > 0.0) {
        // Applica curvatura solo alla parte che si sta sollevando
        float angle = distanceFromFold * curlAmount;
        float radius = curlRadius;
        
        // Trasformazione cilindrica
        pos.x = radius * sin(angle);
        pos.z = radius * (1.0 - cos(angle));
        
        // Aggiunta di oscillazione temporale
        pos.z += sin(time * 2.0) * 0.1 * distanceFromFold;
    }
    
    gl_Position = proj * view * model * vec4(pos, 1.0);
    TexCoord = aTexCoord;
}
#version 330 core

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

uniform float time;

// Pagina curva: parametri
uniform float flipDuration;   // quanto dura l'effetto (es. 2.0 sec)
uniform float bendAmount;     // curvatura massima (es. 0.5)
uniform float pageWidth;      // larghezza totale della pagina (es. 2.0)

// Calcolo curvatura
float smoothFlip(float t) {
    // Interpolazione dolce da 0 a 1 a 0 (come un battito d’ali)
    return sin(t * 3.14159); // si muove avanti e poi torna
}

void main() {
    vec3 pos = aPosition;

    // Normalizza posizione X ? [0, 1] (da destra a sinistra)
    float xNorm = (pos.x + (pageWidth / 2.0)) / pageWidth;

    // Tempo relativo ? [0, 1]
    float t = mod(time / flipDuration, 1.0);
    float flip = smoothFlip(t); // ? [0, 1]

    // Crea una piega lungo X, alzando lungo Z (verso l'alto) VOGLIAMO LA PIEGA LUNGO X
    // La piega avanza da destra a sinistra (xNorm > (1 - flip))
    float edge = 1.0 - flip;
    if (xNorm > edge) {
        float bend = (xNorm - edge) / (1.0 - edge); // da 0 a 1
        float theta = bend * bendAmount * 3.14159;  // piega in rad
        float x = cos(theta) * (pos.x - (pageWidth / 2.0)) + (pageWidth / 2.0);
        float z = sin(theta) * (pos.x - (pageWidth / 2.0));
        pos.x = x;
        pos.z += z; // curvatura verso l’alto
    }

    gl_Position = proj * view * model * vec4(pos, 1.0);
    TexCoord = aTexCoord;
}
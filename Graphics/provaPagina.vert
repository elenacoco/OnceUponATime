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

    float xNorm = pos.x / pageWidth; // da 0 (sx) a 1 (dx)

    float t = mod(time / flipDuration, 1.0); // tempo normalizzato
    float flip = smoothFlip(t);             // va da 0 a 1 (puoi usare smoothstep or sin(t * PI))

    float edge = 1.0 - flip;                // bordo che si sposta da dx a sx
    float foldX = edge * pageWidth;         // posizione X della piega

    if (pos.x > foldX) {
        float bend = (pos.x - foldX) / (pageWidth - foldX); // da 0 a 1 solo oltre il bordo

        float theta = bend * bendAmount * 3.14159;

        // Ruota attorno a foldX, non al centro della pagina!
        float localX = pos.x - foldX;

        float rotatedX = cos(theta) * localX;
        float liftedZ = sin(theta) * localX;

        pos.x = rotatedX + foldX;
        pos.z += liftedZ;
    }

    gl_Position = proj * view * model * vec4(pos, 1.0);
    TexCoord = aTexCoord;
}



#version 330 core

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;

uniform sampler2D texture_diffuse1;

// luce direzionale fissa
uniform vec3 lightDir = normalize(vec3(-0.5, -1.0, -0.3)); // direzione della luce
uniform vec3 lightColor = vec3(1.0);  // bianca
uniform vec3 ambientColor = vec3(0.2); // luce ambientale base

void main()
{
    // normalizzazione della normale interpolata
    vec3 norm = normalize(Normal);

    // calcolo luce diffusa
    float diff = max(dot(norm, -lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // colore texture
    vec3 texColor = texture(texture_diffuse1, TexCoords).rgb;

    // colore finale con luce ambientale + diffusa (LAMBERT)
    vec3 finalColor = (ambientColor + diffuse) * texColor;

    FragColor = vec4(finalColor, 1.0);
}

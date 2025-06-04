#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor; // ignorato
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out vec2 TexCoords;
out vec3 Normal;
out vec3 FragPos;

void main()
{
    TexCoords = aTexCoords;

    vec4 worldPos = model * vec4(aPos, 1.0);
    FragPos = worldPos.xyz;

    // Trasforma le normali correttamente (senza scala non serve inv transpose)
    Normal = mat3(model) * aNormal;

    gl_Position = proj * view * worldPos;
}

#version 330 core

in vec2 TexCoord;        // da vertex shader
in vec3 normal;        // Normale interpolata dal vertex shader
in vec3 fragPos;       // Posizione del frammento nel mondo

out vec4 FragColor;

uniform sampler2D texture_diffuse1;

// Uniforms for lighting
uniform vec3 lightColor;      // Colore della luce
uniform vec3 lightPosition;  // Posizione della luce
uniform vec3 viewPosition;   // Posizione della telecamera
uniform vec3 ambientLight;   // Luce ambientale

void main() 
{
	vec3 textureColor = texture(texture_diffuse1, TexCoord).rgb; // Colore della texture

	//LAMBERT
	vec3 normalNorm = normalize(normal);
	vec3 lightDir = normalize(lightPosition - fragPos); // Direzione della luce
	float diff = max(dot(normalNorm, lightDir), 0.0); // Illuminazione diffusa
	vec3 diffuse = diff * lightColor; // Colore diffuso

	// PHONG
	vec3 viewDir = normalize(viewPosition - fragPos); // Direzione della vista
	vec3 reflectDir = reflect(-lightDir, normalNorm); // Direzione di riflessione
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32); // Illuminazione speculare
	vec3 specular = spec * lightColor; // Colore speculare

	// Combinazione dei contributi di luce
	vec3 ambient = ambientLight; // Luce ambientale
	vec3 finalColor = (ambient + diffuse + specular) * textureColor; // (ambient + diffuse + specular) * ObjectColor

	FragColor = vec4(finalColor, 1);

	// Per visualizzare solo la texture senza illuminazione
    //FragColor = texture(texture_diffuse1, TexCoord);
}

#version 330 core
out vec4 FragColor;

//in vec4 vertexColor; //è esattamente la variabile di uscita del vertex shader
in vec2 coordTex; 
in vec3 normal; // Normale interpolata dal vertex shader
in vec3 fragPos;

uniform sampler2D texture_diffuse1; //non viene modificata dallo shader
uniform sampler2D texture_normal1; //non viene modificata dallo shader
uniform sampler2D texture_specular1; //non viene modificata dallo shader

uniform vec3 lightColor; // Colore della luce
uniform vec3 lightPosition; // Posizione della luce
uniform vec3 viewPosition; // Posizione della telecamera
uniform vec3 ambientLight; // Luce ambientale


void main()
{
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
	vec3 finalColor = (ambient + diffuse + specular) * vec3(1, 0 ,0); // (ambient + diffuse + specular) * ObjectColor

	FragColor = vec4(finalColor, 1);
}
#version 330 core
out vec4 FragColor;

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
	vec3 textureColor = texture(texture_diffuse1, coordTex).rgb; // Colore della texture


	//LAMBERT

	vec3 normalNorm = normalize(normal);
	vec3 lightDir = normalize(lightPosition - fragPos); // Direzione della luce
	float diff = max(dot(normalNorm, lightDir), 0.0); // Illuminazione diffusa
	vec3 diffuse = diff * lightColor * textureColor; // Colore diffuso


	// PHONG

	vec3 viewDir = normalize(viewPosition - fragPos); // Direzione della vista
	vec3 reflectDir = reflect(-lightDir, normalNorm); // Direzione di riflessione
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32); // Illuminazione speculare
	vec3 specular = vec3(0.0, 0.0, 0.0);

	if(diff > 0.0) // Solo se la superficie è illuminata
	{
		float specStrength = 0.5;
		specular = spec * specStrength * lightColor; // Colore speculare
	}


	// Combinazione dei contributi di luce
	vec3 ambient = ambientLight * textureColor; // Luce ambientale
	vec3 finalColor = (ambient + diffuse + specular); // (ambient + diffuse + specular) * ObjectColor

	FragColor = vec4(finalColor, 1);

	//// Debug delle direzioni
	//vec3 debugColor = vec3(0.0);
	//if(dot(viewDir, reflectDir) > 0.8) debugColor = vec3(1.0, 0.0, 0.0); // Rosso per specular alto
	//if(dot(normalNorm, lightDir) > 0.8) debugColor += vec3(0.0, 1.0, 0.0); // Verde per diffuse alto
	//FragColor = vec4(mix(finalColor, debugColor, 0.3), 1.0);
}
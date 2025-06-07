#version 330 core
out vec4 FragColor;

in vec2 coordTex; 
//in vec3 normal; // Normale interpolata dal vertex shader
in vec3 fragPos;
in mat3 TBN; // Matrice Tangente-Bitangent-Normale

uniform sampler2D texture_diffuse1; //non viene modificata dallo shader
uniform sampler2D texture_normal1; //non viene modificata dallo shader
uniform sampler2D texture_specular1; //non viene modificata dallo shader

uniform vec3 lightColor; // Colore della luce
uniform vec3 lightPosition; // Posizione della luce
uniform vec3 viewPosition; // Posizione della telecamera
uniform vec3 ambientLight; // Luce ambientale


void main()
{
	vec3 normal = texture(texture_normal1, coordTex).rgb; // Colore della mappa normale
	normal = normalize(normal * 2.0 - 1.0);  // da [0,1] a [-1,1]
    normal = normalize(TBN * normal);

	vec3 diffuseColor = texture(texture_diffuse1, coordTex).rgb;


	//LAMBERT
	vec3 normalNorm = normalize(normal);
	vec3 lightDir = normalize(lightPosition - fragPos); // Direzione della luce
	float diff = max(dot(normalNorm, lightDir), 0.0); // Illuminazione diffusa
	vec3 diffuse = diff * lightColor * diffuseColor; // Colore diffuso

	// PHONG
	vec3 viewDir = normalize(viewPosition - fragPos); // Direzione della vista
	vec3 reflectDir = reflect(-lightDir, normalNorm); // Direzione di riflessione
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32); // Illuminazione speculare
	float specStrength = texture(texture_specular1, coordTex).r * 2;
	vec3 specular = spec * specStrength * lightColor; // Colore speculare

	// Combinazione dei contributi di luce
	vec3 ambient = ambientLight * diffuseColor; // Luce ambientale
	vec3 finalColor = (ambient + diffuse + specular);

	FragColor = vec4(finalColor, 1);

	//FragColor = vec4(normal * 0.5 + 0.5, 1.0); // debug

}
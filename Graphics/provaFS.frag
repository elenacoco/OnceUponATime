#version 330 core
out vec4 FragColor;

in vec4 vertexColor; //è esattamente la variabile di uscita del vertex shader
in vec2 coordTex; 

uniform sampler2D texture_diffuse1; //non viene modificata dallo shader
uniform sampler2D texture_specular1; //non viene modificata dallo shader

void main()
{
	FragColor = texture(texture_diffuse1, coordTex);
	//FragColor = vec4(coordTex, 0.0, 1.0); // Visualizza le coordinate UV come colore
	//FragColor = texture(texture_diffuse1, vec2(0.5));
	//FragColor = vec4(1.0, 1.0, 0.0, 1.0);
}
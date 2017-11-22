#version 410
in vec2 texture_coordinates;

uniform sampler2D diffuse;

out vec4 frag_Colour;


void main () {
	frag_Colour = texture(diffuse, texture_coordinates);
	//frag_Colour = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}
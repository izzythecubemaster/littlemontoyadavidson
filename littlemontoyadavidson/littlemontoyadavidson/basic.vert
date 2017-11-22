#version 410
in layout(location = 0) vec3 vertex_position;
in layout(location = 1) vec3 colors;
in layout(location = 2) vec3 offset;

out vec3 colour;
uniform mat4 MVP;

void main () {
	gl_Position = MVP * vec4(vertex_position, 1.0f);
	colour = colors;
}
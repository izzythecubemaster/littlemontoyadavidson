#version 410
in layout(location = 0) vec3 vertex_position;
in layout(location = 1) vec2 vt;

uniform mat4 MVP;

out vec2 texture_coordinates;

void main () {
	texture_coordinates = vt;
	gl_Position = MVP * vec4(vertex_position, 1.0f);
}
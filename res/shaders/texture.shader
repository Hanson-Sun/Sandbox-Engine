#shader vertex
#version 330 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec2 textureCoord;

out vec2 v_textureCoord;

uniform mat4 u_mvp;

void main() {
    gl_Position = u_mvp * position;
    v_textureCoord = textureCoord;
};

#shader fragment
#version 330 core
layout(location = 0) out vec4 color;

in vec2 v_textureCoord;
uniform sampler2D u_texture;    

void main() {
    vec4 texColor = texture(u_texture, v_textureCoord);
    color = texColor;
};
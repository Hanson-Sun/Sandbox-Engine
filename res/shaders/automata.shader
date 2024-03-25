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
uniform vec2 u_textureSize;  // Add this uniform for the texture size

void main() {
    // Calculate the nearest pixel's texture coordinates
    vec2 pixelCoord = floor(v_textureCoord * u_textureSize);
    vec2 nearestTexCoord = (pixelCoord  / u_textureSize);

    // Sample the texture at the nearest pixel
    vec4 texColor = texture(u_texture, nearestTexCoord);

    color = texColor;
}
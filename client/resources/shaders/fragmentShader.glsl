#version 330 core

in vec2 TextureCoord;
out vec4 color;

uniform sampler2D tex;

void main()
{
    color = texture(tex, TextureCoord);
}
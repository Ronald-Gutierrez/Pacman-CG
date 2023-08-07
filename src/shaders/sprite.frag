#version 330 core
in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D image;
//uniform vec3 spriteColor;

//color = vec4(spriteColor, 1.0) * texture(image, TexCoord);
void main()
{
    FragColor = texture(image, TexCoord);
}
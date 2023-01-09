#version 440 core

in vec2 Tex;
in vec4 Col;

uniform sampler2D texture;

void main() {
    gl_FragColor = vec4(Tex.xy,Col.ba);
}
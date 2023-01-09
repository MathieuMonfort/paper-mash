#version 440 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTex;

out vec2 Tex;
out vec4 Col;

void main() {
    Tex = aTex;
    Col = vec4(1.0,1.0,1.0,1.0);
    gl_Position = vec4(aPos, 0.0,1.0);
}

#version 440 core

attribute highp vec4 posAttr;
void main() {
   gl_Position = posAttr;
}

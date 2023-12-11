#shader vertex
#version 460 core

layout(location = 0) in vec4 position;

void main()
{
    gl_Position = position;
};

#shader fragment

#version 460 core

layout(location = 0) out vec4 color;

//uniform vec4 u_Color = vec4(0.2,0.8,0.6,1.0);
//uniform vec2 resolution = vec2(0.7,0.8);
//uniform vec2 resolution = vec2(1,1);
//uniform vec2 resolution = vec2(1920,1080);
uniform vec2 resolution = vec2(1000,800);
vec3 thisColor = vec3(0.0);

void main()
{
    //color = u_Color;
    vec2 coordColor = (gl_FragCoord.xy - 0.5 * resolution.xy) / resolution.y;
    //vec2 coord_col = gl_FragCoord.xy - 0.5 * resolution.xy;
    //vec3 col = vec3(0.5 + 0.5 * sin(uv.x), 0.5 + 0.5 * cos(uv.y), 0.0);

    thisColor.xy += coordColor;

    color = vec4(thisColor, 1.0);
};
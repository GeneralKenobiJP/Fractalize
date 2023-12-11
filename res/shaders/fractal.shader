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
vec2 shift = vec2(-0.75,0.0);
float scale = 2.25;

//uniform vec4 u_Color = vec4(0.2,0.8,0.6,1.0);
//uniform vec2 resolution = vec2(0.7,0.8);
//uniform vec2 resolution = vec2(1,1);
//uniform vec2 resolution = vec2(1920,1080);
uniform vec2 resolution = vec2(1000,800);

const int MAX_ITER = 5000;

void main()
{
    vec2 coord = (gl_FragCoord.xy - 0.5 * resolution.xy) / resolution.y;
    coord *= scale;

    float x = coord.x + shift.x;
    float y = coord.y + shift.y;

    float a = x;
    float b = y;

    int iter;
    for (iter = 0; iter < MAX_ITER; ++iter)
    {
        float magnitudeSquared = a * a + b * b;
        if (magnitudeSquared > 4.0)
           break;

        float aTemp = a;
        a = a * a - b * b + x;
        b = 2.0 * aTemp * b + y;
    }

    vec3 iter_color = vec3(float(iter) / float(MAX_ITER));
    color = vec4(iter_color, 1.0);
};
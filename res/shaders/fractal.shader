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
//vec2 shift = vec2(0.0,0.0);
float scale = 2.25;
//float scale = 2.0;

uniform vec2 resolution = vec2(1000,800);

//uniform vec2 juliaNumber = vec2(-0.70176, -0.3842);
uniform vec2 juliaNumber = vec2(-0.8, 0.156);

const int MAX_ITER = 5000;

vec3 mandelbrot(vec2 coord)
{
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

    return vec3(float(iter) / float(MAX_ITER));
}

vec3 julia(vec2 coord)
{
    coord *= scale;

    float a = coord.x + shift.x;
    float b = coord.y + shift.y;

    int iter;
    for (iter = 0; iter < MAX_ITER; ++iter)
    {
        float magnitudeSquared = a * a + b * b;
        if (magnitudeSquared > 4.0)
           break;

        float aTemp = a;
        //a = a + 2;
        //b = b + 1;
        a = a * a - b * b + juliaNumber.x;
        b = 2.0 * aTemp * b + juliaNumber.y;
    }

    return vec3(float(iter) / float(MAX_ITER));
}

void main()
{
    vec2 coord = (gl_FragCoord.xy - 0.5 * resolution.xy) / resolution.y;

    vec3 iter_color = mandelbrot(coord);
    //vec3 iter_color = julia(coord);
    color = vec4(iter_color, 1.0);
};
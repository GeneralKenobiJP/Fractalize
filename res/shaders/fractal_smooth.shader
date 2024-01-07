//temporarily bullshit

#shader vertex
#version 460 core

layout(location = 0) in vec4 position;

void main()
{
    gl_Position = position;
};

#shader fragment

#version 460 core

#define M_PI 3.1415926535897932384626433832795
#define M_E 2.7182818284590452353602874713527

const int MAX_ITER = 8000;

uniform float scale_input;
uniform vec2 shift_input;
uniform vec2 resolution;

layout(location = 0) out vec4 color;

vec2 shift = vec2(-0.75+shift_input.x,0.0+shift_input.y);
float scale = 2.25 / scale_input;

uniform vec2 juliaNumber = vec2(-0.8, 0.156);

float mandelbrot(vec2 coord)
{
    coord *= scale;

    float x = coord.x + shift.x;
    float y = coord.y + shift.y;

    float a = x;
    float b = y;

    int iter;
    for (iter = MAX_ITER-1; iter > 0; --iter)
    {
        float magnitudeSquared = a * a + b * b;
        if (magnitudeSquared > 4.0)
           break;

        float aTemp = a;
        a = a * a - b * b + x;
        b = 2.0 * aTemp * b + y;
    }
    //if(iter == 0)
      //  iter = MAX_ITER + 50;

    return iter + 1 - log(log2(a*a+b*b));
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
        a = a * a - b * b + juliaNumber.x;
        b = 2.0 * aTemp * b + juliaNumber.y;
    }

    return vec3(float(iter) / float(MAX_ITER));
}

void main()
{

    vec2 coord = (gl_FragCoord.xy - 0.5 * resolution.xy) / resolution.y;

    float iter = mandelbrot(coord)/MAX_ITER;
    //vec3 iter_color = julia(coord);

    vec3 iter_color;

    iter_color.x = iter;
    iter_color.y = pow(iter,2);
    iter_color.z = pow(iter,3);//0.5+0.5*sin(iter);

    color = vec4(iter_color, 1.0);
};
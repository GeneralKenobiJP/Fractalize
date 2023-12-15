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

const int MAX_ITER = 5000;

uniform float scale_input;
uniform vec2 shift_input;
uniform vec2 resolution;
uniform vec4 colorScheme[MAX_ITER];

layout(location = 0) out vec4 color;
vec2 shift = vec2(-0.75+shift_input.x,0.0+shift_input.y);
float scale = 2.25 / scale_input;

//uniform vec2 resolution = vec2(1000,800);

//uniform vec2 juliaNumber = vec2(-0.70176, -0.3842);
uniform vec2 juliaNumber = vec2(-0.8, 0.156);

int mandelbrot(vec2 coord)
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

    return iter;
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

const int test_int = 0;

void main()
{

    vec2 coord = (gl_FragCoord.xy - 0.5 * resolution.xy) / resolution.y;

    int iter = mandelbrot(coord);
    //vec3 iter_color = julia(coord);

    //iter_color.x = 0.5*sin(M_PI*(10*iter_color.x-0.5))+0.5;
    //iter_color.y = 0.5*sin(M_PI*(10*iter_color.y-0.5))+0.5;
    //iter_color.z = tan(0.25*M_PI*iter_color.z);

    //color = vec4(iter_color, 1.0);
    vec4 thisVec = colorScheme[test_int];

    //colorScheme[test_int] = vec4(1.0,0.0,0.7,1.0);
    color = vec4(1.0,1.0,0.2,1.0);
   // color = colorScheme[0];
};
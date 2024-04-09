#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_COUNT 10

/* solve f(x) = x^3 + 4x^2 - 10 */

float g1(float x)
{
    return x - powf(x, 3) - 4*powf(x, 2) + 10;
}

float g2(float x)
{
    return sqrtf(10/x - 4*x);
}

float g3(float x)
{
    return sqrtf(10 - powf(x, 3))/2;
}

float g4(float x)
{
    return sqrtf(10 / (4 + x));
}

float g5(float x)
{
    return x - (powf(x, 3) + 4*powf(x, 2) - 10)/(3*powf(x, 2) + 8*x);
}
int main()
{
    float tol = 1e-4;
    float p_pre = 1.5;
    float p_cur = 1e5;
    float diff = fabsf(p_pre - p_cur);
    
    printf("initial: %f\n", p_pre);
    for(int i=0; i < MAX_COUNT; i++)
    {
        if(diff < tol || isnan(p_cur))
            break;

        p_cur = g2(p_pre);
        diff = fabsf(p_pre - p_cur);
        printf("%d iteration:\n", i+1);
        printf("    p_pre: %f\n", p_pre);
        printf("    p_cur: %f\n", p_cur);
        p_pre = p_cur;
    }

    return 0;
}
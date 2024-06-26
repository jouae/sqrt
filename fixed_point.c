#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_COUNT 30

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

void print_errors(float *e, size_t num)
{
    printf("relative errors:\n\n");
    for(int i=0; i < num; i++)
    {
        printf("%2d-iter: %e\n",i+1 , e[i]);
    }
}

float compute_order(float *e, size_t num)
{
    return logf(fabsf(e[num-1]/e[num-2])) / logf(fabsf(e[num-2]/e[num-3]));
}

/** 
 * print_aec - print the asymptotic error constant
 * @e: 1D array, stored errors
 * @num: size of e
 *
 * This method is for linearly convergence e.g.
 * fixed-point method.
 */
void print_aec(float *e, size_t num)
{
    for(int j=0; j < num-1; j++)
    {
        printf("aec: %f\n", e[j+1]/e[j]);
    }
}

int main()
{
    float tol = 1e-4;
    float p_pre = 1.5;
    float p_cur = 1e5;
    float exact = 1.365230013;
    float diff = fabsf(p_pre - p_cur);
    /* relative errors */
    float e[MAX_COUNT];
    int i = 0;
    
    printf("p0: %f\n", p_pre);
    while(i < MAX_COUNT && diff > tol && !isnan(p_cur))
    {
        p_cur = g5(p_pre);
        diff = fabsf(p_pre - p_cur);
        printf("%d iteration:\n", i+1);
        printf("    p_cur: %f\n\n", p_cur);
        p_pre = p_cur;
        e[i] = fabsf(p_cur - exact) / exact;
        i++;
    }
    
    print_errors(e, i);
    print_aec(e, i);

    return 0;
}
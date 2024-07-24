/** 
 * ddsqrt - compute the integer square root
 *          with Digit-by-Digit method
 *          which is the method of Linux int_sqrt()
 * @x: integer of which to calculate the sqrt
 */
unsigned long DDsqrt(unsigned long x);

/**
 * lutsqrt - compute the integer square root 
 *           with Look Up Table method
 *           which is the method of Pyhton3 sqrt()
 * @x: integer of which to calculate the sqrt
 *
 * see
 * Python's integer square root algorithm by Mark Dickinson
 * https://github.com/mdickinson/snippets/tree/main/papers/isqrt
 */
unsigned long LUTsqrt(unsigned long x);
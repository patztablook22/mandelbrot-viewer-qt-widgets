#include "mandelbrot.h"

int mandelbrot(const complex<Scalar> &c, int threshold) {
    complex<Scalar> z(0, 0);
    int steps;
    for (steps = 0; steps < threshold; steps++) {
        z = z*z + c;
        if (abs(z) > 5)
            break;
    }
    return steps * 256 / threshold;
}

int mandelbrot(Scalar a, Scalar b, int threshold) {
    return mandelbrot(complex<Scalar>(a,b), threshold);
}

#include "mandelbrot.h"

int mandelbrot(complex<Scalar> &c) {
    complex<Scalar> z(0, 0);
    int steps;
    for (steps = 0; steps < 256; steps++) {
        z = z*z + c;
        if (abs(z) > 5)
            return steps;
    }
    return steps;
}

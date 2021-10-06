#ifndef MANDELBROT_H
#define MANDELBROT_H

#endif // MANDELBROT_H

#include <complex>
#include <cmath>

using std::complex;
using Scalar = double;


/*
 * receives c = a + bi
 * returns how early does it diverge normed to max = 0xff
 *
 */

int mandelbrot(const complex<Scalar> &c, int = 255);
int mandelbrot(Scalar, Scalar, int = 255);

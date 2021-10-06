#ifndef MANDELBROT_H
#define MANDELBROT_H

#endif // MANDELBROT_H

#include <complex>
#include <cmath>

using std::complex;
using Scalar = double;


/*
 * receives c = a + bi
 * returns how early does it diverge
 *
 */

int mandelbrot(complex<Scalar> &c);

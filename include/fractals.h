#ifndef FRACTALS_H
#define FRACTALS_H

#include "image.h"

/**
 * @brief Function to compute the Mandelbrot set.
 *
 * This function computes the Mandelbrot set for a given image and
 * location in the complex plane.
 *
 * @param dst Destination image for the Mandelbrot set.
 * @param x0 leftmost X-coordinate of the image.
 * @param y0 bottom Y-coordinate of the image.
 * @param dx Width of the image in the complex plane.
 */
void mandelbrot( Image *dst, float x0, float y0, float dx);

/**
 * @brief Function to compute the Julia set.
 *
 * This function computes the Julia set for a given image and
 * location in the complex plane.
 *
 * @param dst Destination image for the Julia set.
 * @param x0 leftmost X-coordinate of the image.
 * @param y0 bottom Y-coordinate of the image.
 * @param dx Width of the image in the complex plane.
 */
void julia(Image *dst, float x0, float y0, float dx);

/**
 * @brief Function to compute the Burning Ship fractal.
 *
 * This function computes the Burning Ship fractal for a given image and
 * location in the complex plane.
 *
 * @param dst Destination image for the Burning Ship fractal.
 * @param x0 leftmost X-coordinate of the image.
 * @param y0 bottom Y-coordinate of the image.
 * @param dx Width of the image in the complex plane.
 */
void burning_ship(Image *dst, float x0, float y0, float dx);

#endif
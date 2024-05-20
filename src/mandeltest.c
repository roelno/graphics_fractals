/*
	Bruce A. Maxwell
	Fall 2013

  Creates a Mandelbrot set at a selected location
*/
#include "image.h"
#include "fractals.h"

int main(int argc, char *argv[]) {
  Image *src;

	src = image_create(750, 1000);

	mandelbrot( src, -1.5, -1.5, 4);

  image_write( src, "mandelbrot-full.ppm");

	mandelbrot( src, 1.755, -0.02, 0.02);

  image_write( src, "mandelbrot.ppm");

	julia( src, -1.8, -1.8*0.75, 3.6);

  image_write( src, "julia.ppm");

  burning_ship(src, -1.8f, -0.08f, 0.1f); // Largest ship
  image_write(src, "burning_ship_largest.ppm");

  image_free( src );
  return(0);
}

#include "image.h"
#include "fractals.h"
#include <complex.h>
#include <math.h>


void mandelbrot(Image *dst, float x0, float y0, float dx) {
    int max_iter = 1000;
    float dy = dx * dst->rows / dst->cols;

    image_reset(dst);
    for (int i = 0; i < dst->rows; i++) {
        for (int j = 0; j < dst->cols; j++) {
            // mapping pixels to the complex plane
            float x = x0 + j * dx / dst->cols;
            float y = y0 + dy - i * dy / dst->rows;

            complex float c = x + I * y;
            complex float z = 0;

            int iter;
            for (iter = 0; iter < max_iter; iter++) {
                if (cabs(z) > 2.0) break;
                z = z * z - c;
            }
            float color = iter / (float)max_iter;
            image_setc(dst, i, j, 0, 0.4f * color);
            image_setc(dst, i, j, 1, 0.6f * color);
            image_setc(dst, i, j, 2, 0.8f * color);
        }
    }
}

void julia(Image *dst, float x0, float y0, float dx) {
    int max_iter = 1000;
    float dy = dx * dst->rows / dst->cols;
    complex float c = 0.7454054 + I * 0.1130063;
   
    image_reset(dst);
    for (int i = 0; i < dst->rows; i++) {
            for (int j = 0; j < dst->cols; j++) {
                float x = x0 + j * dx / dst->cols;
                float y = y0 + dy - i * dy / dst->rows;
                complex float z = x + I * y;
                int iter;
                for (iter = 0; iter < max_iter; iter++) {
                    if (cabs(z) > 2.0) break;
                    z = z * z - c;
                }
                float color = iter / (float)max_iter;
                image_setc(dst, i, j, 0, 0.4f * color);
                image_setc(dst, i, j, 1, 0.6f * color);
                image_setc(dst, i, j, 2, 0.8f * color);
            }
        }
}


void burning_ship(Image *dst, float x0, float y0, float dx) {
    int max_iter = 100;
    float dy = dx * dst->rows / dst->cols;

    image_reset(dst);

    for (int i = 0; i < dst->rows; i++) {
        for (int j = 0; j < dst->cols; j++) {
            float p0_x = 0;
            float p0_y = 0;
            float x = x0 + j * dx / dst->cols;
            float y = y0 + i * dy / dst->rows;
            int k;
            for (k = 0; k < max_iter; k++) {
                float p_x = p0_x * p0_x - p0_y * p0_y + x;
                float p_y = 2 * fabs(p0_x * p0_y) + y;
                p0_x = p_x;
                p0_y = p_y;
                if (p_x * p_x + p_y * p_y > 4) break;
            }
            float color = k / (float)max_iter;
            image_setc(dst, i, j, 0, 0.4f * color);
            image_setc(dst, i, j, 1, 0.6f * color);
            image_setc(dst, i, j, 2, 0.8f * color);
        }
    }
}

void mandelbrot_color(Image *dst, float x0, float y0, float dx) {
    int max_iter = 1000;
    float dy = dx * dst->rows / dst->cols;

    image_reset(dst);
    for (int i = 0; i < dst->rows; i++) {
        for (int j = 0; j < dst->cols; j++) {
            // mapping pixels to the complex plane
            float x = x0 + j * dx / dst->cols;
            float y = y0 + dy - i * dy / dst->rows;

            complex float c = x + I * y;
            complex float z = 0;

            int iter;
            for (iter = 0; iter < max_iter; iter++) {
                if (cabs(z) > 2.0) break;
                z = z * z - c;
            }
            float color = iter / (float)max_iter;
            image_setc(dst, i, j, 0, color);
            image_setc(dst, i, j, 1, 1.f - color);
            image_setc(dst, i, j, 2, 1.f - color);
        }
    }
}

void julia_color(Image *dst, float x0, float y0, float dx) {
    int max_iter = 1000;
    float dy = dx * dst->rows / dst->cols;
    complex float c = 0.7454054 + I * 0.1130063;
   
    image_reset(dst);
    for (int i = 0; i < dst->rows; i++) {
            for (int j = 0; j < dst->cols; j++) {
                float x = x0 + j * dx / dst->cols;
                float y = y0 + dy - i * dy / dst->rows;
                complex float z = x + I * y;
                int iter;
                for (iter = 0; iter < max_iter; iter++) {
                    if (cabs(z) > 2.0) break;
                    z = z * z - c;
                }
                float color = iter / (float)max_iter;
                image_setc(dst, i, j, 0, color);
                image_setc(dst, i, j, 1, color * color);
                image_setc(dst, i, j, 2, sqrt(color));
            }
        }
}


void burning_ship_color(Image *dst, float x0, float y0, float dx) {
    int max_iter = 100;
    float dy = dx * dst->rows / dst->cols;

    image_reset(dst);

    for (int i = 0; i < dst->rows; i++) {
        for (int j = 0; j < dst->cols; j++) {
            float p0_x = 0;
            float p0_y = 0;
            float x = x0 + j * dx / dst->cols;
            float y = y0 + i * dy / dst->rows;
            int k;
            for (k = 0; k < max_iter; k++) {
                float p_x = p0_x * p0_x - p0_y * p0_y + x;
                float p_y = 2 * fabs(p0_x * p0_y) + y;
                p0_x = p_x;
                p0_y = p_y;
                if (p_x * p_x + p_y * p_y > 4) break;
            }
            float color = k / (float)max_iter;
            image_setc(dst, i, j, 0, 0.8f * color);
            image_setc(dst, i, j, 1, 0.3f * color);
            image_setc(dst, i, j, 2, 0.1f * color);
        }
    }
}
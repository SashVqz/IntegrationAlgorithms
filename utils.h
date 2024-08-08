#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int readPoints(const char filename[], double **x, double **y);
void generateCurvePoints(const char *filename, int num_points);

#endif // UTILS_H

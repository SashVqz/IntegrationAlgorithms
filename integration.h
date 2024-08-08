#ifndef INTEGRATION_H
#define INTEGRATION_H

#include "utils.h"
 
#define PI 3.14159265358979323846
#define E exp(1.0)

double calculateRectangleArea(const char filename[]);
double calculateTrapezoidArea(const char filename[]);
double calculateSimpsonArea(const char filename[]);
double calculateRombergArea(const char filename[]);
double calculateMonteCarloArea(const char filename[], int num_samples);

#endif // INTEGRATION_H

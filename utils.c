#include "utils.h"

/**
 * Reads points from a file.
 */
int readPoints(const char filename[], double **x, double **y) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror("Error opening the file");
        return -1;
    }

    int max_points = 100;
    *x = (double *)malloc(max_points * sizeof(double));
    *y = (double *)malloc(max_points * sizeof(double));
    if (*x == NULL || *y == NULL) {
        perror("Error allocating memory");
        fclose(f);
        return -1;
    }

    int num_points = 0;
    while (fscanf(f, "%lf %lf", &(*x)[num_points], &(*y)[num_points]) != EOF) {
        num_points++;
        if (num_points >= max_points) {
            max_points *= 2;
            *x = (double *)realloc(*x, max_points * sizeof(double));
            *y = (double *)realloc(*y, max_points * sizeof(double));
            if (*x == NULL || *y == NULL) {
                perror("Error reallocating memory");
                fclose(f);
                return -1;
            }
        }
    }

    fclose(f);
    return num_points;
}

/**
 * Generates a file with quadratic curve points with semi-random variations.
 */
void generateCurvePoints(const char *filename, int num_points) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        perror("Error opening the file for writing");
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < num_points; i++) {
        double x = i / 100.0;
        double y = (x * x) + ((rand() % 100) / 1000.0); 

        fprintf(f, "%lf\t%lf\n", x, y);
    }

    fclose(f);
}


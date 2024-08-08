#include "integration.h"

/**
 * @Description, calculate the area under the curve defined by the points in the file using the rectangle rule.
 * @linkhttps://en.wikipedia.org/wiki/Rectangle_method
 */
double calculateRectangleArea(const char filename[]) {
    double *x, *y;
    int num_points = readPoints(filename, &x, &y);
    if (num_points == -1) exit(1);
    
    double area = 0.0;
    for (int i = 0; i < num_points - 1; i++) {
        double base = x[i + 1] - x[i];
        double h = y[i];
        area += base * h;
    }

    free(x);
    free(y);

    return area;
}

/**
 * @Description, calculate the area under the curve defined by the points in the file using the trapezoidal rule.
 * @linkhttps://en.wikipedia.org/wiki/Trapezoidal_rule
 */

double calculateTrapezoidArea(const char filename[]) {
    double *x, *y;
    int num_points = readPoints(filename, &x, &y);
    if (num_points == -1) exit(1);
    
    double area = 0.0;
    for (int i = 0; i < num_points - 1; i++) {
        double base = x[i + 1] - x[i];
        double h1 = y[i];
        double h2 = y[i + 1];
        area += (base / 2) * (h1 + h2);
    }

    free(x);
    free(y);

    return area;
}

/**
 * @Description, calculate the area under the curve defined by the points in the file using Simpson's rule.
 * @linkhttps://en.wikipedia.org/wiki/Simpson%27s_rule 
 */
double calculateSimpsonArea(const char filename[]) {
    double *x, *y;
    int num_points = readPoints(filename, &x, &y);
    if (num_points == -1) exit(1);
    if (num_points % 2 == 0) num_points--;

    double area = 0.0;
    for (int i = 0; i < num_points - 2; i += 2) {
        double h = x[i + 2] - x[i];
        area += (h / 6.0) * (y[i] + 4.0 * y[i + 1] + y[i + 2]);
    }

    free(x);
    free(y);

    return area;
}

/**
 * @Description, calculate the area under the curve defined by the points in the file using Monte Carlo integration.
 * @linkhttps://en.wikipedia.org/wiki/Monte_Carlo_integration
 */

double calculateMonteCarloArea(const char filename[], int num_samples) {
    double *x, *y;
    int num_points = readPoints(filename, &x, &y);
    if (num_points == -1) exit(1);

    double x_min = x[0], x_max = x[num_points - 1];
    double y_min = y[0], y_max = y[0];
    for (int i = 1; i < num_points; i++) {
        if (y[i] < y_min) y_min = y[i];
        if (y[i] > y_max) y_max = y[i];
    }

    int count = 0;
    srand(time(NULL));
    for (int i = 0; i < num_samples; i++) {
        double x_rand = x_min + (x_max - x_min) * ((double)rand() / RAND_MAX);
        double y_rand = y_min + (y_max - y_min) * ((double)rand() / RAND_MAX);

        for (int j = 0; j < num_points - 1; j++) {
            if (x_rand >= x[j] && x_rand < x[j + 1]) {
                double y_interp = y[j] + (y[j + 1] - y[j]) * (x_rand - x[j]) / (x[j + 1] - x[j]);
                if (y_rand <= y_interp) count++;
                break; 
            }
        }
    }

    double area = (double)count / num_samples * (x_max - x_min) * (y_max - y_min);

    free(x);
    free(y);

    return area;
}

/**
 * @Description, calculate the area under the curve defined by the points in the file using Romberg integration.
 * @linkhttps://en.wikipedia.org/wiki/Romberg%27s_method
 */
double calculateRombergArea(const char filename[]) {
    double *x, *y;
    int num_points = readPoints(filename, &x, &y);
    if (num_points == -1) exit(1);

    double **R = (double **)malloc((num_points / 2 + 1) * sizeof(double *));
    for (int i = 0; i <= num_points / 2; i++) R[i] = (double *)malloc((num_points / 2 + 1) * sizeof(double));
    
    for (int k = 0; k <= num_points / 2; k++) {
        int N = (int)pow(2, k); 
        double h = (x[num_points - 1] - x[0]) / N;
        double sum = 0.0;

        for (int i = 1; i < N; i++) sum += y[i * (num_points - 1) / N];
        
        R[k][0] = (h / 2) * (y[0] + 2 * sum + y[num_points - 1]);
    }

    for (int j = 1; j <= num_points / 2; j++) {
        for (int k = j; k <= num_points / 2; k++) {
            R[k][j] = (pow(4, j) * R[k][j - 1] - R[k - 1][j - 1]) / (pow(4, j) - 1);
        }
    }

    double area = R[num_points / 2][num_points / 2];

    for (int i = 0; i <= num_points / 2; i++) free(R[i]);
    free(R);
    free(x);
    free(y);

    return area;
}
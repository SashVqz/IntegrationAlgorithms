#include "integration.h"

int main() {
    char f1[] = "./data/c1.txt";
    char f2[] = "./data/c2.txt";

    FILE *fout = fopen("history.txt", "w");
    if (fout == NULL) {
        perror("Error opening the output file");
        return 1;
    }
    
    // generateCurvePoints(f1, 30);
    // generateCurvePoints(f2, 30);

    double exact_value = -1.0 + (2.0 * E / PI); // exact value of the area between the curves, example!!!

    // Rectangle method
    double areaRectangles = fabs(calculateRectangleArea(f1) - calculateRectangleArea(f2));
    double errorRectangles = fabs(exactValue - areaRectangles);

    // Trapezoid method
    double areaTrapezoids = fabs(calculateTrapezoidArea(f1) - calculateTrapezoidArea(f2));
    double errorTrapezoids = fabs(exactValue - areaTrapezoids);

    // Simpson method
    double areaSimpson = fabs(calculateSimpsonArea(f1) - calculateSimpsonArea(f2));
    double errorSimpson = fabs(exactValue - areaSimpson);

    // Monte Carlo method 
    int num_samples = 10000; // too exact  
    double areaMontecarlo = fabs(calculateMonteCarloArea(f1, num_samples) - calculateMonteCarloArea(f2, num_samples));
    double errorMontecarlo = fabs(exactValue - areaMontecarlo);

    // Romberg method
    double areaRomberg = fabs(calculateRombergArea(f1) - calculateRombergArea(f2));
    double errorRomberg = fabs(exactValue - areaRomberg);

    // Output
    fprintf(fout, "Results: \n");
    fprintf(fout, "Exact value of the area between the curves: %lf\n", exactValue);

    fprintf(fout, "\n---------------------------------------------\n\n");

    fprintf(fout, "Area between the curves (rectangles): %lf\n", areaRectangles);
    fprintf(fout, "Error (rectangles): %lf\n", errorRectangles);

    fprintf(fout, "\n---------------------------------------------\n\n");

    fprintf(fout, "Area between the curves (trapezoids): %lf\n", areaTrapezoids);
    fprintf(fout, "Error (trapezoids): %lf\n", errorTrapezoids);

    fprintf(fout, "\n---------------------------------------------\n\n");

    fprintf(fout, "Area between the curves (Simpson): %lf\n", areaSimpson);
    fprintf(fout, "Error (Simpson): %lf\n", errorSimpson);

    fprintf(fout, "\n---------------------------------------------\n\n");

    fprintf(fout, "Area between the curves (Monte Carlo): %lf\n", areaMontecarlo);
    fprintf(fout, "Error (Monte Carlo): %lf\n", errorMontecarlo);

    fprintf(fout, "\n---------------------------------------------\n\n");

    fprintf(fout, "Area between the curves (Romberg): %lf\n", areaRomberg);
    fprintf(fout, "Error (Romberg): %lf\n", errorRomberg);

    fclose(fout);

    return 0;
}

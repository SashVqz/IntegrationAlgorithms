This repository contains the implementation of various numerical integration methods in C, designed to calculate the area between two curves. The project includes the comparison of different integration methods.

## Integration methods:
 - Rectangles: Calculates the approximate area by dividing the region under the curve into rectangles.
 - Trapezoids: Approximates the area using trapezoids under the curve.
 - Simpson's: Uses quadratic polynomials for a more accurate approximation.
 - Monte Carlo: A stochastic method that uses random sampling to approximate the area.
 - Romberg: Uses Richardson extrapolation to improve the accuracy of the trapezoidal integration

## Project Structure

- **main.c**: Contains the main program that executes the different integration methods and calculates the area between two curves.
- **integration.h/.c**: Define and implement the numerical integration functions.
- **utils.h/.c**: Include auxiliary functions, such as reading points from files and generating curves.
- **data/**: Contains the data files (`c1.txt`, `c2.txt`) with the points that define the curves.

To compile the program, you can use the included `Makefile`. Simply run

### Compilation
```sh
make
```

### Execution
```sh
./programa
```

### Cleanup
```sh
make clean
```




//ko, ivan
//Feb 06th, 2017
//input: x, c5, c4, c3, c2, c1, c0
//output: x, y
//purpose: Using the Newton-Raphson Algorithm to find out a root of a polynomial. The x value is entered by user to
//start the calculation and will be updated later. The algorithm depends on y and yNu value to reach the answer.
//The pogram will also stop if it runs higher than the countLimit.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	double x, y = 1, yNu = 0, c5 = 0, c4 = 0, c3 = 0, c2 = 0, c1 = 0, c0 = 0;
	int count = 0, countLimit = 500;

	printf("This program is to find one root of 5th-order polynomial using Newton-Rhapson method.\n");
	printf("c5x ^ 5 + c4x ^ 4 + c3x ^ 3 + c2x ^ 2 + c1x + c0\n");

	printf("Enter polynomial coefficients : c5 c4 c3 c2 c1 c0 in this order : ");
	scanf("%lf %lf %lf %lf %lf %lf", &c5, &c4, &c3, &c2, &c1, &c0);
	
	printf("Your polynomial is "); 

	///I know this part is stupid, but I don't know how else to comply to the spec in a clean way.
	///Print out different formula depending out the user input.
	if (fabs(c5 - 0) >= 0.0001){
		printf("%.1lfx^5 + ", c5);
	}
	if (fabs(c4 - 0) >= 0.0001) {
		printf("%.1lfx^4 + ", c4);
	}
	if (fabs(c3 - 0) >= 0.0001) {
		printf("%.1lfx^3 + ", c3);
	}
	if (fabs(c2 - 0) >= 0.0001) {
		printf("%.1lfx^2 + ", c2);
	}
	if (fabs(c1 - 0) >= 0.0001) {
		printf("%.1lfx + ", c1);
	}
	if (fabs(c0 - 0) >= 0.0001) {
		printf("%.1lf", c0);
	}
	printf("\n");


	printf("Enter initial guess for x: ");
	scanf("%lf", &x);

	///Start the calculation for y.
	y = c5*pow(x, 5) + c4*pow(x, 4) + c3*pow(x, 3) + c2*pow(x, 2) + c1*x + c0;

	///Keep doing the loop as long as y is not close to 0.
	while (fabs(y) >= 0.000001) {
		///Update yNu and then find new value for x using y and yNu.
		yNu = 5 * c5*pow(x, 4) + 4 * c4*pow(x, 3) + 3 * c3*pow(x, 2) + 2 * c2*x + c1;

		///Fails the program if yNu is close to 0.
		if ((fabs(yNu) - 0) <= 0.000001) {
			printf("The algorithm failed; roots may be complex\n");
			return(0);
		}
		else {
			x = x - (y / yNu);
			count += 1;
		}
		///Stop the program if count is larger than the countLimit.
		if (count > countLimit) {
			printf("The algorithm failed; roots may be complex\n");
			return(0);
		}
		y = c5*pow(x, 5) + c4*pow(x, 4) + c3*pow(x, 3) + c2*pow(x, 2) + c1*x + c0;
	}
	
	printf("One of the roots of this polynomial is %lf\n", x);
	printf("It takes %d iterations to obtain this answer.\n", count);


	return(0);
}
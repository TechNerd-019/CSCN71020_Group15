#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* checkTriangle(int side1, int side2, int side3) {


	char* resultCheck = "";

	if (side1 < side2 + side3 && side2 < side1 + side3 && side3 < side1 + side2) {
		resultCheck = "Valid triangle.\n";
		double angle1, angle2, angle3, semiPerimeter, area, pi, R;


		pi = acos(-1);

		semiPerimeter = (side1 + side2 + side3) / 2;
		area = sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3)); //Using Heron's formula.

		R = ((double)side1 * (double)side2 * (double)side3) / (4 * area);

		//angle1 = (180 / pi) * asin(side1 / 2 * R); [Missed parenthesis breaks the calculation].
		angle1 = (180 / pi) * asin(side1 / (2 * R));
		angle2 = (180 / pi) * asin(side2 / (2 * R));
		angle3 = (180 / pi) * asin(side3 / (2 * R));

		printf("Angle 1: %.2f, Angle2: %.2f, Angle 3: %.2f\n", angle1, angle2, angle3);

	}
	else {
		printf("Not a triangle.\n");
	}


	return resultCheck;
}


char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		printf("\n");
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		printf("\n");
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		printf("\n");
		result = "Isosceles triangle";
	}
	else {
		printf("\n");
		result = "Scalene triangle";
	}

	return result;
}




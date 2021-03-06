#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>

void std_dev() {
	int n;
	double sum = 0;
	double avg;
	double std_dev = 0;
	double *sd_ptr = &std_dev;
	std::cout << "\nEnter the number of terms: ";
	std::cin >> n;
	
	std::cout << "\nNow enter the terms: ";
	double *arr = new double[n];
	for (int i = 0; i < n; i++) {
		std::cin >> *(arr + i);
		sum += *(arr + i);
	}

	avg = sum / n;
	std::cout << std::setprecision(2) << std::fixed << std::showpoint;		//Round to 2 decimal places
	std::cout << "\nThe average is: " << avg << "\n";

	for (int i = 0; i < n; i++) {
		*sd_ptr += pow((*(arr + i) - avg), 2);
	}
	*sd_ptr = *sd_ptr / (n*1.0);
	*sd_ptr = sqrt(*sd_ptr);

	std::cout << "The standard deviation is: " << std_dev << "\n";

	delete[] arr;
	arr = nullptr;
}

int main()
{
	while (true) {
		std_dev();
		char input;
		std::cout << "\nDo another one? (Y/N)";
		std::cin >> input;
		if (toupper(input) == 'N') {
			break;
		}
	}
	
    return 0;
}


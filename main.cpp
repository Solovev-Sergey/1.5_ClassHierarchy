#include "ClassHierarchy.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>


double frst_func(size_t num){
	if(num == 0) 
		return 0;

	return (double) 1 / (double) (num * num);
}

double scnd_func(size_t num) {
	if(num == 0) 
		return 0;

	return  (double) (1 - 2 * (int) (num % 2)) / (double) num;
}

double thrd_func(size_t num) {
	if (num == 0)
		return 0;

	return (double) 1 / (double) num;
}

double frth_coef(size_t num, double centre) {
	int fact = 1;

	for (size_t i = 1; i < num + 1; i++) {
		fact *= i;
	}

	return (double) exp(centre) / (double) fact;
}

double frth_func(size_t num, double point) {
	double power = 1;

	for(size_t i = 0; i < num; i++) {
		power *= point;
	}

	return power;
}

double ffth_coef(size_t num, double centre) {
	if (num == 0)
		return 1;

	return (double) 1 / (double) (centre * centre + num * num);
}

double ffth_func(size_t num, double point) {
	return sin(num * point);
}


int main() {
	
	NumericSeries frst(frst_func);

	NumericSeries scnd(scnd_func);

	NumericSeries trd(thrd_func);
	
	FunctionSeries frth(0, frth_coef, frth_func, 1);

	FunctionSeries ffth(0, ffth_coef, ffth_func, 2 * 3.14159265);

	std::vector<Series *> arr = {&frst, &scnd, &trd, &frth, &ffth};

	for (size_t i = 0; i < 5; i++) {
		arr[i]->name();
		arr[i]->print_first_n(10);
		std::cout << arr[i]->evaluate_first_n(10) << std::endl;
	}

	std::cout << std::endl << std::endl;

	std::sort(arr.begin(), arr.end());

	for (size_t i = 0; i < 5; i++) {
		arr[i]->name();
		arr[i]->print_first_n(10);
		std::cout << arr[i]->evaluate_first_n(10) << std::endl;
	}

	return 0;

}
#include "ClassHierarchy.h"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

NumericSeries::NumericSeries(double (*common_member)(size_t)) :
	common_member(common_member) {}

void NumericSeries::name () const {
	cout << "This is numeric series" << endl;
	return;
}

double NumericSeries::evaluate_first_n(size_t n) const {
	double result = 0;

	for (size_t i = 0; i < n; i++) {
		result += this->common_member(i);
	}

	return result;
}

void NumericSeries::print_first_n(size_t n) const {
	for(size_t i = 0; i < n; i++) {
		cout << this->common_member(i) << " + ";
	}

	cout << "..." << endl;
	return;
}



FunctionSeries::FunctionSeries (double centre,
	double (*common_coef)(size_t, double),
	double (*function)(size_t, double),
	double point) :
	centre(centre), common_coef(common_coef), function(function), point(point) {}

void FunctionSeries::name() const {
	cout << "This is functional series" <<endl;
	return;
}

double FunctionSeries::evaluate_first_n(size_t n) const {
	double result = 0;

	for(size_t i = 0; i < n; i++) {
		result += this->common_coef(i, this->centre) *
			this->function(i, this->point);
	}

	return result;
}

void FunctionSeries::print_first_n(size_t n) const {
	for(size_t i = 0; i < n; i++) {
		cout << this->common_coef(i, this->centre) << " * F(" << i << ", " <<
			this->point << ") + ";
	}

	cout << "..." << endl;
	return;
}

void FunctionSeries::change_centre(double new_centre) {
	this->centre = new_centre;
	return;
}

void FunctionSeries::change_point(double new_point) {
	this->point = new_point;
	return;
}



bool operator<(const Series &first,const Series &second) {
	return first.evaluate_first_n(1) < second.evaluate_first_n(1);
}

bool operator==(const Series &first, const Series &second) {
	return first.evaluate_first_n(1) == second.evaluate_first_n(1);
}

bool operator>(const Series &first, const Series &second) {
	return second < first;
}

bool operator<=(const Series &first, const Series &second) {
	return !(first > second);
}

bool operator>=(const Series &first, const Series &second) {
	return !(first < second);
}

bool operator!=(const Series &first, const Series &second) {
	return !(first == second);
}
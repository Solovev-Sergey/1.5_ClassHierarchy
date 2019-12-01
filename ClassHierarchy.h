#pragma once

#include <cstdlib>

class Series {
private:
public:
	Series() = default;
	virtual ~Series() = default;

	virtual void name() const = 0;
	virtual double evaluate_first_n(size_t n) const = 0;
	virtual void print_first_n(size_t n) const = 0; 


};


class NumericSeries : public Series {
private:
	double (*common_member)(size_t);
public:
	NumericSeries (double (*common_member)(size_t));
	~NumericSeries() override = default;

	void name() const override;
	double evaluate_first_n(size_t n) const override;
	void print_first_n(size_t n) const override;
};


class FunctionSeries : public Series {
private:
	double (*common_coef)(size_t, double);
	double (*function)(size_t, double);
	double centre;
	double point;
public:
	FunctionSeries (double centre,
		double (*common_coef)(size_t, double),
		double (*function)(size_t, double),
		double point);

	~FunctionSeries() override = default;

	void name() const override;
	double evaluate_first_n(size_t n) const override;
	void print_first_n(size_t n) const override;
	void change_centre(double new_centre);
	void change_point(double new_point);
};


bool operator<(const Series &first,const Series &second);
bool operator==(const Series &first, const Series &second);
bool operator>(const Series &first, const Series &second);
bool operator<=(const Series &first, const Series &second);
bool operator>=(const Series &first, const Series &second);
bool operator!=(const Series &first, const Series &second);
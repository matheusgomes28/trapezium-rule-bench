#ifndef EIGEN_TRAPEZIUM_H
#define EIGEN_TRAPEZIUM_H

#include <Eigen/Dense>
#include <Eigen/Core>


template <typename Func>
double estimate_area_eigen(Func f, double a, double b, std::size_t n)
{
	auto inputs = Eigen::VectorXd::LinSpaced(n + 1, a, b);
	auto samples = f(inputs);
	double h = (b - a) / n;

	
	double const sum = samples.segment(1, n - 1).sum();
	double const first = samples[0];
	double const last = samples[n];

	return (h / 2) * (samples[0] + samples[n] + 2 * samples.segment(1, n-1).sum());
}


#endif // EIGEN_TRAPEZIUM_H
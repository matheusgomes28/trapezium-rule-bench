#ifndef EIGEN_TRAPEZIUM_H
#define EIGEN_TRAPEZIUM_H

#include <Eigen/Dense>
#include <Eigen/Core>

namespace eigen_trapz
{
	template <typename Func>
	double estimate_area(Func f, double a, double b, std::size_t n)
	{
		auto const inputs = Eigen::VectorXd::LinSpaced(n + 1, a, b);
		auto const samples = f(Eigen::Ref<Eigen::ArrayXd const>{inputs});
		double const h = (b - a) / n;

		return (h / 2) * (samples[0] + samples[n] + 2 * samples.segment(1, n-1).sum());
	}
} // namespace eigen_traps



#endif // EIGEN_TRAPEZIUM_H
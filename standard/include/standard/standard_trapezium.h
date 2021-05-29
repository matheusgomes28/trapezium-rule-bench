#ifndef STANDARD_STANDARD_H
#define STANDARD_STANDARD_H

#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>

namespace std_trapz
{
	/// generates the inputs in the range [a, b],
	/// with n+1 samples equally spaced by ((b - a) / n)
	std::vector<double> create_inputs(double a, double b, std::size_t n);

	/// applies a function to an input vector
	template <typename Func>
	std::vector<double> apply(Func f, std::vector<double> const& inputs)
	{
		std::vector<double> samples;
		samples.reserve(inputs.size());

		std::transform(begin(inputs),
			end(inputs),
			std::back_inserter(samples),
			[&](auto input) {
				return f(input);
			});

		return samples;
	}

	template<typename Func>
	double estimate_area(Func f, double a, double b, std::size_t n)
	{
		auto const samples = apply(f, create_inputs(a, b, n));
		auto const h = (b - a) / n;

		return  (h / 2) * (samples.front() + samples.back() + 2 * std::accumulate(begin(samples) + 1, end(samples) - 1, 0.0));
	}
} // namespace std_trapz

#endif // STANDARD_STANDARD_H


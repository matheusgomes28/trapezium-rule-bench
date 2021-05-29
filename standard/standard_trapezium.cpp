#include <standard/standard_trapezium.h>

#include <algorithm>
#include <iterator>
#include <stddef.h>

namespace std_trapz
{
	std::vector<double> create_inputs(double a, double b, std::size_t n)
	{
		auto samples = std::vector<double>(n + 1);
		const double h = (b - a) / n;
		
		std::generate_n(std::back_inserter(samples), n + 1, [&] {
			a = a + h;
			return a - h;
		});
		
		return samples;
	}
}


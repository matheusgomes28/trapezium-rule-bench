#include <standard/standard_trapezium.h>

#include <algorithm>
#include <iterator>
#include <stddef.h>

namespace std_trapz
{
	std::vector<double> create_inputs(double a, double b, std::size_t n)
	{
		std::vector<double> samples;
		samples.reserve(n + 1);

		const double h = (b - a) / n;
		std::generate_n(std::back_inserter(samples), n + 1, [&] {
		    auto const temp = a;
			a = a + h;
			return temp;
		});
		
		return samples;
	}
}

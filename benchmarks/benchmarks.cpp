#include <standard/standard_trapezium.h>
#include <eigen_trapezium/eigen_trapezium.h>

#include <benchmark/benchmark.h>

#include <cmath>

template<int a, int b, std::size_t n>
static void BM_StandardImplementation(benchmark::State& state)
{
	// f(x) = e^(-x^2) implemented with the std
	// functions
	const auto f = [](auto const& x)
	{
		return std::exp(-x * x);
	};
	
	for (auto _ : state)
	{
		double area = std_trapz::estimate_area(f, a, b, n);
		benchmark::DoNotOptimize(area);
	}
}

template <int a, int b, std::size_t n>
static void BM_EigenImplementation(benchmark::State& state)
{
	// f(x) = e^(-x^2) implemented with Eigen3
	// functions
	const auto f = [](auto const& X) -> Eigen::VectorXd
	{
		return Eigen::exp(-X.array().square());
	};

	for (auto _ : state)
	{
		double area = eigen_trapz::estimate_area(f, a, b, n);
		benchmark::DoNotOptimize(area);
	}
}

auto bm_standard_traps10x10x100= BM_StandardImplementation<-10, 10, 100>;
BENCHMARK(bm_standard_traps10x10x100);

auto bm_eigen10x10x100 = BM_EigenImplementation<-10, 10, 100>;
BENCHMARK(bm_eigen10x10x100);

auto bm_standard_traps10x10x1000 = BM_StandardImplementation<-10, 10, 1000>;
BENCHMARK(bm_standard_traps10x10x1000);

auto bm_eigen10x10x1000 = BM_EigenImplementation<-10, 10, 1000>;
BENCHMARK(bm_eigen10x10x1000);

auto bm_standard_traps15x15x10000 = BM_StandardImplementation<-15, 15, 10000>;
BENCHMARK(bm_standard_traps15x15x10000);

auto bm_eigen15x15x10000 = BM_EigenImplementation<-15, 15, 10000>;
BENCHMARK(bm_eigen15x15x10000);

auto bm_standard_traps15x15x20000 = BM_StandardImplementation<-15, 15, 20000>;
BENCHMARK(bm_standard_traps15x15x20000);

auto bm_eigen15x15x20000 = BM_EigenImplementation<-15, 15, 20000>;
BENCHMARK(bm_eigen15x15x20000);

auto bm_standard_traps20x20x50000= BM_StandardImplementation<-20, 20, 50000>;
BENCHMARK(bm_standard_traps20x20x50000);

auto bm_eigen20x20x50000 = BM_EigenImplementation<-20, 20, 50000>;
BENCHMARK(bm_eigen20x20x50000);

BENCHMARK_MAIN();

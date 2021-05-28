#include <standard/standard_trapezium.h>
#include <eigen_trapezium/eigen_trapezium.h>

#include <benchmark/benchmark.h>

#include <cmath>



auto f(double x)
{
	return std::exp(-x * x);
};

auto f_eigen(Eigen::ArrayXd const& X) -> Eigen::VectorXd
{
	return Eigen::exp(-X.cwiseProduct(X));
}

template<int a, int b, std::size_t n>
static void BM_StandardImplementation(benchmark::State& state)
{
	for (auto _ : state)
	{
		double area = estimate_area(f, a, b, n);
		benchmark::DoNotOptimize(area);
	}
}

auto benchmark1 = BM_StandardImplementation<-10, 10, 100>;
BENCHMARK(benchmark1);

auto benchmark2 = BM_StandardImplementation<-10, 10, 1000>;
BENCHMARK(benchmark2);

auto benchmark3 = BM_StandardImplementation<-15, 15, 10000>;
BENCHMARK(benchmark3);

auto benchmark4 = BM_StandardImplementation<-15, 15, 20000>;
BENCHMARK(benchmark4);

auto benchmark5 = BM_StandardImplementation<-20, 20, 50000>;
BENCHMARK(benchmark5);

template <int a, int b, std::size_t n>
static void BM_EigenImplementation(benchmark::State& state)
{
	for (auto _ : state)
	{
		double area = estimate_area_eigen(f_eigen, a, b, n);
		benchmark::DoNotOptimize(area);
	}
}

auto bm_eigen10x10x100 = BM_EigenImplementation<-10, 10, 100>;
BENCHMARK(bm_eigen10x10x100);

auto bm_eigen10x10x1000 = BM_EigenImplementation<-10, 10, 1000>;
BENCHMARK(bm_eigen10x10x1000);

auto bm_eigen15x15x10000 = BM_EigenImplementation<-15, 15, 10000>;
BENCHMARK(bm_eigen15x15x10000);

auto bm_eigen15x15x20000 = BM_EigenImplementation<-15, 15, 20000>;
BENCHMARK(bm_eigen15x15x20000);

auto bm_eigen20x20x50000 = BM_EigenImplementation<-20, 20, 50000>;
BENCHMARK(bm_eigen20x20x50000);

BENCHMARK_MAIN();

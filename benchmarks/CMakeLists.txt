find_package(benchmark REQUIRED)

add_executable(benchmarks 
  benchmarks.cpp)

target_link_libraries(benchmarks
 PUBLIC
  benchmark::benchmark
  eigen_trapezium
  standard)

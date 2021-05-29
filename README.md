# C++ Trapezoid Rule Benchmarks

This project was created for my personal website with the aim to explore how to implement the trapezoidal rule with C++ and benchmark a few different implementations.

So far, the implementations included here are:

  - Standard library implementation: an implementation solely using the CPP standard library (stl) was provided, using vectors and functions in the header `algorithm`.

  - Numerical library implementation (Eigen3): Eigen3 is one of the most popular linear algebra libraries for C++, and it provides means of handling matrices and vectors. It's quite optimised for numerical programming.


## Tools And Dependencies

In order to build the project, you will need a [recent version of CMake](https://cmake.org/download/ "CMake Download") (anything >3.16). The code should compile in any modern C++ compiler; since C++14 features were used, make sure your compiler supports that (`gcc`, `clang`,and `msvc` should all support it).


There are a couple of library dependencies to this project, which are handled with `conan`. Conan is a package manager for C/C++, and it will pull all dependencies (libraries and headers) with a single command once it's installed, so install the latest version from the [Conan's website](https://conan.io/downloads.html "Conan download website").

The dependencies are:
  - Eigen3: The numerical library used for one of the trapezium rule implementations.
  - Google Benchmark: Used to create the benchmark executable.


## Building The Project

Assuming you installed the tools mentioned in the previous section, and assuming you have a working compiler installed, building the project is as easy as typing the following commands.

```bash
# where the build files will be created
mkdir build && cd build
# pull the dependencies and find scripts with
# conan
conan install --build=missing -sbuild_type=Release ..

# configure the project with the dir for
# conan find_package scripts
cmake -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_MODULE_PATH:FILEPATH="PATH-TO-REPO/build" \
      ..

# build the project
cmake --build .

# run the benchmarks
./benchmarks/benchmarks
```

Of course, replacing `PATH-TO-REPO` with the path in your computer where this repository is located (where the main `CMakeLists.txt` is).


## Project Organisation

The project is organised in three CMake targets:

  - `standard`: A static library containing the pure C++ `std` implementation. The files `standard_trapezium.{cpp, h}` defines the `estimate_area(...)` function that estimates area of a function using `std` libraries.
  - `eigen_trapezium`: A static library containing the `Eigen3` trapezoidal rule implementation. The files `eigen_trapezium.{cpp,h}` also defines a function `estimate_area(...)` that uses `Eigen3` to implement the trapezium rule.
  - `benchmarks`: An executable created from `benchmarks.cpp` that uses Google's benchmark library to benchmark the standard and eigen implementation with different inputs and sizes.

## Learn More About The Trapezoidal Rule

If you are struggling to understand the code here, check out
my the post I made on [understanding the trapezoidal rule](https://matgomes.com/understanding-trapezium-rule/ "Understanding the trapezoidal rule"). 
This particular repo was created to show people how to implement
the trapezoidal rule with modern C++.

## Benchmark Results

On a modest computer (fairly powerful Lenovo Legion Y740), the improvement between the standard C++ implementation and the Eigen3 one is noticeable. The table below shows benchmarks for the trapezium rule applied to the function <img src="https://render.githubusercontent.com/render/math?math=f(x)=e^{-x^{2}}">, with varying start and end points `{a, b}`, and the number of trapeziums `N`:

| Inputs {a, b, N} | std C++ | Eigen3  |
|------------------|---------|---------|
| {-10, 10, 100}   | 2.035μs | 1.154μs |
| {-10, 10, 1000}  | 14.49μs | 7.470μs |
| {-15, 15, 10000} | 175.3μs | 76.96μs |
| {-15, 15, 20000} | 346.6μs | 155.5μs |
| {-20, 20, 50000} | 1.366ms | 0.372ms |

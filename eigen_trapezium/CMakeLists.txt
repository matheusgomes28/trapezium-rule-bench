find_package(Eigen3 REQUIRED)

add_library(eigen_trapezium
  eigen_trapezium.cpp)

target_include_directories(eigen_trapezium
  PUBLIC
   include)

 target_link_libraries(eigen_trapezium
  PUBLIC
  Eigen3::Eigen)

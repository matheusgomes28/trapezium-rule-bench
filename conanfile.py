from conans import ConanFile

class TrapeziumBenchmarks(ConanFile):

	settings = ("os", "compiler", "build_type", "arch")
	generators = ("cmake_find_package")
	requires = ["benchmark/1.5.3", "eigen/3.3.9"]


	def imports(self):
		self.copy("*.dll", dst="bin", src="bin")
		self.copy("*.dylib", dst="bin", src="lib")

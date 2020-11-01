#include <iostream>
#include <vector>
#include "convolution.h"

int main() {
	std::vector<double> x;
	std::vector<double> w;
	std::vector<double> y;
	bool pack_with_zeros = true;

	std::string s;
	std::cin >> s;
	if(s == "false") {
	   pack_with_zeros = false;
	}
	std::cin >> s;
	x = readInVector(s);
	std::cin >> s;
	w = readInVector(s);

	std::cout << "x: {" << x[0];
	for(int i = 1; i < x.size(); i++) {
	   std::cout << ", " << x[i];
	}
	std::cout << "}" << std::endl;

	std::cout << "w: {" << w[0];
	for(int i = 1; i < w.size(); i++) {
	   std::cout << ", " << w[i];
	}
	std::cout << "}" << std::endl;

	y = applyConvolution(x,w,pack_with_zeros);
	std::cout << "{" << y[0];
	for(int i = 1; i < y.size(); i++) {
		std::cout << ", " << y[i];
	}
	std::cout << "}" << std::endl;

	return 0;
}
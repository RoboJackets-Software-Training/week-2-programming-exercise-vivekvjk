#include "convolution.h"

std::vector<double> readInVector(std::string s) {
	int prev_location = 0;
	int next_location = 0;
	std::vector<double> result;
	while(s.find(',', prev_location) != std::string::npos) {
		next_location = s.find(',', prev_location);
		result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
		next_location++;
		prev_location = next_location;
	}
	result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
	return result;
}

std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros) {
	std::vector<double> y;
	int packing_size = (w.size()-1)/2;
	for(int i = 0; i < x.size(); i++) {
		double accumulator = 0;
		for(int j = 0; j < w.size(); j++) {
			if(i - packing_size + j >= 0 && i - packing_size + j < x.size()) {
				accumulator += x[i - packing_size + j]*w[j];
			} else if(!pack_with_zeros && i - packing_size + j < 0) {
				// Handles the case where where we underflow indexes
				accumulator += x[0] * w[j];
			} else if(!pack_with_zeros && i - packing_size + j >= x.size()) {
				// Handles the case where we overflow indexes
				accumulator += x[x.size()-1] * w[j];
			}
		}
		y.push_back(accumulator);
	}
	return y;
}
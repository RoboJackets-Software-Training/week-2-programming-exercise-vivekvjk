#pragma once
#include <iostream>
#include <vector>


std::vector<double> readInVector(std::string s);
std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros);
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

std::size_t points(double const& c)
{
	constexpr double z_0 = 0.;

  std::vector<double> v_z {z_0};

	for (int i = 0; i != 1e3; ++i) {
		double result = std::pow(v_z.back(), 2) + c;

		if(result > 1e6) {
			break;
		}

		v_z.push_back(result);
	}

	return v_z.size();
}

int main() 
{
	std::vector<double> numbers {};
	double c = -3.;
	constexpr double dc = 0.01;

	while(c < 1.) {
		std::size_t control = points(c);

		if(control == 1001) {
			numbers.push_back(c);
		}

		c += dc;
	}

	std::ofstream fout("numbers.txt");

	for (auto i : numbers) {
		fout << i << ' ' << 0 << '\n';
	}

	fout.close();
}
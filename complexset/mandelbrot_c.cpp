#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <fstream>

auto points(std::complex<double> const& c) 
{
  constexpr std::complex<double> z_0 {0., 0.};
  std::vector<std::complex<double>> v_z {z_0};

  for(int i{}; i != 1e3; ++i) {
    std::complex<double> result = std::pow(v_z.back(), 2) + c;
    if(result.real() > 1e6) {
      break;
    }
    v_z.push_back(result);
  }
  
  return v_z.size();
}

int main() 
{
  constexpr double DEGTORAD = 2 * M_PI / 360;
  std::ofstream fout {"data.txt"};
  std::vector<std::complex<double>> numbers {};

  for(int i{}; i != 300; ++i) {
    double rho = static_cast<double>(i) / 100;
    for(int j{}; j != 360; ++j) {
      double theta = j * DEGTORAD;
      std::complex<double> c = std::polar(rho, theta);
      auto control = points(c);
      if(control == 1001) {
        numbers.push_back(c);
      }
    }
  }

  for(auto i : numbers) {
    fout << i.real() << ' ' << i.imag() << '\n';
  }

  fout.close();
}
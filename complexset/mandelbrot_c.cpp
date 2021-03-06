#include <cmath>
#include <complex>
#include <vector>

#include <SFML/Graphics.hpp>

struct Point 
{
  double x;
  double y;
};

auto points(std::complex<double> const& c) noexcept
{
  constexpr std::complex<double> z_0 {0., 0.};
  std::vector<std::complex<double>> v_z {z_0};

  for(int i{}; i != 1e3; ++i) {
    std::complex<double> result = std::pow(v_z.back(), 2) + c;
    if(result.real() > 1e9) {
      break;
    }
    v_z.push_back(result);
  }
  
  return v_z.size();
}

int main() 
{
  constexpr double window_width = 900;
  constexpr double window_height = 900;
  constexpr double point_min_x = -2.;
  constexpr double point_max_x = 1.;
  constexpr double point_min_y = -1.5;
  constexpr double point_max_y = 1.5;
  constexpr auto radius = 0.5;

  constexpr double DEGTORAD = 2 * M_PI / 360;

  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Mandelbrot Set", sf::Style::Default, settings);

  auto to_window_frame = [](Point const& p) {
    constexpr auto x_scale = window_width / (point_max_x - point_min_x);
    constexpr auto y_scale = window_height / (point_max_y - point_min_y);
    return sf::Vector2f((p.x - point_min_x) * x_scale, window_height - (p.y - point_min_y) * y_scale);
  };

  if (window.isOpen()) {
    window.clear(sf::Color::Black);
    for(int i{}; i != 3000; ++i) {
      double rho = static_cast<double>(i) / 1000;
      for(int j{}; j != 2880; ++j) {
        double theta = j * DEGTORAD / 8;
        std::complex<double> c = std::polar(rho, theta);
        auto control = points(c);
        if(control == 1001) {
          Point p {c.real(), c.imag()};
          sf::CircleShape c{radius};
          c.setFillColor(sf::Color::Cyan);
          c.setOrigin(sf::Vector2f{radius, radius});
          c.move(to_window_frame(p));
          window.draw(c);
        }
      }
    }

    window.display();

    sf::Event event;
    while (window.waitEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        break;
      }
    }
  }
}

#include "colors.hpp"

const Color colors::darkBlue{44, 44, 127, 255};
const Color colors::lightBlue{59, 85, 162, 255};
const Color colors::yellow{237, 234, 4, 255};
const Color colors::red{232, 18, 18, 255};
const Color colors::orange{226, 116, 17, 255};
const Color colors::violet{166, 0, 247, 255};
const Color colors::navyBlue{21, 204, 209, 255};
const Color colors::blue{13, 64, 216, 255};
const Color colors::green{47, 230, 23, 255};

std::vector<Color> colors::GetColors() {
  std::vector<Color> tiles;
  tiles.push_back(lightBlue);
  tiles.push_back(yellow);
  tiles.push_back(red);
  tiles.push_back(orange);
  tiles.push_back(violet);
  tiles.push_back(navyBlue);
  tiles.push_back(blue);
  tiles.push_back(green);
  return tiles;
}
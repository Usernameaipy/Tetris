#pragma once
#include <raylib.h>

#include <vector>

namespace colors {
extern const Color darkBlue;
extern const Color lightBlue;
extern const Color yellow;
extern const Color red;
extern const Color orange;
extern const Color violet;
extern const Color navyBlue;
extern const Color blue;
extern const Color green;
std::vector<Color> GetColors();
}  // namespace colors
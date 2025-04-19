#include "font.hpp"

GameFont::GameFont() {}

GameFont::GameFont(std::string path) : path{path}, fontSize{45}, spacing{2} {
  customFt = LoadFont(path.c_str());
}

GameFont::~GameFont() { UnloadFont(customFt); }

void GameFont::Draw(std::string string, Vector2 pos) {
  DrawTextEx(customFt, string.c_str(), pos, fontSize, spacing, WHITE);
}

int GameFont::Size(const char* str) { return MeasureText(str, 45); }
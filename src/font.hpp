#pragma once

#include <raylib.h>

#include <string>

class GameFont {
  std::string path;
  Font customFt;
  float fontSize;
  float spacing;

 public:
  GameFont();
  GameFont(std::string path);
  ~GameFont();
  void Draw(std::string string, Vector2 pos);
  int Size(const char* str);
};
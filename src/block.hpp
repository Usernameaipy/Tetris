#pragma once
#include <raylib.h>

#include <map>
#include <vector>

#include "colors.hpp"

struct Position {
  int x;
  int y;
};

class Block {
 protected:
  int rotate;
  int cellSize;
  int colorId;
  int shift;
  std::vector<Color> color;
  std::map<int, std::vector<Position>> rotates;
  void Move(int setX, int setY, int rat);

 private:
  int offSetX;
  int offSetY;

 public:
  Block();
  std::vector<Position> GetNowRotate();
  void Draw(int setX = 0, int setY = 0);
  void MoveBlockLeft();
  void MoveBlockRight();
  void MoveBlockDown();
  void MoveBlockUp();
  void MoveUnBlockRot();
  void MoveBlockRot();
  int GetOffSetX();
  int GetOffSetY();
  int GetColorId();
};
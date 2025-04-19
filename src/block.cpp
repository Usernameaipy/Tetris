#include "block.hpp"

Block::Block() : rotate{0}, cellSize{40}, offSetX{0}, offSetY{0}, shift{10} {
  color = colors::GetColors();
}

std::vector<Position> Block::GetNowRotate() { return rotates[rotate]; }

void Block::Draw(int setX, int setY) {
  std::vector<Position> tiles = GetNowRotate();
  for (Position item : tiles)
    DrawRectangleRounded(
        (Rectangle){(float)(item.y + offSetY) * cellSize + shift + setX,
                    (float)(item.x + offSetX) * cellSize + shift + setY,
                    (float)cellSize - 1, (float)cellSize - 1},
        0.2, 20, color[colorId]);
}

void Block::Move(int setX, int setY, int rat) {
  offSetX += setX;
  offSetY += setY;
  rotate += rat;
}

void Block::MoveBlockLeft() { Move(0, -1, 0); }

void Block::MoveBlockRight() { Move(0, 1, 0); }

void Block::MoveBlockDown() { Move(1, 0, 0); }

void Block::MoveBlockUp() { Move(-1, 0, 0); }

void Block::MoveBlockRot() {
  if (rotate == rotates.size() - 1)
    rotate = 0;
  else
    Move(0, 0, 1);
}

void Block::MoveUnBlockRot() {
  if (rotate == 0)
    rotate = rotates.size() - 1;
  else
    Move(0, 0, -1);
}

int Block::GetOffSetX() { return offSetX; }

int Block::GetOffSetY() { return offSetY; }

int Block::GetColorId() { return colorId; }
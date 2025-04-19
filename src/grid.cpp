#include "grid.hpp"

Grid::Grid() : numRow{10}, numColl{20}, cellSize(40), shift{10} {
  SetGridNull();
}

void Grid::SetGridNull() {
  for (int row = 0; row < numRow; row++)
    for (int coll = 0; coll < numColl; coll++) grid[row][coll] = 0;
}

Color Grid::WhatCellColor(int row, int coll) {
  Color res;
  switch (grid[row][coll]) {
    case 0:
      res = colors::lightBlue;
      break;
    case 1:
      res = colors::yellow;
      break;
    case 2:
      res = colors::red;
      break;
    case 3:
      res = colors::orange;
      break;
    case 4:
      res = colors::violet;
      break;
    case 5:
      res = colors::navyBlue;
      break;
    case 6:
      res = colors::blue;
      break;
    case 7:
      res = colors::green;
      break;
    default:
      res = colors::darkBlue;
      break;
  }
  return res;
}

void Grid::GridDraw() {
  for (int row = 0; row < numRow; row++)
    for (int coll = 0; coll < numColl; coll++)
      DrawRectangleRounded(
          (Rectangle){(float)row * cellSize + shift,
                      (float)coll * cellSize + shift, (float)cellSize - 1,
                      (float)cellSize - 1},
          0.2, 20, WhatCellColor(row, coll));
}

bool Grid::IsCellOutside(int row, int coll) {
  if (row >= 0 && row < numRow && coll >= 0 && coll < numColl) return false;
  return true;
}

bool Grid::IsCellEmpty(int row, int coll) {
  if (grid[row][coll]) return false;
  return true;
}

void Grid::SetCellGrid(int row, int coll, int color) {
  grid[row][coll] = color;
}

bool Grid::IsRowFull(int coll) {
  for (int row = 0; row < numRow; row++)
    if (!grid[row][coll]) return false;
  return true;
}

void Grid::ClearRow(int coll) {
  for (int row = 0; row < numRow; row++) grid[row][coll] = 0;
}

void Grid::MoveRowDown(int coll, int numcoll) {
  for (int row = 0; row < numRow; row++) {
    grid[row][coll + numcoll] = grid[row][coll];
    grid[row][coll] = 0;
  }
}

int Grid::ClearFullRows() {
  int completed = 0;
  for (int coll = numColl - 1; coll >= 0; coll--) {
    if (IsRowFull(coll)) {
      ClearRow(coll);
      completed += 1;
    } else if (completed > 0) {
      MoveRowDown(coll, completed);
    }
  }
  return completed;
}
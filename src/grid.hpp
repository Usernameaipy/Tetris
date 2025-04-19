#pragma once

#include "colors.hpp"

class Grid {
  int grid[10][20];
  int numRow;
  int numColl;
  int cellSize;
  int shift;
  Color WhatCellColor(int row, int coll);

 public:
  Grid();
  void GridDraw();
  bool IsCellOutside(int, int);
  bool IsCellEmpty(int, int);
  void SetCellGrid(int, int, int);
  int ClearFullRows();
  bool IsRowFull(int);
  void ClearRow(int);
  void SetGridNull();
  void MoveRowDown(int, int);
};
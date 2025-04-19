#ifndef PLAY
#define PLAY
#include <raylib.h>
#include <stdio.h>

#include <random>

#include "blocks.hpp"
#include "colors.hpp"
#include "font.hpp"
#include "grid.hpp"

class Time {
  double lastUpdateTime;

 public:
  Time();
  bool EventTriggered(double interval);
};

class Game {
  Grid grid;
  Time time;
  GameFont text;
  std::vector<Block> blocksV;
  Block currentBlock;
  Block nextBlock;
  Sound rotate;
  Sound clear;
  Music music;
  short gameOver;
  int score;
  int GetRandomNumber(int st, int fn);
  std::vector<Block> GetVectorBlock();
  Block GetRandomBlock();
  void MoveBlockLeffCheck();
  void MoveBlockRightCheck();
  void MoveBlockDownCheck();
  void MoveRotateBlockCheck();
  void KeyCheck();
  bool CheckCollisionWin();
  bool CheckCollisions();
  void BlockFixChange();
  void GameDraw();
  void TableDraw();
  void CheckGameOver();
  void GameOver();
  void ResetGame();
  void DrawNextBlock();
  void RowsScore(int);
  void DrawScore();

 public:
  Game();
  ~Game();
  void play();
};
#endif
#include "play.hpp"

Time::Time() : lastUpdateTime{0} {}

bool Time::EventTriggered(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

Game::Game() {
  grid = Grid();
  time = Time();
  InitAudioDevice();
  music = LoadMusicStream("../sounds/music.mp3");
  PlayMusicStream(music);
  rotate = LoadSound("../sounds/rotate.mp3");
  clear = LoadSound("../sounds/clear.mp3");
  text = GameFont("../fonts/pixels.ttf");
  gameOver = 0;
  score = 0;
  blocksV = GetVectorBlock();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
}

Game::~Game() {
  UnloadMusicStream(music);
  UnloadSound(rotate);
  UnloadSound(clear);
  CloseAudioDevice();
}

void Game::play() {
  InitWindow(670, 820, "Tetris");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    UpdateMusicStream(music);
    if (gameOver) ResetGame();
    KeyCheck();
    BeginDrawing();
    ClearBackground(colors::darkBlue);
    CheckGameOver();
    GameDraw();
    if (time.EventTriggered(0.2)) MoveBlockDownCheck();
    EndDrawing();
  }
  CloseWindow();
}

std::vector<Block> Game::GetVectorBlock() {
  return {OBlock(), IBlock(), SBlock(), ZBlock(), LBlock(), JBlock(), TBlock()};
}

Block Game::GetRandomBlock() {
  if (blocksV.empty()) blocksV = GetVectorBlock();
  int pos = GetRandomNumber(0, blocksV.size() - 1);
  Block tmp = blocksV[pos];
  blocksV.erase(blocksV.begin() + pos);
  return tmp;
}

int Game::GetRandomNumber(int st, int fn) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(st, fn);
  return distr(gen);
}

void Game::MoveBlockLeffCheck() {
  if (!gameOver) {
    currentBlock.MoveBlockLeft();
    if (CheckCollisionWin() || CheckCollisions() == false)
      currentBlock.MoveBlockRight();
  }
}

void Game::MoveBlockRightCheck() {
  if (!gameOver) {
    currentBlock.MoveBlockRight();
    if (CheckCollisionWin() || CheckCollisions() == false)
      currentBlock.MoveBlockLeft();
  }
}

void Game::MoveBlockDownCheck() {
  if (!gameOver) {
    currentBlock.MoveBlockDown();
    if (CheckCollisionWin() || CheckCollisions() == false) {
      currentBlock.MoveBlockUp();
      BlockFixChange();
    }
  }
}

void Game::MoveRotateBlockCheck() {
  if (!gameOver) {
    currentBlock.MoveBlockRot();
    if (CheckCollisionWin() || CheckCollisions() == false)
      currentBlock.MoveUnBlockRot();
    else
      PlaySound(rotate);
  }
}

void Game::KeyCheck() {
  int keyPressed = GetKeyPressed();
  switch (keyPressed) {
    case (KEY_LEFT):
      MoveBlockLeffCheck();
      break;
    case (KEY_RIGHT):
      MoveBlockRightCheck();
      break;
    case (KEY_DOWN):
      MoveBlockDownCheck();
      score += 10;
      break;
    case (KEY_UP):
      MoveRotateBlockCheck();
      break;
  }
}

bool Game::CheckCollisionWin() {
  std::vector<Position> tiles = currentBlock.GetNowRotate();
  for (Position item : tiles) {
    if (grid.IsCellOutside(item.y + currentBlock.GetOffSetY(),
                           item.x + currentBlock.GetOffSetX()))
      return true;
  }
  return false;
}

bool Game::CheckCollisions() {
  std::vector<Position> tiles = currentBlock.GetNowRotate();
  for (Position item : tiles) {
    if (grid.IsCellEmpty(item.y + currentBlock.GetOffSetY(),
                         item.x + currentBlock.GetOffSetX()) == false)
      return false;
  }
  return true;
}

void Game::BlockFixChange() {
  std::vector<Position> tiles = currentBlock.GetNowRotate();
  int color = currentBlock.GetColorId();
  for (Position item : tiles) {
    grid.SetCellGrid(item.y + currentBlock.GetOffSetY(),
                     item.x + currentBlock.GetOffSetX(), color);
  }
  currentBlock = nextBlock;
  if (CheckCollisions() == false) gameOver = 1;
  nextBlock = GetRandomBlock();
  if (grid.ClearFullRows()) PlaySound(clear);
}

void Game::RowsScore(int num) {
  switch (num) {
    case 1:
      score += 100;
      break;
    case 2:
      score += 300;
      break;
    case 3:
      score += 500;
      break;
    case 4:
      score += 1000;
      break;
    default:
      score += 2000;
      break;
  }
}

void Game::TableDraw() {
  text.Draw("score", Vector2{475, 20});
  text.Draw("next", Vector2{495, 160});
  DrawRectangleRounded((Rectangle){450.0f, 70.0f, 180.0f, 70.0f}, 0.3f, 6,
                       colors::lightBlue);
  DrawRectangleRounded((Rectangle){450.0f, 210.0f, 180.0f, 175.0f}, 0.3f, 6,
                       colors::lightBlue);
}

void Game::DrawScore() {
  char str[10] = {0};
  sprintf(str, "%d", score);
  int textSize = text.Size(str);
  text.Draw(str, Vector2{(float)450 + ((180 - textSize) / 2) + 1, 82.0f});
}

void Game::DrawNextBlock() {
  switch (nextBlock.GetColorId()) {
    case 1:
      nextBlock.Draw(330, 245);
      break;
    case 2:
      nextBlock.Draw(330, 265);
      break;
    case 3:
      nextBlock.Draw(310, 245);
      break;
    case 4:
      nextBlock.Draw(350, 245);
      break;
    case 5:
      nextBlock.Draw(330, 220);
      break;
    case 6:
      nextBlock.Draw(330, 220);
      break;
    case 7:
      nextBlock.Draw(350, 245);
      break;
  }
}

void Game::GameDraw() {
  grid.GridDraw();
  TableDraw();
  if (!gameOver) {
    currentBlock.Draw(0, 0);
    DrawNextBlock();
  }
  DrawScore();
}

void Game::CheckGameOver() {
  if (gameOver) GameOver();
}

void Game::GameOver() { text.Draw("GAMEOVER", Vector2{417, 415}); }

void Game::ResetGame() {
  int key = GetKeyPressed();
  if (key == KEY_SPACE) {
    gameOver = 0;
    score = 0;
    grid.SetGridNull();
    blocksV = GetVectorBlock();
  }
}
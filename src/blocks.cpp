#include "blocks.hpp"

OBlock::OBlock() {
  colorId = 1;
  rotates[0] = {Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1}};
  Move(0, 4, 0);
};

IBlock::IBlock() {
  colorId = 2;
  rotates[0] = {Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{1, 3}};
  rotates[1] = {Position{0, 2}, Position{1, 2}, Position{2, 2}, Position{3, 2}};
  rotates[2] = {Position{2, 0}, Position{2, 1}, Position{2, 2}, Position{2, 3}};
  rotates[3] = {Position{0, 1}, Position{1, 1}, Position{2, 1}, Position{3, 1}};
  Move(-1, 3, 0);
}

SBlock::SBlock() {
  colorId = 3;
  rotates[0] = {Position{0, 1}, Position{0, 2}, Position{1, 0}, Position{1, 1}};
  rotates[1] = {Position{0, 1}, Position{1, 1}, Position{1, 2}, Position{2, 2}};
  rotates[2] = {Position{1, 1}, Position{1, 2}, Position{2, 0}, Position{2, 1}};
  rotates[3] = {Position{0, 0}, Position{1, 0}, Position{1, 1}, Position{2, 1}};
  Move(0, 4, 0);
}

ZBlock::ZBlock() {
  colorId = 4;
  rotates[0] = {Position{0, 0}, Position{0, 1}, Position{1, 1}, Position{1, 2}};
  rotates[1] = {Position{0, 2}, Position{1, 1}, Position{1, 2}, Position{2, 1}};
  rotates[2] = {Position{1, 0}, Position{1, 1}, Position{2, 1}, Position{2, 2}};
  rotates[3] = {Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{2, 0}};
  Move(0, 3, 0);
}

LBlock::LBlock() {
  colorId = 5;
  rotates[0] = {Position{0, 1}, Position{1, 1}, Position{2, 1}, Position{2, 2}};
  rotates[1] = {Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 0}};
  rotates[2] = {Position{0, 0}, Position{0, 1}, Position{1, 1}, Position{2, 1}};
  rotates[3] = {Position{0, 2}, Position{1, 0}, Position{1, 1}, Position{1, 2}};
  Move(0, 3, 0);
}

JBlock::JBlock() {
  colorId = 6;
  rotates[0] = {Position{0, 1}, Position{1, 1}, Position{2, 0}, Position{2, 1}};
  rotates[1] = {Position{0, 0}, Position{1, 0}, Position{1, 1}, Position{1, 2}};
  rotates[2] = {Position{0, 1}, Position{0, 2}, Position{1, 1}, Position{2, 1}};
  rotates[3] = {Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 2}};
  Move(0, 4, 0);
}

TBlock::TBlock() {
  colorId = 7;
  rotates[0] = {Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{1, 2}};
  rotates[1] = {Position{0, 1}, Position{1, 1}, Position{1, 2}, Position{2, 1}};
  rotates[2] = {Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 1}};
  rotates[3] = {Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{2, 1}};
  Move(0, 3, 0);
}
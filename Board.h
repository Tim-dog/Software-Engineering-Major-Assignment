#pragma once

#include "Config.h"
#include <array>

class Board {
public:
    Board();

    // 重置棋盘
    void reset();

    // 在指定位置落子
    bool placeMark(int row, int col, CellState mark);

    // 获取指定格子的状态
    CellState getCell(int row, int col) const;

    // 判断指定格子是否为空
    bool isEmpty(int row, int col) const;

    // 判断坐标是否在棋盘范围内
    bool isInside(int row, int col) const;

    // TODO 1：判断棋盘是否已满
    bool isFull() const;

private:
    std::array<std::array<CellState, BOARD_SIZE>, BOARD_SIZE> grid_;
};
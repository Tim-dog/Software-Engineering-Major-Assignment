#pragma once

#include "Game.h"

class BoardView {
public:
    // 绘制整个命令行界面
    void draw(const Game& game) const;

    // 绘制棋盘
    void drawBoard(const Board& board) const;

    // 绘制游戏状态
    void drawStatus(const Game& game) const;

private:
    // 将 CellState 转换为字符
    char cellToChar(CellState cell) const;
};
#pragma once

#include "Board.h"
#include <utility>

class Player {
public:
    explicit Player(CellState mark);
    virtual ~Player() = default;

    // 获取玩家棋子类型
    CellState getMark() const;

    // 执行落子，返回 row 和 col
    virtual std::pair<int, int> play(const Board& board) = 0;

protected:
    CellState mark_;
};

class HumanPlayer : public Player {
public:
    explicit HumanPlayer(CellState mark);

    // TODO 2：让人类玩家从命令行输入坐标
    std::pair<int, int> play(const Board& board) override;
};

class AIPlayer : public Player {
public:
    explicit AIPlayer(CellState mark);

    // TODO 3：实现简单的 AI 落子逻辑
    std::pair<int, int> play(const Board& board) override;
};
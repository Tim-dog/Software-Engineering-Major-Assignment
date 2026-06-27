#pragma once

// 棋盘大小
constexpr int BOARD_SIZE = 3;

// 棋子状态
enum class CellState {
    Empty,
    X,
    O
};

// 游戏模式
enum class GameMode {
    HumanVsHuman,
    HumanVsAI
};
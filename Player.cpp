#include "Player.h"
#include <iostream>
#include <limits>

Player::Player(CellState mark) : mark_(mark) {}

CellState Player::getMark() const {
    return mark_;
}

HumanPlayer::HumanPlayer(CellState mark) : Player(mark) {}

std::pair<int, int> HumanPlayer::play(const Board& board) {
    int row, col;

    while (true) {
        std::cout << "请输入落子坐标 (行 列)，以空格分隔：";

        if (!(std::cin >> row >> col)) {
            std::cout << "输入格式错误，请输入两个整数（0-2）。\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        // 丢弃当前行剩余内容，避免影响后续输入
        std::cin.ignore(10000, '\n');

        if (!board.isInside(row, col)) {
            std::cout << "坐标超出范围，请输入 0 到 " << BOARD_SIZE - 1 << " 之间的值。\n";
            continue;
        }

        if (!board.isEmpty(row, col)) {
            std::cout << "该位置已被占用，请选择其他位置。\n";
            continue;
        }

        break;
    }

    return { row, col };
}

AIPlayer::AIPlayer(CellState mark) : Player(mark) {}

std::pair<int, int> AIPlayer::play(const Board& board) {
    // 简单 AI：从左到右、从上到下寻找第一个空格
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (board.isEmpty(row, col)) {
                std::cout << "AI 选择落子位置：(" << row << ", " << col << ")\n";
                return { row, col };
            }
        }
    }

    // 理论上不会到这里（棋盘未满时一定有空格）
    return { -1, -1 };
}

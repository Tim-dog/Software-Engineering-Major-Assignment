#include "Board.h"

Board::Board() {
    reset();
}

void Board::reset() {
    for (auto& row : grid_) {
        row.fill(CellState::Empty);
    }
}

bool Board::placeMark(int row, int col, CellState mark) {
    if (!isInside(row, col)) {
        return false;
    }

    if (grid_[row][col] != CellState::Empty) {
        return false;
    }

    grid_[row][col] = mark;
    return true;
}

CellState Board::getCell(int row, int col) const {
    return grid_[row][col];
}

bool Board::isEmpty(int row, int col) const {
    return isInside(row, col) && grid_[row][col] == CellState::Empty;
}

bool Board::isInside(int row, int col) const {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

bool Board::isFull() const {
    // 遍历棋盘，如果还存在 Empty，说明棋盘未满
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (grid_[row][col] == CellState::Empty) {
                return false;
            }
        }
    }
    return true;
}

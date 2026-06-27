#include "Game.h"

Game::Game(GameMode mode)
    : mode_(mode),
    humanX_(CellState::X),
    humanO_(CellState::O),
    aiPlayer_(CellState::O) {
    reset();
}

void Game::reset() {
    board_.reset();
    currentPlayer_ = CellState::X;
    winner_ = CellState::Empty;
    gameOver_ = false;
    draw_ = false;
}

Board& Game::getBoard() {
    return board_;
}

const Board& Game::getBoard() const {
    return board_;
}

CellState Game::getCurrentPlayer() const {
    return currentPlayer_;
}

CellState Game::getWinner() const {
    return winner_;
}

bool Game::isGameOver() const {
    return gameOver_;
}

bool Game::isDraw() const {
    return draw_;
}

GameMode Game::getMode() const {
    return mode_;
}

HumanPlayer& Game::getHumanX() {
    return humanX_;
}

HumanPlayer& Game::getHumanO() {
    return humanO_;
}

AIPlayer& Game::getAIPlayer() {
    return aiPlayer_;
}

bool Game::makeMove(int row, int col) {
    if (gameOver_) {
        return false;
    }

    if (!board_.placeMark(row, col, currentPlayer_)) {
        return false;
    }

    if (checkWinner(currentPlayer_)) {
        winner_ = currentPlayer_;
        gameOver_ = true;
        return true;
    }

    if (board_.isFull()) {
        draw_ = true;
        gameOver_ = true;
        return true;
    }

    switchPlayer();
    return true;
}

bool Game::checkWinner(CellState mark) const {
    // 检查所有行
    for (int row = 0; row < BOARD_SIZE; ++row) {
        bool rowWin = true;
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (board_.getCell(row, col) != mark) {
                rowWin = false;
                break;
            }
        }
        if (rowWin) return true;
    }

    // 检查所有列
    for (int col = 0; col < BOARD_SIZE; ++col) {
        bool colWin = true;
        for (int row = 0; row < BOARD_SIZE; ++row) {
            if (board_.getCell(row, col) != mark) {
                colWin = false;
                break;
            }
        }
        if (colWin) return true;
    }

    // 检查主对角线（左上到右下）
    bool diagWin = true;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board_.getCell(i, i) != mark) {
            diagWin = false;
            break;
        }
    }
    if (diagWin) return true;

    // 检查副对角线（右上到左下）
    bool antiDiagWin = true;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board_.getCell(i, BOARD_SIZE - 1 - i) != mark) {
            antiDiagWin = false;
            break;
        }
    }
    if (antiDiagWin) return true;

    return false;
}

void Game::switchPlayer() {
    // 在 X 和 O 之间切换当前玩家
    currentPlayer_ = (currentPlayer_ == CellState::X) ? CellState::O : CellState::X;
}

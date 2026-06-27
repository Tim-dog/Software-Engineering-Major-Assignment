#include "GameController.h"
#include <iostream>

GameController::GameController(GameMode mode)
    : game_(mode) {}

void GameController::run() {
    while (!game_.isGameOver()) {
        view_.draw(game_);
        handleTurn();
    }

    view_.draw(game_);
}

void GameController::handleTurn() {
    std::pair<int, int> move;

    // 1. 根据当前玩家和游戏模式，选择 HumanPlayer 或 AIPlayer
    CellState currentPlayer = game_.getCurrentPlayer();

    if (currentPlayer == CellState::X) {
        // 玩家 X 始终由人类控制
        move = game_.getHumanX().play(game_.getBoard());
    }
    else { // CellState::O
        if (game_.getMode() == GameMode::HumanVsHuman) {
            // 双人模式：玩家 O 也是人类
            move = game_.getHumanO().play(game_.getBoard());
        }
        else {
            // 人机模式：玩家 O 是 AI
            move = game_.getAIPlayer().play(game_.getBoard());
        }
    }

    int row = move.first;
    int col = move.second;

    // 2-4. 调用 makeMove，如果落子失败则提示
    if (!game_.makeMove(row, col)) {
        std::cout << "落子失败，请重试。\n";
    }
}

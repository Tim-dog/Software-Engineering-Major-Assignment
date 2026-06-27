#include "BoardView.h"
#include <iostream>

void BoardView::draw(const Game& game) const {
    std::cout << "\n============================\n";
    std::cout << "       Morpion MVC C++      \n";
    std::cout << "============================\n\n";

    drawBoard(game.getBoard());
    drawStatus(game);
}

void BoardView::drawBoard(const Board& board) const {
    std::cout << "坐标说明：行和列均为 0 到 2\n\n";

    std::cout << "     0   1   2\n";
    std::cout << "   +---+---+---+\n";

    for (int row = 0; row < BOARD_SIZE; ++row) {
        std::cout << " " << row << " |";

        for (int col = 0; col < BOARD_SIZE; ++col) {
            std::cout << " " << cellToChar(board.getCell(row, col)) << " |";
        }

        std::cout << "\n";
        std::cout << "   +---+---+---+\n";
    }

    std::cout << "\n";
}

void BoardView::drawStatus(const Game& game) const {
    if (game.isGameOver()) {
        if (game.isDraw()) {
            std::cout << "游戏结束：平局！\n";
        }
        else {
            std::cout << "游戏结束：玩家 "
                << (game.getWinner() == CellState::X ? 'X' : 'O')
                << " 获胜！\n";
        }
    }
    else {
        std::cout << "当前回合：玩家 "
            << (game.getCurrentPlayer() == CellState::X ? 'X' : 'O')
            << "\n";
    }
}

char BoardView::cellToChar(CellState cell) const {
    if (cell == CellState::X) {
        return 'X';
    }

    if (cell == CellState::O) {
        return 'O';
    }

    return ' ';
}
#pragma once

#include "Game.h"
#include "BoardView.h"

class GameController {
public:
    explicit GameController(GameMode mode);

    // 启动游戏主循环
    void run();

private:
    // TODO 6：处理一个回合
    void handleTurn();

private:
    Game game_;
    BoardView view_;
};
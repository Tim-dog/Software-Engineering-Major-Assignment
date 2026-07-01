// 井字棋游戏 (Morpion) — 软件工程大作业
// 基于 MVC 架构的命令行井字棋，支持双人对战和人机对战
// 作者：苏怡萌 | 班级：水电2401班 | 学号：U202411889

#include "Config.h"
#include "GameController.h"

#include <iostream>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    // 设置 Windows 控制台输入和输出为 UTF-8，解决中文乱码问题
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    std::cout << "============================\n";
    std::cout << "       Morpion MVC C++      \n";
    std::cout << "============================\n";
    std::cout << "请选择游戏模式：\n";
    std::cout << "1. 双人对战\n";
    std::cout << "2. 人机对战\n";
    std::cout << "请输入选择：";

    int choice = 0;

    while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cout << "输入无效，请输入 1 或 2：";

        // 清理错误状态
        std::cin.clear();

        // 丢弃当前行剩余内容
        std::cin.ignore(10000, '\n');
    }

    GameMode mode = choice == 1 ? GameMode::HumanVsHuman : GameMode::HumanVsAI;

    GameController controller(mode);
    controller.run();

    std::cout << "\n按回车键退出程序...";

    std::cin.ignore(10000, '\n');
    std::cin.get();

    return 0;
}

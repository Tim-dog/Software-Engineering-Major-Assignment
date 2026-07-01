# 井字棋游戏 (Morpion) — 基于 MVC 架构的 C++ 命令行应用

> **华中科技大学 软件工程大作业**  
> 作者：苏怡萌 | 学号：U202411889 | 班级：水电2401班

---

## 📖 项目简介

本项目是软件工程课程的期末大作业，要求使用 **C++** 语言，基于 **MVC（Model-View-Controller）** 设计模式，实现一个命令行交互的井字棋（Tic-Tac-Toe）游戏。程序在 Windows 平台下开发，支持 Visual Studio 和 VSCode 编译运行。

### 主要特性

- 🎮 **双人对战模式**：两名玩家在同一台电脑上轮流落子
- 🤖 **人机对战模式**：AI 自动选择第一个可落子的空格
- 🧱 **严格的 MVC 分层**：Model 管理数据和逻辑，View 负责界面渲染，Controller 协调交互流程
- 🛡️ **完善的输入校验**：自动检测坐标越界、位置占用、格式错误等异常输入
- 📐 **面向对象设计**：使用继承与多态实现人类玩家和 AI 玩家的统一接口

### 技术栈

| 项目 | 说明 |
|------|------|
| 编程语言 | C++20 |
| 开发环境 | Visual Studio 2022 / VSCode |
| 编译器 | MSVC / GCC (MinGW-w64) |
| 构建工具 | Visual Studio 项目文件 (.vcxproj) + VSCode tasks.json |
| 版本控制 | Git + GitHub |

---

## 🏗️ MVC 架构说明

```
┌───────────────────────────────────────────────┐
│              GameController (Controller)       │
│         控制游戏流程，调度 Model 和 View         │
└──────────┬──────────────────┬─────────────────┘
           │                  │
    ┌──────▼──────┐    ┌──────▼──────┐
    │    Game      │    │  BoardView   │
    │  (Model)     │    │  (View)      │
    │ 核心游戏逻辑  │    │ 命令行界面    │
    └──────┬──────┘    └──────────────┘
           │
    ┌──────┼──────┐
    │      │       │
┌───▼──┐ ┌─▼──┐ ┌─▼────┐
│Board │ │Player│ │Config │
│棋盘   │ │玩家  │ │配置   │
└──────┘ └─────┘ └──────┘
```

- **Model 层**：`Board`（棋盘状态）、`Player`（玩家抽象，含 `HumanPlayer` 和 `AIPlayer` 子类）、`Game`（游戏状态机）
- **View 层**：`BoardView`（在命令行中绘制棋盘、显示提示信息）
- **Controller 层**：`GameController`（游戏主循环，根据模式选择玩家类型并处理回合）

---

## 📁 项目结构

```
ProjectMorpion/
├── main.cpp                 # 程序入口：模式选择 + UTF-8 控制台设置
├── Config.h                 # 全局配置：棋盘大小、CellState/GameMode 枚举
├── Board.h / Board.cpp      # Model: 棋盘状态管理（落子、判满、查询）
├── Player.h / Player.cpp    # Model: 玩家抽象基类 + HumanPlayer + AIPlayer
├── Game.h / Game.cpp        # Model: 游戏核心逻辑（makeMove、checkWinner、switchPlayer）
├── BoardView.h / BoardView.cpp  # View: 命令行棋盘渲染与状态显示
├── GameController.h / GameController.cpp  # Controller: 主循环与回合调度
├── ProjectMorpion.slnx      # Visual Studio 解决方案
├── ProjectMorpion.vcxproj   # Visual Studio 项目文件
├── .vscode/tasks.json       # VSCode 编译任务：Ctrl+Shift+B 一键编译运行
└── .gitignore               # Git 忽略规则
```

---

## 🔧 编译与运行

### 方式一：Visual Studio

双击 `ProjectMorpion.slnx` 打开解决方案，按 `Ctrl+F5` 编译运行。

### 方式二：VSCode

在项目根目录打开终端：

```powershell
# 编译
g++ -std=c++20 *.cpp -o morpion.exe

# 运行
.\morpion.exe
```

或直接按 `Ctrl+Shift+B` 使用预配置的编译任务。

---

## 🎯 游戏规则

- 采用经典 **3×3 棋盘**，玩家 **X 先手**
- 玩家轮流输入行号和列号（范围 0~2）落子
- 横向、纵向或对角线上**率先形成三连**者获胜
- 棋盘被**填满且无人获胜**则判定为平局

---

## 📝 软件工程实践

本项目遵循以下软件工程原则：

- **MVC 分层架构**：严格分离数据、界面和控制逻辑，提高可维护性
- **策略模式**：通过 `Player` 抽象基类和虚函数 `play()`，实现对人类玩家和 AI 玩家的统一调用
- **防御式编程**：所有用户输入均经过格式校验、范围检查和占位检测
- **版本控制**：使用 Git 进行增量式开发，分时间段提交，完整记录开发过程

---

**© 2026 苏怡萌 | 华中科技大学 水电2401班**

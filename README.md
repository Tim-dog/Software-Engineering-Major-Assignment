# 井字棋游戏 (Morpion) - MVC 架构 C++

## 项目简介

基于 **MVC 架构** 的命令行井字棋游戏。支持双人对战和人机对战模式。

- **语言**：C++20
- **平台**：Windows + Visual Studio / VSCode
- **架构**：Model-View-Controller

## 项目结构

```
ProjectMorpion/
├── main.cpp              # 程序入口，模式选择
├── Config.h              # 全局配置（棋盘大小、枚举）
├── Board.h / Board.cpp   # Model: 棋盘状态
├── Player.h / Player.cpp # Model: 玩家（人类/AI）
├── Game.h / Game.cpp     # Model: 游戏核心逻辑
├── BoardView.h / BoardView.cpp  # View: 命令行界面
├── GameController.h / GameController.cpp  # Controller: 流程控制
├── docs/                 # UML 设计文档
│   ├── use_case.puml     # 用例图
│   ├── class_diagram.puml # 类图
│   └── sequence_diagram.puml # 序列图
└── .gitignore
```

## 编译运行

使用 Visual Studio 打开 `ProjectMorpion.slnx`，或命令行：

```powershell
cl /EHsc /std:c++20 /Fe:morpion.exe main.cpp Board.cpp Player.cpp Game.cpp BoardView.cpp GameController.cpp
```

## 游戏规则

- 3×3 棋盘，玩家 X 先手
- 横/竖/对角线三连即获胜
- 棋盘满无人获胜则为平局

## 作者

苏怡萌 (U202411889) — 水电2401班

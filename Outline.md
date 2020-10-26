# MazeCracker
## Maze
### ICell 迷宫单元接口
- 一些关于单元的操作和属性访问
### ICellOperation 单元操作接口
- 对迷宫单元的具体操作 *如标记已探索*
### IAlgorithm 算法接口
- 提供控制算法进度的接口, 并操作单元的具体操作接口
## Opeartion
### IOperation 操作接口
- 执行与撤销
- 操作合并
### OperationStack 操作栈
- 利用栈实现操作的记录与撤销/重做
## UI
### MainWindow 主窗口
- 创建界面, 管理控件上的信号槽连接
### CellWidget 单元控件
- 实现具体操作对应的UI变化
- 与用户直接交互
### CellContainer 单元容器, 即迷宫主体
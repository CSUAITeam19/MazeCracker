# 如何把原本的算法移植到该解决方案?

1. 打开**Algorithm**项目
2. 建立新的类, 如[**UCS**](Algorithm/UCS.h), 添加`#include "Maze.h"`
   - **UCS**继承自`IMazeSearcher`
3. 将maze的定义改为`const IMaze& maze`
4. 把`ofstream out` 改为`ostream& out`, 这样可以输出到任意输出流
   - 未来可能用其它方法记录中间数据
5. 判断某个位置是否为出口可以用`maze[point_now] == MazeState::Exit`, 也可以用原本的先找到出口, 记录坐标, 搜索时比较坐标的方法
6. 坐标建议使用`Vector2D`*(在Maze.h中已经include)*, 支持直接赋值, 向量加法, 以及欧式距离`lengthFloat()`,曼哈顿距离`lengthManhattan()`, 这对于计算坐标之差及其各类距离是比较方便的
7. maze可以用`maze[Vector2D(x,y)]`获取值, 也可以用`maze[x][y]`获取
8. 自行调整所需的**初始化**步骤, 在**构造函数**中完成
9.  至少存在一个参数为`const IMaze& maze, std::ostream& out`的构造函数
10. 在**TestConsole**项目中以控制台的方式进行测试, 应该已经写好项目依赖和文件路径, 可以直接`#include "UCS.h"`. 如果运行了错误的项目, 在**解决方案资源管理器**中右键**TestConsole**, 选择"设置为启动项目"
11. 默认运行路径在`repo根目录/TestConsole/`,创建/打开文件时搜索路径相同
12. 具体详见相关项目中的代码, 有疑问联系Hyt


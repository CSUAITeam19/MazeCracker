# 编码规范
*本规范主要由Hyt根据个人开发经验与行业规范编写*
## 命名规范
- 不要使用拼音或{a-z,0-9,_}以外的字符
- 尽可能避免单字母标识符
- 常用, 公认的缩写可以适量使用, 非常用的在容易看到的地方注明缩写含义
- 缩写组成的单个词组认为是一个字母, 统一进行大小写变换
- 动词可以使用非实际英语语法来表示不同时态, 如read-readed-readen(*尽管这种情况比较少见*)
- 类: 大写驼峰
  - 纯虚类需添加I前缀, 如
  ```c++
    class LoopList : public ILinkedList {};
  ```
- 文件: 除Qt自动创建的文件外, 与类名/模块名统一
- 命名空间: 大写驼峰
  - 本项目中以MazeCracker为根命名空间
- 函数: 大部分小写驼峰; 槽函数视情况而定
- 成员变量: 小写驼峰
- 控件: 小写驼峰
- 缩进: 存在层次结构的必须缩进(*如if, for, switch*)
- 括号: 按喜好决定括号换行或不换行
## OOP规范
- 尽可能避免对非抽象类进行多重继承以消歧义
- 用接口(即抽象类)代替一般类作为基类, 而用包含代替继承来建立具体类之间的联系
- 通过类名与函数名限定类的职责与功能
- 对成员函数, 能const则const, 从函数签名层面避免不必要的修改
- 大对象慎重处理复制构造函数, 避免无意义复制
## 杂项
- 多写注释, 特别在较为抽象或者容易混淆的地方
- 用命名空间区分模块
- **不要在头文件使用```using namespace std;```**等using
- 可应用单元测试, 对纯逻辑/数据层面的操作进行测试
- 使用cmath时不要用"x1"变量名, 有特殊含义 *震撼我🐎*
// TODO: refactor using MazeLib to unify implement
#include <queue>

#include "class.cpp"
int width, height;//地图的长宽
int startx, starty, endx, endy;
vector<vector<int>> maze;//迷宫地图数据
vector<vector<int>> vis;//是否访问过和能否访问
vector<vector<int>> cost;//耗费 
queue<Point> openList;//访问表
ofstream out("D://answer.txt");
/// <summary>
/// 垂直(v)水平(h)的四个方向
/// </summary>
int vhDirections[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
/// <summary>
/// 斜向(slant)的四个方向
/// </summary>
int slantDirections[4][2] = { {1,1},{1,-1},{-1,1},{-1,-1} };
void readFile() {
    ifstream in("D:\\maze.txt");//地图数据地址
    in >> width>>height;
    maze.resize(width);
    vis.resize(width);
    cost.resize(width);
    for (int i = 0; i < width; i++)
    {
        maze[i].resize(height);
        vis[i].resize(height);
        cost[i].resize(height);
    }
    //vector 构造
  //  cout << width << " " << height << endl;
   
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            in >> maze[i][j];//读入每个格子的数据
            if (maze[i][j] == 4) {
                startx = i;
                starty = j;
            }
            else if (maze[i][j] == 8) {
                endx = i;
                endy = j;
            }
            else if (maze[i][j] == 1) {
                vis[i][j] = 5;
            }
        }
    } 
//    out << startx << " " << starty << endl;
//    out << endx << " " << endy << endl;
    in.close();//用完后关闭
}
void show() {
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            out << setw(2) << left<< vis[i][j];
        } 
        out <<"                 " ;
        for (int j = 0; j < height; j++)
        {
            out << setw(4) <<left<< cost[i][j];
        }
        out << endl;
    }
    out << endl;
}
/// <summary>
/// 等代价搜索
/// </summary>
void UCS() {
    int num = 0;
    openList.push(Point(startx, starty));//将开始节点加入
    int x_now = startx, y_now = starty;
    while (true) {
        num++;
        int cznum = 1;
        out << num << " ";
        int cost_now = 100000;
        if (openList.empty()) {
            out << "无效！";
            return;
        }
        int lenth = openList.size();
        for (int i = 0; i < lenth; i++)
        {
            Point point_now = openList.front();//取出
            openList.pop();//删除队列头
            if (point_now.x == endx && point_now.y == endy)//终点出现了！
            {
                x_now = point_now.x;
                y_now = point_now.y;
                cost_now = cost[x_now][y_now];
                openList.push(point_now);
                break;
            }
            else if (cost[point_now.x][point_now.y] < cost_now)
            {
                x_now = point_now.x;
                y_now = point_now.y;
                cost_now= cost[x_now][y_now];
            }
            openList.push(point_now);
        } 
        while (true) {
            Point point_now = openList.front();//取出
            openList.pop();//删除队列
            if (point_now.x == x_now && point_now.y == y_now)break;
            openList.push(point_now);
        }
        vis[x_now][y_now] = 3;//标记为使用过
        for (int i = 0; i < 4; i++) {//这里是上左下右
            int x_next = x_now + vhDirections[i][0], y_next = y_now + vhDirections[i][1];
            if (vis[x_next][y_next] != 5)//排除是墙
            {
                if (vis[x_next][y_next] == 1)//如果在队列里
                {
                    cznum++;
                }
                else if (vis[x_next][y_next] != 3)//不在队列里且没有使用过
                {
                    cznum++;
                }
            }
        }
        for (int i = 0; i < 4; i++) {//这里是上左下右（斜）
            int x_next = x_now + slantDirections[i][0], y_next = y_now + slantDirections[i][1];
            if (vis[x_next][y_now] == 5 && vis[x_now][y_next] == 5)continue;
            if (vis[x_next][y_next] != 5)
            {
                if (vis[x_next][y_next] == 1)//如果在队列里
                {
                    cznum++;
                }
                else if (vis[x_next][y_next] != 3)//不在队列里且没有使用过
                {
                    cznum++;
                }
            }
        }
        if (x_now == endx && y_now == endy) cznum = 1;
        out << cznum << endl;
        out << "vis  " << x_now << " " << y_now << " " << cost_now << " " << endl;
        if (x_now == endx && y_now == endy)
        {
            cout << "find it!" << endl;
            return;
        }
        for (int i = 0; i < 4; i++) {//这里是上左下右
            int x_next = x_now + vhDirections[i][0], y_next = y_now + vhDirections[i][1];
            if (vis[x_next][y_next] != 5)//排除是墙
            {
                if (vis[x_next][y_next] == 1)//如果在队列里
                {
                    cost[x_next][y_next] = min(cost[x_next][y_next],cost_now + 10);
                    out << "cost " << x_next << " " << y_next <<" "<<cost[x_next][y_next] << endl;
                }
                else if(vis[x_next][y_next]!=3)//不在队列里且没有使用过
                {
                    vis[x_next][y_next] = 1;
                    openList.push(Point(x_next,y_next));
                    cost[x_next][y_next] = cost_now + 10;
                    out << "add  " << x_next << " " << y_next <<" "<<cost[x_next][y_next] << endl;
                }
            }
        }
        for (int i = 0; i < 4; i++) {//这里是上左下右（斜）
            int x_next = x_now + slantDirections[i][0], y_next = y_now + slantDirections[i][1];
            if (vis[x_next][y_now] == 5 && vis[x_now][y_next] == 5)continue;
            if (vis[x_next][y_next] != 5)
            {
                if (vis[x_next][y_next] == 1)//如果在队列里
                {
                    cost[x_next][y_next] = min(cost[x_next][y_next], cost_now + 14);
                    out <<"cost "<<x_next << " " << y_next << " " << cost[x_next][y_next]<<endl;
                }
                else if(vis[x_next][y_next] != 3)//不在队列里且没有使用过
                {
                    vis[x_next][y_next] = 1;
                    openList.push(Point(x_next, y_next));
                    cost[x_next][y_next] = cost_now + 14;
                    out << "add  " << x_next << " " << y_next << " " << cost[x_next][y_next] << endl;
                }
            }
        }
//        show();
    }
}
int main()
{
    readFile();
    UCS();
    out.close();
   // cout << "Hello World!\n";
}
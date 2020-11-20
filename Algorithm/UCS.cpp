#include "UCS.h"

using namespace std;

namespace MazeCracker
{
	namespace Maze
	{
		void UCS::UCSImplement()
        {
            int num = 0;
            openList.push(entrancePos);//����ʼ�ڵ����
            int x_now = entrancePos.x, y_now = entrancePos.y;
            while (true)
            {
                num++;
                int cznum = 1;
                out << num << " ";
                int cost_now = 100000;
                if (openList.empty())
                {
                    out << "��Ч��";
                    return;
                }
                int lenth = openList.size();
                for (int i = 0; i < lenth; i++)
                {
                    auto point_now = openList.front();//ȡ��
                    openList.pop();//ɾ������ͷ
                    if (maze[point_now] == MazeState::Exit)//�յ�����ˣ�
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
                        cost_now = cost[x_now][y_now];
                    }
                    openList.push(point_now);
                }
                while (true)
                {
                    auto point_now = openList.front();//ȡ��
                    openList.pop();//ɾ������
                    if (point_now.x == x_now && point_now.y == y_now)break;
                    openList.push(point_now);
                }
                vis[x_now][y_now] = 3;//���Ϊʹ�ù�
                for (int i = 0; i < 4; i++)
                {
                	//��������������
                    int x_next = x_now + Vector2D::fourDirections[i].x, y_next = y_now + Vector2D::fourDirections[i].y;
                    if (vis[x_next][y_next] != 5)//�ų���ǽ
                    {
                        if (vis[x_next][y_next] == 1)//����ڶ�����
                        {
                            cznum++;
                        }
                        else if (vis[x_next][y_next] != 3)//���ڶ�������û��ʹ�ù�
                        {
                            cznum++;
                        }
                    }
                }
                for (int i = 0; i < 4; i++)
                {
                	//�������������ң�б��
                    int x_next = x_now + Vector2D::diagonalDirection[i].x, y_next = y_now + Vector2D::diagonalDirection[i].y;
                    if (vis[x_next][y_now] == 5 && vis[x_now][y_next] == 5)continue;
                    if (vis[x_next][y_next] != 5)
                    {
                        if (vis[x_next][y_next] == 1)//����ڶ�����
                        {
                            cznum++;
                        }
                        else if (vis[x_next][y_next] != 3)//���ڶ�������û��ʹ�ù�
                        {
                            cznum++;
                        }
                    }
                }
                if (maze[x_now][y_now] == MazeState::Exit) cznum = 1;
                out << cznum << endl;
                out << "vis  " << x_now << " " << y_now << " " << cost_now << " " << endl;
                if (maze[x_now][y_now] == MazeState::Exit)
                {
                    cout << "find it!" << endl;
                    isFinished = true;
                    return;
                }
                for (int i = 0; i < 4; i++)
                {
                    //��������������
                    int x_next = x_now + Vector2D::fourDirections[i].x, y_next = y_now + Vector2D::fourDirections[i].y;
                    if (vis[x_next][y_next] != 5)//�ų���ǽ
                    {
                        if (vis[x_next][y_next] == 1)//����ڶ�����
                        {
                            cost[x_next][y_next] = min(cost[x_next][y_next], cost_now + 10);
                            out << "cost " << x_next << " " << y_next << " " << cost[x_next][y_next] << endl;
                        }
                        else if (vis[x_next][y_next] != 3)//���ڶ�������û��ʹ�ù�
                        {
                            vis[x_next][y_next] = 1;
                            openList.push({ x_next, y_next });
                            cost[x_next][y_next] = cost_now + 10;
                            out << "add  " << x_next << " " << y_next << " " << cost[x_next][y_next] << endl;
                        }
                    }
                }
                for (int i = 0; i < 4; i++)
                {
                    //�������������ң�б��
                    int x_next = x_now + Vector2D::diagonalDirection[i].x, y_next = y_now + Vector2D::diagonalDirection[i].y;
                    if (vis[x_next][y_now] == 5 && vis[x_now][y_next] == 5)continue;
                    if (vis[x_next][y_next] != 5)
                    {
                        if (vis[x_next][y_next] == 1)//����ڶ�����
                        {
                            cost[x_next][y_next] = min(cost[x_next][y_next], cost_now + 14);
                            out << "cost " << x_next << " " << y_next << " " << cost[x_next][y_next] << endl;
                        }
                        else if (vis[x_next][y_next] != 3)//���ڶ�������û��ʹ�ù�
                        {
                            vis[x_next][y_next] = 1;
                            openList.push({ x_next, y_next });
                            cost[x_next][y_next] = cost_now + 14;
                            out << "add  " << x_next << " " << y_next << " " << cost[x_next][y_next] << endl;
                        }
                    }
                }
                //        show();
            }
            
        }

		UCS::UCS(const IMaze& maze, std::ostream& out) : maze(maze), out(out)
		{
			for(int i =0;i<maze.getWidth();i++)
			{
				cost.emplace_back(vector<int>());
				vis.emplace_back(vector<int>());
				for(int j=0;j<maze.getHeight();j++)
				{
					cost[i].emplace_back(0);
					vis[i].emplace_back(maze[i][j] == MazeState::Wall ? 5 : 0);
				}
			}
            isFinished = false;
		}

		void UCS::run(Vector2D entrancePos)
		{
            isFinished = false;
			this->entrancePos = entrancePos;
			UCSImplement();
		}

		bool UCS::finished()
		{
            return isFinished;
		}

		std::string UCS::searcherName() const
		{
			return "UCS";
		}
	}
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct node
{
    int x;
    int y;
} frontt,temp,parent[11][11];//用parent[i][j]存(i,j)的父节点即上一层
int path[4][2]= {0,1,0,-1,1,0,-1,0},mapp[10][10];
void bfs()
{
    queue <node> que;//bfs数据结构：队列queue
    frontt.x=0;
    frontt.y=0;
    que.push(frontt);
    while(!que.empty())
    {
        frontt=que.front();
        que.pop();
        if(frontt.x==4&&frontt.y==4)//最先到达最右下的就是最短路径,此时已经将(4,4)这一点的父节点以及父节点的父节点....都保存。记录了最短路径
            return;
        for(int i=0; i<4; i++)
        {
            temp.x=path[i][0]+frontt.x;
            temp.y=path[i][1]+frontt.y;
            if(temp.x>=0&&temp.x<5&&temp.y>=0&&temp.y<5&&mapp[temp.x][temp.y]==0)
            {
                parent[temp.x][temp.y].x=frontt.x;//记录temp点的父节点
                parent[temp.x][temp.y].y=frontt.y;
                que.push(temp);//将符合条件的temp点入队
                mapp[temp.x][temp.y]=1; //将已经走过的路标记,防止搜temp点时又搜回上一层...
            }
        }
    }
}
void print(int x,int y)//递归输出
{
    if(x==0&&y==0)
    {
        printf("(%d, %d)\n",x,y);
        return ;
    }
    else
    {
        print(parent[x][y].x,parent[x][y].y);
        printf("(%d, %d)\n",x,y);
    }
}
int main()
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
        {
            scanf("%d",&mapp[i][j]);
            //cin>>mapp[i][j];
        }
    bfs();
    print(4,4);
    return 0;
}

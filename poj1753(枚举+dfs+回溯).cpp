//全部翻转为同一个颜色叫"翻转完成"
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
bool mapp[8][8],flag=0;
int step,Move[5][2]={0,0,0,1,0,-1,1,0,-1,0};//注意第一种Move是不移动
void buildmapp()
{
    memset(mapp,0,sizeof(mapp));
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
    {
        char ch;
        cin>>ch;
        if(ch=='w')
            mapp[i][j]=1;
    }
}
void flip(int row,int col)
{
    for(int i=0;i<5;i++)
    {
        int r=row+Move[i][0],c=col+Move[i][1];
        if(r>=1&&r<=4&&c>=1&&c<=4)
            mapp[r][c]=!mapp[r][c];
    }
    return ;
}
bool check()//检查是否翻转完成
{
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
    {
        if(mapp[i][j]!=mapp[1][1])
            return false;
    }
    return true;
}
void dfs(int row,int col,int deep)//当前位置为(row,col),已经翻转过deep次
{
    if(step==deep)//判断当前这种翻转了step次的方式是否翻转完成
    {
        flag=check();
        return;
    }
    if(flag||row>4)//flag为1即已经翻转为同一时直接return,不需要进行以下的操作||row>4即搜出了最大行数4时,也return
        return ;
    flip(row,col);//将当前位置(以及周围)翻转
    if(col<4)  //判断是否超过最大列数
        dfs(row,col+1,deep+1);
    else
        dfs(row+1,1,deep+1);//换行
    flip(row,col);//既然会走到这一步,一定是前面的所有操作都没有实现翻转完成,将最开始翻转过的那个翻回去翻回去翻回去!

    //改变最开始翻转的位置
    if(col<4)
        dfs(row,col+1,deep);
    else
        dfs(row+1,1,deep);
}
int main()
{
    buildmapp();
    for(step=0;step<=16;step++)
    {
        dfs(1,1,0);//从(1,1)开始搜索
        if(flag)//判断在总翻转次数为step时能否将棋盘变成同一种颜色
            break;
    }
    if(flag)
        printf("%d\n",step);
    else
        printf("Impossible\n");
}

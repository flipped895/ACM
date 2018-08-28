
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
bool flag[1000101];
int n,k,ans;
struct aa
{
    int num;
    int step;
};
int bfs(aa x)
{
    if(x.num==k)
        return ans=0;
    aa y,temp;
    queue <aa> qu;
    qu.push(x);
    while(!qu.empty())
    {
        y=qu.front();
        temp=y;
        qu.pop();
        if(y.num+1!=k&&flag[y.num+1]&&y.num+1>0&&y.num+1<=100000)
        {
            temp.num=y.num+1;
            temp.step=y.step+1;
            qu.push(temp);
            flag[temp.num]=false;
        }
        if(y.num-1!=k&&flag[y.num-1]&&y.num-1>0&&y.num-1<=100000)
        {
            temp.num=y.num-1;
            temp.step=y.step+1;
            qu.push(temp);
            flag[temp.num]=false;
        }
        if(y.num*2!=k&&flag[y.num*2]&&y.num*2>0&&y.num*2<=100000)
        {
            temp.num=y.num*2;
            temp.step=y.step+1;
            qu.push(temp);
            flag[temp.num]=false;
        }
        if(y.num+1==k||y.num-1==k||y.num*2==k)
        {
            ans=y.step+1;
            return ans;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    aa b;
    memset(flag,1,sizeof(flag));
    b.num=n;b.step=0;
    bfs(b);
    printf("%d\n",ans);
    return 0;
}

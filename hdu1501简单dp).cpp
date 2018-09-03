#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int dp[222][222];//dp[i][j]表示
char str1[222],str2[222],str3[411];
int main()
{
    int t;
    scanf("%d",&t);
    for(int sett=1;sett<=t;sett++)
    {
        scanf("%s%s%s",str1+1,str2+1,str3+1);
        str1[0]=str2[0]=str3[0]='0';//如果没有strlen函数测不出长度!!! 表示A前 i 为 和B 前j 位是否可以组成 C的前i+j位
        memset(dp,0,sizeof(dp));
        int length1,length2;
        length1=strlen(str1)-1;
        length2=strlen(str2)-1;
        //printf("%d %d\n",length1,length2);
        for(int i=1;i<=length1;i++)
        {
            if(str1[i]==str3[i])    //初始化边界
                dp[i][0]=1;
        }
        for(int i=1;i<=length2;i++) //初始化边界
        {
            if(str2[i]==str3[i])
                dp[0][i]=1;
        }
        for(int i=1;i<=length1;i++)
            for(int j=1;j<=length2;j++)
        {
            if((dp[i-1][j]&&str1[i]==str3[i+j])||(dp[i][j-1]&&str2[j]==str3[i+j]))
                dp[i][j]=1;
        }
        if(dp[length1][length2])
            printf("Data set %d: yes\n",sett);
        else
            printf("Data set %d: no\n",sett);
    }
    return 0;
}

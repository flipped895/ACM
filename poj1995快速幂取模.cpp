//https://blog.csdn.net/ltyqljhwcm/article/details/53043646
//poj1995快速幂取模
#include <cstdio>
using namespace std;
typedef long long ll;
ll quick(ll a,ll b,ll c)//快速幂取模
{
    ll ans=1;
    a=a%c;
    while(b!=0)
    {
        if(b&1)//当最右一位是1时(二进制)
            ans=(ans*a)%c;
        b>>=1;//左移一位
        a=(a*a)%c;//(A(n+1)=A(n)*A(n))-----A(n)=(a^(bn*2^n))%c
    }
    return ans;
}
int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll m,h,ans=0,a;
        int b;
        scanf("%lld",&m);
        scanf("%lld",&h);
        for(int i=0;i<h;i++)
        {
            scanf("%lld%d",&a,&b);
            ans=(ans+quick(a,b,m))%m;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

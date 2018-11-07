#include<iostream>
#include<stdio.h>
#include<math.h>
#include <string>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#include<utility>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define eps 1e-8
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define rd(x) scanf("%d",&x)
#define rd2(x,y) scanf("%d%d",&x,&y)
#define ll long long int
#define mod 1000000007
#define maxn 200100
#define maxm 10001005
int n,m;
int pr[maxn],pn;
ll pow(ll a,int b){
    ll ans=1;
    while(b){
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m)){
        ll sum=pow(m,n);
        pn=0;
        int mm=m;
        for(int i=2;i*i<=mm;i++){//m的素因子
            if(!(mm%i)) pr[pn++]=i;
            while(mm%i==0) mm/=i;
        }
        if(mm!=1) pr[pn++]=mm;
 
        for(int i=1;i<(1<<pn);i++){//数位枚举所有奇偶素因子情况
            int k=1;
            ll kk=1;
            int nn=0;
            for(int j=0;j<pn;j++){
                if(k&i) {
                    kk*=pr[j];
                    nn++;
                }
                k<<=1;
            }
            if(nn%2) sum-=pow(m/kk,n);
            else sum+=pow(m/kk,n);
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
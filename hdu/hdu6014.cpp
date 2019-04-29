#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
const int N=31,Mod=1e9+7;
typedef long long ll;
ll x[N],y[N],A[N][N],p[N],nis[N],nip[N],C[N*N][N*N];
ll all[N*N],discon[N][N*N],con[N][N*N],tot[N][N*N];
ll edge[N][N*N];
ll w[N*N];
vector<int> V[N];
ll power(ll x,ll y){
    ll re=1;
    for (;y;y>>=1,x=x*x%Mod)
        if (y&1) re=re*x%Mod;
    return re;
}
ll ni(ll x){
    if (x==0) return 0;
    return power(x,Mod-2);
}

int Gauss(int n){
    for (int i=1;i<=n;i++){
        if (!A[i][i]){
            int r=i;
            for (int j=i+1;j<=n;j++) if (A[j][i]) r=j;
            for (int j=i;j<=n+1;j++) swap(A[i][j],A[r][j]);
        }
        ll x=power(A[i][i],Mod-2);
        for (int j=i;j<=n+1;j++)
            A[i][j]=A[i][j]*x%Mod;
        for (int j=1;j<=n;j++)
            if (i!=j&&A[j][i]){
                ll x=Mod-A[j][i];
                for (int k=i;k<=n+1;k++)
                    A[j][k]=(A[j][k]+x*A[i][k])%Mod;
            }
    }
    for (int i=1;i<=n;i++)
        x[i]=A[i][n+1]*ni(A[i][i]);
}

void Init(){
    for (int i=1;i<N;i++)
        for (int j=0;j<=i*(i-1)/2;j++) tot[i][j]=C[j][i*(i-1)/2];
   // puts("!!!!!");
    for (int n=1;n<N;n++){
        for (int m=0;m<=n*(n-1)/2;m++){
            if (n==1) discon[n][m]=con[n][m]=1;
            else{
                for (int k=1;k<n;k++)
                    for (int x=0;x<=min(k*(k-1)/2,m);x++){
                        //printf("%d %d %d %d\n",n,m,k,x);
                        discon[n][m]+=(C[k-1][n-1]*con[k][x]%Mod)*tot[n-k][m-x],
                        discon[n][m]%=Mod;
                    }
                con[n][m]=(tot[n][m]-discon[n][m]+Mod)%Mod;
            }
          //  printf("discon[%d][%d]=%lld  con[%d][%d]=%lld\n",n,m,discon[n][m],n,m,con[n][m]);
            for (int k=1;k<n;k++)
                for (int x=0;x<=min(k*(k-1)/2,m-1);x++)
                    edge[n][m]+=((C[k-1][n-1]*con[k][x])%Mod*con[n-k][m-1-x])%Mod*k*(n-k),
                    edge[n][m]%=Mod;
        }
    }
}

int main(){
 //   freopen("1.in","r",stdin);
 //   freopen("1.out","w",stdout);
    int T;
    for (int i=0;i<N*N;i++){
        C[0][i]=1;
        for (int j=1;j<=i;j++) C[j][i]=(C[j-1][i-1]+C[j][i-1])%Mod;
    }
    Init();
    for (scanf("%d",&T);T--;){
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%I64d",&p[i]),V[i].clear(),nip[i]=ni(p[i]);
        for (int x,i=1;i<=n;i++){
            y[i]=0;
            scanf("%d",&x);
            nis[i]=ni(x);
            for (int a;x--;){
                scanf("%d",&a);
                V[i].push_back(a);
            }
        }
        for (int k=n*(n-1)/2-1;k>=0;k--)
        if (discon[n][k]==0)
            for (int i=1;i<=n;i++) y[i]=Mod-1;
        else{
            memset(A,0,sizeof(A));
            ll P=((edge[n][k+1]*ni(n*(n-1)/2-k))%Mod*ni(discon[n][k]))%Mod;
       //     printf("%I64d %I64d\n",discon[n][k],edge[n][k+1]);
            for (int i=1;i<=n;i++){
                A[i][i]=Mod-1;
                A[i][n+1]=(1-p[i]*P)%Mod;
                A[i][n+1]+=Mod;
                A[i][n+1]%=Mod;
                for (auto t:V[i]){
                    ll add=A[i][t]=nis[i];
                    add=add*(y[t])%Mod;
                    add=add*(p[i])%Mod;
                    add=add*(Mod+1-P)%Mod;
              //     printf("add=%I64d\n",add);
                    A[i][n+1]+=add;
                    A[i][n+1]%=Mod;
                    A[i][t]=A[i][t]*(Mod+1-p[i])%Mod;
                }
                A[i][n+1]=(Mod-A[i][n+1])%Mod;
            }
            Gauss(n);
            swap(x,y);
        }
        printf("%I64d\n",y[1]);
    }
    return 0;
}

#include<cstdio>
using namespace std;
int n,a[10000],i,j,k;
int main (){
	while (~scanf("%d",&n))
	{
		a[0]=1; a[1]=1; 
		for (i=2;i<=n;i++){
			k=0;
			for (j=1;j<=a[0];j++){
				a[j]=a[j]*i+k;
				k=0; 
				if (a[j]>10000)
				{k=a[j]/10000;
				 a[j]%=10000;}
			}
			if (k>0){a[a[0]+1]=k;a[0]++;}
		}
		printf("%d",a[a[0]]);
		for (i=a[0]-1;i>=1;i--)printf("%04d",a[i]);
		printf("\n");
	}
	return 0;
}

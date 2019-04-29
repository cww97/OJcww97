/*
f[k][i]��ʾ��k��Сʱǰi���ж��ٸ�����
��i���ϰ벿�ֵ�ʱ�������Ǹ��Ƶ�k-1��״̬��ֻ�� *2����
�������¡����������������ϰ�����ȫ���ϣ��ټ���k-1ʱǰ��i-�ϰ����������е�����
c[k] = ��k��Сʱ��ɫ��������
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long LL;
using namespace std;
const int N=40000;
int i,k,a,b;
LL c[40];

LL f(int k,int i){
	if (i<=0)return 0;
	if (k==0)return 1;
	if (i<=(1<<(k-1)))return f(k-1,i)<<1;
	return c[k-1]*2+f(k-1,i-(1<<(k-1)));
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T;scanf("%d",&T);
	c[0]=1;for (int i=1;i<=31;i++)c[i]=c[i-1]*3;
	for (int cas=1;cas<=T;cas++){
		scanf("%d%d%d",&k,&a,&b);
		printf("Case %d: %lld\n",cas,f(k,b)-f(k,a-1));
	}
	return 0;
}

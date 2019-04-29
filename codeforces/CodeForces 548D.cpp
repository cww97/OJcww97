#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=233333;
struct node{
	int num,dep;
	node(int n,int d):num(n),dep(d){}
};
int n,ans[N],arr[N];
stack<node>s;
int main(){
	//freopen("fuck.in","r",stdin);
	for (;~scanf("%d",&n);){
		while(!s.empty())s.pop();
		memset(ans,0,sizeof(ans));
		arr[++n]=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
			int len=0;
			while (!s.empty()){
				node tp=s.top();
				if (tp.num<arr[i])break;
				len+=tp.dep;
				ans[len]=max(ans[len],tp.num);
				s.pop();
			}
			s.push(node(arr[i],len+1));
		}
		for (int i=n-1;i>=1;i--)ans[i]=max(ans[i],ans[i+1]);
		for (int i=1;i<n-1;i++)printf("%d ",ans[i]);
		printf("%d\n",ans[n-1]);
	}
	
	return 0;
}

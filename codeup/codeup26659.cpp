#include<set>
#include<cstdio>
#include<iostream>
using namespace std;
int n,ma,a[400];
int main(){
	//freopen("fuck.in","r",stdin);
	for(;~scanf("%d",&n);){
		set<int>s; ma=0;
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
			ma=max(ma,a[i]);
			if (s.find(a[i])==s.end())s.insert(a[i]);
		}
		int ans=0;
		set<int>f; f=s;
		for (set<int>::iterator it=s.begin();it!=s.end();it++){
			int w=*it,ww=w;
			for (int i=0;i<n;i++) if (a[i]==w)w*=2;
			ans++;
			if (f.find(w)!=f.end()){
				f.erase(w);ans--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

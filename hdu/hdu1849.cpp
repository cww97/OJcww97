#include<cstdio>
using namespace std;
int main(){
	int n,x;
	while (scanf("%d",&n)==1&&n){
		int ans=0;
		for (;n--;){
			scanf("%d",&x);
			ans ^= x;
		}
		puts(ans?"Rabbit Win!":"Grass Win!");
		
	}
	return 0;
} 

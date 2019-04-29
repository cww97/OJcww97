#include<cstdio>
#include<iostream>
using namespace std;
int n;
int main(){
	while (~scanf("%d",&n)){
		if (n<0)puts("Score is error!");
		else if (n<60)puts("E");
		else if (n<70)puts("D");
		else if (n<80)puts("C");
		else if (n<90)puts("B");
		else if (n<=100)puts("A");
		else puts("Score is error!");
	}
	return 0;
} 

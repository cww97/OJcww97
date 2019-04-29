#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int i;
	char a[100];
	while(gets(a)){
		for(i=0;i<strlen(a);++i){
            if(i==0)a[0]=a[0]-32;
			if(a[i]==' ')a[i+1]=a[i+1]-32;
			cout<<a[i];
		}
		puts("");
	}
}

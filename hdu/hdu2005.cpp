#include<cstdio>
#include<iostream>
using namespace std;
///                  1  2  3  4  5  6  7  8  9 10 11 12
const int day0[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int day1[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int x,y,z,ans;

inline void read(int &a,int &b,int &c){
	char ch; a=b=c=0;
	while(((ch=getchar())>='0')&&(ch<='9'))(a*=10)+=ch-'0';
	if (a==0)return;
	while(((ch=getchar())>='0')&&(ch<='9'))(b*=10)+=ch-'0';
	while(((ch=getchar())>='0')&&(ch<='9'))(c*=10)+=ch-'0';
}

bool RunNian(int x){
	if (x%100) return x%4==0;
	return x%400==0;
}

int main(){
	while (1){
		read(x,y,z);ans=0;
		if (!x)break;
		if (RunNian(x)){
			for (int i=1;i<y;i++)ans+=day1[i];
			printf("%d\n",ans+z);
		}else{
			for (int i=1;i<y;i++)ans+=day0[i];
			printf("%d\n",ans+z);
		}
	}
	return 0;
} 

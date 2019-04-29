#include<cstdio>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
int main(){
	string st;
	while (cin>>st){
		if (st.length()>10) puts("TAT");
		else {
            long long n=0;
            for (int i=0;i<st.length();i++){
                n = n*10 + (st[i]-'0');
            }
            //printf("n=%I64d\n",n);
            if (!n)puts("TAT");
            else {
                int ans=0;
                for (;n>1;ans++){
                    n= (long long)floor((sqrt(n)));
                }
                if (ans<6)printf("%d\n",ans);
                else puts("TAT");
            }
		}
	}
	return 0;
}

#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string st;

int main(){
	//freopen("fuck.in","r",stdin);
    for (;cin>>st&&st[0]!='0';){
        int sum=0,len=st.size();
        for(int i=0;i<len;i++){
            sum+=st[i]-'0';
            if(sum>9)sum=sum%10+sum/10;
        }
        printf("%d\n",sum);
    }
    return 0;
}

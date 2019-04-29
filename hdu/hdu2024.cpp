#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int i,j,n;
    char a[50];
    cin>>n;
    getchar();
    while(n--) {
    	gets(a);
        j=strlen(a);
        for(i=1;a[i]!='\0';i++){
            if(!(a[0]=='_'||(a[0]>='A'&&a[0]<='Z')||(a[0]>='a'&&a[0]<='z')))break;
            if(!(a[i]=='_'||(a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')||(a[i]>='0'&&a[i]<='9')))break;
    	}
		puts(i==j?"yes":"no");                            
    }	
}

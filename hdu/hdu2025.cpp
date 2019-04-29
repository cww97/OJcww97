#include <stdio.h>
#include <string.h>
int main(){
    int i,l;
    char str[100],ma;
    while(~scanf("%s",str)){
        l=strlen(str);
        ma=str[0];
        for(i=0;i<l;i++)if(str[i]>ma)ma=str[i]; 
        for(i=0;i<l;i++){
            putchar(str[i]);
            if(str[i]==ma)printf("(max)");
        }
        puts(""); 
    }
    return 0;
}

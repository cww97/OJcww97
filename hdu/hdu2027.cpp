#include <stdio.h>
int main(){
    int n;
    char x,enter;
    scanf("%d%c",&n,&enter);
    while (n--){
    	int a=0,e=0,i=0,o=0,u=0;
        while (scanf("%c",&x)!=EOF&&(x!='\n')){
            if (x=='a')  a++;
            if (x=='e')  e++;
            if (x=='i')  i++;
            if (x=='o')  o++;
            if (x=='u')  u++;
        }
        printf("a:%d\n",a);
        printf("e:%d\n",e);
        printf("i:%d\n",i);
        printf("o:%d\n",o);
        printf("u:%d\n",u);
        if(n)printf("\n");
    }
}

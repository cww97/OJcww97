/*
����:CWW970329
��Ŀ:p3085 ��ͬ�ĺ���λ
*/
#include <stdio.h>
int p,m,n;

int power(int x){
    int ans=1;
    int p1 = p % 1000;
    while(x>0){
        if (x&1) ans = (ans * p1) % 1000;
        x >>= 1;
        p1 = (p1 * p1) % 1000;
    }//������
    return ans;
}

int main(){
    scanf("%d",&p);
    for(m=2;;m++)
        for(n=1;n<m;n++)
            if(power(m)==power(n)){
                printf("%d %d",m,n);
                return 0;
        }
}

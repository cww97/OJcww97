#include <bits/stdc++.h>
using namespace std;
const int N = 222;
char st[N]; // ԭ�ַ���
char arr[N]; // �����е���ĸ��������
int n, A;

int main(){
    //freopen("in.txt", "r", stdin);
    int _;
    scanf("%d\n", &_);
    for (int cas = 0; cas < _; cas++){
        printf("case #%d:\n", cas);
        n = 0;  // �������ݣ���st��n����
        memset(st, 0, sizeof st);

        for (char ch = '0'; ch != '\n';){ // ��һ��
            scanf("%c", &ch);
            st[n++] = ch;
        }

        A = 0; // �õ�������ĸ
        for (int i = 0; i < strlen(st); i++){
            if (st[i] >= 'A' && st[i] <= 'Z'){
                arr[A++] = st[i];
            }
        }
        sort(arr, arr + A);  // ����

        int now = 0;
        for (int i = 0; i < strlen(st); i++){
            if (st[i] >= 'A' && st[i] <= 'Z'){
                printf("%c", arr[now++]);
            }else{
                printf("%c", st[i]);
            }
        }
    }
    return 0;
}

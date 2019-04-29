#include <map>
#include <cmath>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 333;

char st[N];

map<char, int> mp; // priority
void init(){
    mp['#'] = -1;
    mp['('] = 0;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
    mp[')'] = 4; // 单独处理
    // 基本符号???
    mp['^'] = 3;
}

bool isOperator(char ch){
    return ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^';
}
void printVec(vector <char> vec){
    for (int i = 0; i < vec.size(); i++){
        printf("%c ", vec[i]);
    }
    puts("");
}
vector<char> getInfix(char* st){
    vector <char> infix;  // 中缀表达式
    stack <char> op;
    op.push('#');
    for (int i = 0; i < strlen(st); i++){
        //printf("st[%d] = %c\n", i, st[i]);
        if (isdigit(st[i])){
            infix.push_back(st[i]);
        } else if (isOperator(st[i])){
            if (mp[st[i]] > mp[op.top()]){  // 优先级大于栈顶元素
                op.push(st[i]);
            }else{ // <=
                while (mp[st[i]] <= mp[op.top()]){
                    infix.push_back(op.top());
                    op.pop();
                }
                op.push(st[i]);
            }
        }else if (st[i] == '('){
            op.push(st[i]);
        }else { // ')'
            while (op.top() != '('){
                infix.push_back(op.top());
                op.pop();
            }
            op.pop();
        }
    }
    while (op.top() != '#'){
        infix.push_back(op.top());
        op.pop();
    }
    printVec(infix);
    return infix;
}

int calc(int x, int y, char op){
    if (op == '+') return y + x;
    if (op == '-') return y - x;
    if (op == '*') return y * x;
    if (op == '/') return y / x;
    return pow(y, x);
}
// 编译原理
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    init();
    scanf("%s", st);
    //printf("%s\n", st);
    vector <char> infix = getInfix(st);

    static int num[N], top;
    for (int i = 0; i < infix.size(); i++){
        if (isdigit(infix[i])){
            num[top++] = infix[i] - '0';
        }else { // operator
            int &x = num[--top];
            int &y = num[--top];
            int z = calc(x, y, infix[i]);
            //printf("= %dn", z);
            num[top++] = z;
            for (int j = 0; j < top; j++){
                printf("%d ", num[j]);
            }
            for (int j = i+1; j < infix.size(); j++){
                printf("%c%c", infix[j], j+1==infix.size()? '\n': ' ');
            }
        }
    }
    //printf("%dn", num[top]);
    return 0;
}

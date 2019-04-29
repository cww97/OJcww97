#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    //freopen("in.txt", "r", stdin);
    int s, v1, v2, t1, t2;
    for (;cin>> s >> v1 >> v2 >> t1 >> t2;){
        int time1 = s * v1 + t1 * 2;
        int time2 = s * v2 + t2 * 2;
        //printf("%d : %d\n", time1, time2);
        if (time1 < time2) puts("First");
        else if (time1 > time2) puts("Second");
        else puts("Friendship");
    }
    return 0;
}

#include <cstdio>
#include <iostream>
using namespace std;
const int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 39, 124, 514, 836, 1053, 4139, 12815, 61135, 104937, 792517, 1454698, 9679838, 17354310, 9735140, 1760750, 986050, 621360, 113815, 581437, 1252496, 7676706, 13019288, 94367798, 178067380 };

int main(){
    //freopen("in.txt", "r", stdin);
    int n;
    for (;cin >> n;){
        cout << arr[n] << endl;
    }
    return 0;
}
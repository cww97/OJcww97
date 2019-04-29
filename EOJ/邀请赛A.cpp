#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

string aList = "aāáǎà";
string eList = "eēéěè";
string iList = "iīíǐì";
string oList = "oōóǒò";
string uList = "uūúǔù";
string vList = "üǖǘǚǜ";

int main(){
	freopen("in.txt","r",stdin);
	int T;
	scanf("%d\n", &T);
	printf("t = %d\n", T);
	string st;
	

	for (int cas = 1; cas <= T; cas++){
		printf("Case %d: ", cas);
		cin >> st;
		cout << st << endl;
		int key = 0;
		//int len = strlen(st);
		int len = st.length();
		printf("len = %d\n",len);
		if ('1'<=st[len-1] && st[len-1]<='9'){
			key = st[len-1] - '0';
		}
		if (key > 0) st[len-1] = '\0',len--;
		bool ok = false;

		for (int i = 0; (i < len) && (!ok); i++){
			if (st[i] == 'a'){
				st[i] = aList[key];
				ok = 1;
			}
			else if (st[i] == 'e'){
				st[i] = eList[key];
				ok = 1;
			}
			else if (st[i] == 'o'){
				st[i] = eList[key];
				ok = 1;
			}
		}
		for (int i = 0; (i < len) && (!ok); i++){
			if (st[i] == 'u'){
				st[i] = uList[key];
				ok = 1;
			}
			else if (st[i] == 'v'){
				st[i] = vList[key];
				ok = 1;
			}
		}
		cout << st << endl;
	}
	return 0;
}
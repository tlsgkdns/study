#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string cmd, ans = "";
char ch;
int N, A, B, cnt = 0;
vector<int> T;
string txt[51];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	T.push_back(0); txt[0] = "";
	for (int i = 1; i <= N; i++)
	{
		cin >> cmd;
		if (cmd == "type")
		{
			cin >> ch >> A;
			T.push_back(A);
			ans.push_back(ch);
			txt[i] = ans;
		}
		else
		{
			cin >> A >> B;
			int idx = lower_bound(T.begin(), T.end(), B - A - 1) - T.begin();
			if (idx == T.size() || T[idx] != B - A - 1) --idx;
			ans = txt[idx];
			txt[i] = ans;
			T.push_back(B);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1360
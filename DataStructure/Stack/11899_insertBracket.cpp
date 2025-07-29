#include <iostream>
#include <stack>

using namespace std;
stack<bool> S;
string B;
int ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> B;
	for (int i = 0; i < B.size(); i++)
	{
		if (B[i] == '(')
		{
			S.push(1);
		}
		else
		{
			if (S.empty()) ++ans;
			else S.pop();
		}
	}
	ans += S.size();
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11899
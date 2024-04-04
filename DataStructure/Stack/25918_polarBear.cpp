#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

stack<char> st;
int N, ans = 0;
string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> S;
	for (int i = 0; i < S.size(); i++)
	{
		ans = max(ans, (int)st.size());
		if (!st.empty() && S[i] != st.top())
		{
			st.pop();
		}
		else
			st.push(S[i]);
	}
	if (!st.empty()) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/25918
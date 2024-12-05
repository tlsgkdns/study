#include <iostream>
#include <deque>

using namespace std;

deque<char> dq;
string S, ans = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	dq.push_back(S[0]);
	for (int i = 1; i < S.size(); i++)
		if (dq.front() < S[i])
			dq.push_back(S[i]);
		else
			dq.push_front(S[i]);
	for (int i = 0; i < dq.size(); i++) ans.push_back(dq[i]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1464
#include <iostream>
#include <stack>
using namespace std;

int N;
int A[1000001], cnt[1000001], ans[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		++cnt[A[i]];
	}
	stack<int> s;
	for (int i = N - 1; i >= 0; i--)
	{
		while (!s.empty() && cnt[A[i]] >= cnt[s.top()]) s.pop();
		if (s.empty()) ans[i] = -1;
		else ans[i] = s.top();
		s.push(A[i]);
	}
	for (int i = 0; i < N; i++) cout << ans[i] << " "; cout << '\n';
}

// https://www.acmicpc.net/problem/17298
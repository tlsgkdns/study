#include <iostream>
#include <stack>

using namespace std;

int N, P, A, B, ans = 0;
stack<int> S[6];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		--A;
		while (!S[A].empty() && S[A].top() > B)
		{
			S[A].pop();
			++ans;
		}
		if (S[A].empty() || S[A].top() != B)
		{
			S[A].push(B);
			++ans;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2841
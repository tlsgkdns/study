#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int A[101], N, ans = 0, cnt = 0;
priority_queue<int> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		q.push(A[i]);
	}

	while (q.size() > 1)
	{
		int a1 = q.top();
		q.pop();
		int a2 = q.top();
		q.pop();
		a1--; a2--;
		++ans;
		if (a1 > 0) q.push(a1);
		if (a2 > 0) q.push(a2);
	}
	if (!q.empty()) ans += q.top();
	if (ans > 1440) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/26215
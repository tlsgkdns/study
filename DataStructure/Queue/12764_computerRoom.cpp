#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> A;
int N, P, Q, ans[100001], L = 0;
priority_queue<int> C;
priority_queue<pair<int, int>> U;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P >> Q;
		A.push_back({ P, Q });
		C.push(-i);
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++)
	{
		while (!U.empty() && -U.top().first < A[i].first)
		{
			C.push(U.top().second);
			U.pop();
		}
		++ans[-C.top()];
		U.push({ -A[i].second, C.top() });
		C.pop();
	}
	while (ans[L++] > 0); --L;
	cout << L << '\n';
	for (int i = 0; i < L; i++) cout << ans[i] << " ";
}

// https://www.acmicpc.net/problem/12764
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr, A;
int N, M, E, cnt[10001];

void solve(int idx)
{
	if (idx == A.size()) return;
	if (arr.size() == M)
	{
		for (int i = 0; i < M; i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	arr.push_back(A[idx]);
	solve(idx);
	arr.pop_back();
	solve(idx + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> E;
		if (cnt[E]) continue;
		cnt[E] = true;
		A.push_back(E);

	}
	sort(A.begin(), A.end());
	solve(0);
}

// https://www.acmicpc.net/problem/15666
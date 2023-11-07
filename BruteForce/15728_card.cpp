#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> A;
int N, K, S[101], T[101], cnt = 0;
bool v[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> S[i];
	for (int i = 0; i < N; i++) cin >> T[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A.push_back({ -S[i] * T[j], j });
	sort(A.begin(), A.end());
	int i = 0;
	for (i = 0; i < A.size() && cnt <= K; i++)
	{
		if (v[A[i].second]) continue;
		v[A[i].second] = true;
		++cnt;
	}
	cout << -A[i - 1].first << '\n';
}

// https://www.acmicpc.net/problem/15728
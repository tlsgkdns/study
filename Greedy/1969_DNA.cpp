#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<char, int> um;
int N, M, cnt[51][4], s = 0;
string D[1001], ans = "", A = "ACGT";
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < A.size(); i++) um[A[i]] = i;
	for (int i = 0; i < N; i++) cin >> D[i];
	sort(D, D + N);
	for (int i = 0; i < N; i++)
		for (int idx = 0; idx < M; idx++)
			++cnt[idx][um[D[i][idx]]];
	for (int i = 0; i < M; i++)
	{
		int h = 0;
		for (int j = 1; j < A.size(); j++)
			if (cnt[i][j] > cnt[i][h])
				h = j;
		ans += A[h];
		s += (N - cnt[i][h]);
	}
	cout << ans << '\n' << s << '\n';
}

// https://www.acmicpc.net/problem/1969
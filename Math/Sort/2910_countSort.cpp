#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N, C;
int M[1001];
unordered_map<int, int> cnt, idx;
bool cmp(int a1, int a2)
{
	if (cnt[a1] == cnt[a2]) return idx[a1] < idx[a2];
	return cnt[a1] > cnt[a2];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> M[i];
		if (cnt.find(M[i]) == cnt.end()) idx[M[i]] = i;
		++cnt[M[i]];
	}
	sort(M, M + N, cmp);
	for (int i = 0; i < N; i++) cout << M[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/2910
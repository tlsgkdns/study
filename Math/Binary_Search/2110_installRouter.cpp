#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> A;
bool can(int len)
{
	int install = 0, limit = -1;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] < limit) continue;
		install++;
		limit = A[i] + len;
	}
	return C <= install;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int lo = 0, hi = 1000000001;
	cin >> N >> C;
	A.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	for (int it = 0; it <= 100; it++)
	{
		int mid = (lo + hi) / 2;
		if (can(mid)) lo = mid;
		else hi = mid;
	}
	cout << lo << '\n';
}
// https://www.acmicpc.net/problem/2110
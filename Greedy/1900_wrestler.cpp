#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> A;
int N, P, R;

bool cmp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
{
	return p1.second.first + p2.second.first * p1.second.second > p2.second.first + p1.second.first * p2.second.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> P >> R;
		A.push_back({ i, {P, R} });
	}
	sort(A.begin(), A.end(), cmp);
	for (int i = 0; i < N; i++) cout << A[i].first << '\n';
}

// https://www.acmicpc.net/problem/1900
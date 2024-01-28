#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<long long, int> um;
int N, ans = 0, cnt = 0;
long long C;
bool cmp(pair<long long, int> p1, pair<long long, int> p2)
{
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second > p2.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> C;
		++um[C];
	}
	vector<pair<long long, int>> arr;
	for (pair<long long, int> p : um)
		arr.push_back(p);
	sort(arr.begin(), arr.end(), cmp);
	cout << arr[0].first << '\n';
}

// https://www.acmicpc.net/problem/11652
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<pair<int, int>> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < N; i++)
		cout << arr[i].first << " " << arr[i].second << '\n';
}
// https://www.acmicpc.net/problem/11651
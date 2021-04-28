#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> apple;
int n, ans = 0;
int main()
{
	cin >> n;
	apple.resize(n);
	for (int i = 0; i < n; i++)
		cin >> apple[i].first >> apple[i].second;
	for (pair<int, int> a : apple)
		ans += a.second % a.first;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/10833
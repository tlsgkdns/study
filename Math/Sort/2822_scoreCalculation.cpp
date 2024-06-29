#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arr;
vector<int> ans;
int S, a = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 8; i++)
	{
		cin >> S;
		arr.push_back({ S, i });
	}
	sort(arr.begin(), arr.end());
	for (int i = 3; i < arr.size(); i++)
	{
		a += arr[i].first;
		ans.push_back(arr[i].second + 1);
	}
	sort(ans.begin(), ans.end());
	cout << a << '\n';
	for (int e : ans) cout << e << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/2822
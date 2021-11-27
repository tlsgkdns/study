#include <iostream>
#include <vector>

using namespace std;

int S, cnt = 0;

vector<vector<int>> anss;
vector<vector<vector<int>>> ansss;

void solve(vector<int>& arr, vector<int>& a, int idx)
{
	if (a.size() == 6)
	{
		anss.push_back(a);
		return;
	}
	if (idx == S) return;
	for (int i = idx; i < S; i++)
	{
		a.push_back(arr[i]);
		solve(arr, a, i + 1);
		a.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> S;
		if (S == 0) break;
		anss = vector<vector<int>>();
		vector<int> arr(S), emp;
		for (int i = 0; i < S; i++)
			cin >> arr[i];
		solve(arr, emp, 0);
		ansss.push_back(anss);
	}
	for (vector<vector<int>> vv : ansss)
	{
		for (vector<int> v : vv)
		{
			for (int e : v)
				cout << e << " ";
			cout << '\n';
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/6603
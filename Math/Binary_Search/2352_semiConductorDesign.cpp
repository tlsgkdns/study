#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s;
int arr[40001];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		auto iter = lower_bound(s.begin(), s.end(), arr[i]);
		if (iter == s.end()) s.push_back(arr[i]);
		else *iter = arr[i];
	}
	cout << (int)s.size() << '\n';
}

// https://www.acmicpc.net/problem/2352
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> arr;
int N, A, P[51];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		arr.push_back({ A, i });
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++) P[arr[i].second] = i;
	for (int i = 0; i < N; i++) cout << P[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/1015
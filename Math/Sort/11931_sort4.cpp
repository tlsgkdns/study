#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		arr[i] = -arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
		cout << -arr[i] << '\n';
}

// https://www.acmicpc.net/problem/11931
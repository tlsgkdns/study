#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long ans = 0;
int N, arr[500001], A;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)	ans += abs(arr[i] - i - 1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2012
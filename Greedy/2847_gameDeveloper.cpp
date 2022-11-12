#include <iostream>

using namespace std;

int arr[101], N, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = N - 2; i >= 0; i--)
		if (arr[i] >= arr[i + 1])
		{
			ans += (arr[i] - arr[i + 1] + 1);
			arr[i] = arr[i + 1] - 1;
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2847
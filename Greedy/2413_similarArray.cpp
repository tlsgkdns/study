#include <iostream>

using namespace std;

int arr[50001], dic[50001], N;
bool S[50001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dic[arr[i]] = i;
	}
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 1 || S[arr[i] - 1] || S[arr[i]] || dic[arr[i] - 1] < i) continue;
		S[arr[i] - 1] = true;
		S[arr[i]] = true;
		swap(arr[i], arr[dic[arr[i] - 1]]);
		dic[arr[i]] = dic[arr[i] - 1];
		dic[arr[i] - 1] = i;
	}
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/2413
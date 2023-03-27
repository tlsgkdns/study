#include <iostream>

using namespace std;

int N, M, arr1[1000001], arr2[1000001], idx1 = 0, idx2 = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr1[i];
	for (int i = 0; i < M; i++) cin >> arr2[i];
	while (idx1 < N && idx2 < M)
	{
		if (arr1[idx1] < arr2[idx2])
			cout << arr1[idx1++] << " ";
		else
			cout << arr2[idx2++] << " ";
	}
	if (idx1 == N)
		while (idx2 < M)
			cout << arr2[idx2++] << " ";
	if (idx2 == M)
		while (idx1 < N)
			cout << arr1[idx1++] << " ";
}

// https://www.acmicpc.net/problem/11728
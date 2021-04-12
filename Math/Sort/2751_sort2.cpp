#include <iostream>
#include <vector>
using namespace std;

vector<int> arr, big;
void mergeSort(int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	int i = left, j = mid + 1, pos = left;
	while (i <= mid && j <= right)
	{
		if (big[i] < big[j])
			arr[pos++] = big[i++];

		else
			arr[pos++] = big[j++];
	}
	int tmp = i > mid ? j : i;
	while (pos <= right) arr[pos++] = big[tmp++];
	for (int i = left; i <= right; i++) big[i] = arr[i];
}
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	arr.resize(n); big.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		big[i] = arr[i];
	}
	mergeSort(0, n - 1);
	for (int a : arr) cout << a << '\n';
}

// https://www.acmicpc.net/problem/2751

/*
To review sort algorithm, I coded quickSort at first.
But result was "Times out". So I tried mergeSort instead of it.
And it corrects.
*/
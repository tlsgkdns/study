#include <algorithm>
#include <iostream>
using namespace std;
int arr[3];
int main()
{
	for (int i = 0; i < 3; i++) cin >> arr[i];
	sort(arr, arr + 3);
	for (int i = 0; i < 3; i++) cout << arr[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/2752
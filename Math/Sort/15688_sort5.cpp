#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> arr;
int N, num;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++) cout << arr[i] << '\n';
}

// https://www.acmicpc.net/problem/15688
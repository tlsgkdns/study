#include <iostream>
#include <deque>
#include <vector>
using namespace std;

deque<pair<int, int>> dq;
vector<int> arr;
int N, L;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L; arr.resize(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		if (!dq.empty() && dq.front().second == i - L) dq.pop_front();
		while (!dq.empty() && dq.back().first > arr[i]) dq.pop_back();
		dq.push_back({ arr[i], i });
		cout << dq.front().first << " ";
	}
	cout << '\n';
}

// https://www.acmicpc.net/problem/11003
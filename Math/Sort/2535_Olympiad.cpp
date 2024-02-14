#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> arr;
int N, A, B, C, cnt[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> A >> B >> C;
		arr.push_back({ -C, {A, B} });
	}
	sort(arr.begin(), arr.end());
	for (int idx = 0, c = 0; idx < arr.size() && c < 3; idx++)
	{
		if (cnt[arr[idx].second.first] >= 2) continue;
		++c;
		cout << arr[idx].second.first << " " << arr[idx].second.second << '\n';
		++cnt[arr[idx].second.first];
	}
}

// https://www.acmicpc.net/problem/2535
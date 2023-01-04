#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, L, R, idx = 0;
vector<pair<int, int>> B, T;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> L >> R;
		T.push_back({ L, R });
	}
	sort(T.begin(), T.end());
	pair<int, int> pos = { 0, 0 };
	for (int i = 0; i < N; i++)
	{
		if (T[i].second <= pos.second) continue;
		if (pos.second < T[i].first)
		{
			B.push_back(pos);
			pos = T[i];
		}
		else pos.second = T[i].second;
	}
	B.push_back(pos);
	while (true)
	{
		pair<int, int> tmpPos = { -1, -1 };
		int tmpIdx = idx + 1, tmpIdx2 = idx;
		while (tmpIdx < (int)B.size() && B[tmpIdx].first <= 2 * B[idx].second - B[idx].first)
		{
			if (2 * B[tmpIdx].second - B[tmpIdx].first > 2 * tmpPos.second - tmpPos.first)
			{
				tmpIdx2 = tmpIdx;
				tmpPos = B[tmpIdx];
			}
			tmpIdx++;
		}
		if (tmpPos.first < 0) break;
		idx = tmpIdx2;
	}
	cout << B[idx].second << '\n';
}

// https://www.acmicpc.net/problem/24229
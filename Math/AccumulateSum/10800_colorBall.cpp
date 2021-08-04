#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int>> ball, info;
vector<int> ans, idxArr, idxPsum, cPsum, bulk, sortedBulk, bulkPsum;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.first == p2.first) return p1.second < p2.second;
	else return p1.first < p2.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	idxPsum.resize(N + 1, 0); cPsum.resize(N + 1, 0);
	ball.resize(N + 1); idxArr.resize(N + 1, 0); bulkPsum.resize(N + 1, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> ball[i].first >> ball[i].second;
		info.push_back(ball[i]);
		idxArr[ball[i].first]++;
	}
	sort(info.begin(), info.end(), cmp);
	for (auto in : info)
	{
		bulk.push_back(in.second);
		sortedBulk.push_back(in.second);
	}
	sort(sortedBulk.begin(), sortedBulk.end());
	for (int i = 1; i <= N; i++)
	{
		idxPsum[i] = idxPsum[i - 1] + idxArr[i];
		bulkPsum[i] = bulkPsum[i - 1] + sortedBulk[i - 1];
	}

	for (int i = 0; i < N; i++)
	{
		if (i == 0 || info[i].first != info[i - 1].first) cPsum[i] = info[i].second;
		else cPsum[i] = cPsum[i - 1] + info[i].second;
	}

	for (int i = 0; i < N; i++)
	{
		int l = idxPsum[ball[i].first - 1];
		int r = idxPsum[ball[i].first];
		int idx = lower_bound(sortedBulk.begin(), sortedBulk.end(), ball[i].second) - sortedBulk.begin();
		int k = lower_bound(bulk.begin() + l, bulk.begin() + r, ball[i].second) - bulk.begin();
		int a = (k == l) ? 0 : cPsum[k - 1];
		ans.push_back(bulkPsum[idx] - a);
	}
	for (int a : ans) cout << a << '\n';
}
// https://www.acmicpc.net/problem/10800
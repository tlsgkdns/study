#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
using pos = pair<int, int>;
using ll = long long;

int main(void)
{
	int n, m, k;
	cin >> n >> m;


	vector<vector<ll>> arr(n + 1, vector<ll>(m + 1));
	vector<vector<ll>> psum(n + 1, vector<ll>(m + 1, 0));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] + arr[i][j] - psum[i - 1][j - 1];
		}

	cin >> k;
	vector<pos> start(k);
	vector<pos> end(k);
	vector<ll> answer(k);

	for (int p = 0; p < k; p++)
		cin >> start[p].first >> start[p].second >> end[p].first >> end[p].second;

	for (int index = 0; index < k; index++)
	{
		int sf = start[index].first;
		int ss = start[index].second;
		int ef = end[index].first;
		int es = end[index].second;

		answer[index] = psum[ef][es] - psum[ef][ss - 1] - psum[sf - 1][es] + psum[sf - 1][ss - 1];
	}

	copy(answer.begin(), answer.end(), ostream_iterator <ll> {cout, "\n"});
	return 0;
}

// https://www.acmicpc.net/problem/2167

/*
you don't have to worry the border
if you allocate one more space
And I didn't think about that.
*/
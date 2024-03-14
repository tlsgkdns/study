#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
unordered_map<int, int> xIndex, yIndex;
vector<pair<pii, pii>> input;
int N, X, Y, W, H, P[50001];
vector<pair<pii, int>> xStart[50001], xEnd[50001], yStart[50001], yEnd[50001];
set<int> xSet, ySet;
ll S[50001], ans = 0;
int find(int u)
{
	if (u == P[u]) return P[u];
	return P[u] = find(P[u]);
}
void merge(int p, int q)
{
	p = find(p);
	q = find(q);
	if (p < q) swap(p, q);
	P[p] = q;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y >> W >> H;
		P[i] = i;
		xSet.insert(X); ySet.insert(Y);
		xSet.insert(W + X); ySet.insert(H + Y);
		input.push_back({ {X, Y}, {W + X, H + Y} });
	}
	vector<int> x(xSet.begin(), xSet.end()), y(ySet.begin(), ySet.end());
	for (int i = 0; i < x.size(); i++) xIndex[x[i]] = i;
	for (int i = 0; i < y.size(); i++) yIndex[y[i]] = i;
	for (int i = 0; i < N; i++)
	{
		xStart[xIndex[input[i].first.first]].push_back({ {input[i].first.second, input[i].second.second}, i });
		xEnd[xIndex[input[i].second.first]].push_back({ {input[i].first.second, input[i].second.second}, i });
		yStart[yIndex[input[i].first.second]].push_back({ {input[i].first.first, input[i].second.first}, i });;
		yEnd[yIndex[input[i].second.second]].push_back({ {input[i].first.first, input[i].second.first}, i });;
	}
	for (int i = 0; i < xSet.size(); i++)
	{
		sort(xStart[i].begin(), xStart[i].end());
		sort(xEnd[i].begin(), xEnd[i].end());
		int idxS = 0, idxE = 0;
		while (idxS < xStart[i].size() && idxE < xEnd[i].size())
		{
			if (xStart[i][idxS].first.first <= xEnd[i][idxE].first.first && xEnd[i][idxE].first.first <= xStart[i][idxS].first.second)
				merge(xStart[i][idxS].second, xEnd[i][idxE].second);
			if (xEnd[i][idxE].first.first <= xStart[i][idxS].first.first && xStart[i][idxS].first.first <= xEnd[i][idxE].first.second)
				merge(xStart[i][idxS].second, xEnd[i][idxE].second);
			if (xStart[i][idxS].first.second <= xEnd[i][idxE].first.second) ++idxS;
			else ++idxE;
		}
	}
	for (int i = 0; i < ySet.size(); i++)
	{
		sort(yStart[i].begin(), yStart[i].end());
		sort(yEnd[i].begin(), yEnd[i].end());
		int idxS = 0, idxE = 0;
		while (idxS < yStart[i].size() && idxE < yEnd[i].size())
		{
			if (yStart[i][idxS].first.first <= yEnd[i][idxE].first.first && yEnd[i][idxE].first.first <= yStart[i][idxS].first.second)
				merge(yStart[i][idxS].second, yEnd[i][idxE].second);
			if (yEnd[i][idxE].first.first <= yStart[i][idxS].first.first && yStart[i][idxS].first.first <= yEnd[i][idxE].first.second)
				merge(yStart[i][idxS].second, yEnd[i][idxE].second);
			if (yStart[i][idxS].first.second <= yEnd[i][idxE].first.second) ++idxS;
			else ++idxE;
		}
	}
	for (int i = 0; i < N; i++)
	{
		int idx = find(i);
		S[idx] += (ll)(input[i].second.first - input[i].first.first) * (ll)(input[i].second.second - input[i].first.second);
		ans = max(ans, S[idx]);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10534
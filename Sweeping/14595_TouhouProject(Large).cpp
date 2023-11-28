#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> A, B;
int N, M, X, Y, l = 0, r = 0, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		A.push_back({ X, Y });
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < M; i++)
	{
		if (r < A[i].first)
		{
			B.push_back({ l, r });
			l = A[i].first;
			r = A[i].second;
		}
		else if (A[i].second > r)
		{
			r = A[i].second;
		}
	}
	B.push_back({ l, r });
	for (int i = 1; i < B.size(); i++)
	{
		ans += B[i].first - B[i - 1].second - 1;
		++ans;
	}
	ans += N - B.back().second;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14595
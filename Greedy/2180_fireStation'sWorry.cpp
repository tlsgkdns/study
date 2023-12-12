#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<pii> F;
int N, A, B;
ll ans = 0;

bool cmp(pii p1, pii p2)
{
	if (p1.first == 0) return false;
	if (p2.first == 0) return true;
	return p1.second * p2.first < p1.first * p2.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		F.push_back({ A, B });
	}
	sort(F.begin(), F.end(), cmp);
	for (int i = 0; i < N; i++)
	{
		ans += ans * F[i].first + F[i].second;
		ans %= 40000;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2180
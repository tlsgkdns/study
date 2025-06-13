#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const int MAX = 1000001;
bool P[MAX];
vector<ll> prime;
int N;
ll S;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int n = 2; n < MAX; n++)
	{
		if (P[n]) continue;
		prime.push_back(n);
		for (int i = n + n; i < MAX; i += n)
			P[i] = true;
	}
	cin >> N;
	while (N--)
	{
		cin >> S;
		string ans = "YES\n";
		for (int i = 0; i < prime.size(); i++)
		{
			if (S % prime[i] == 0)
			{
				ans = "NO\n";
				break;
			}
		}
		cout << ans;
	}
}

// https://www.acmicpc.net/problem/1816
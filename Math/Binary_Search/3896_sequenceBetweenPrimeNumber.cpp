#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<int> p;

const int MAX = 1299710;
int T, K;
bool P[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(P, true, sizeof(P));
	cin >> T;
	for (int i = 2; i < MAX; i++)
	{
		if (P[i])
		{
			p.push_back(i);
			for (int j = i + i; j < MAX; j += i)
				P[j] = false;
		}
	}
	while (T--)
	{
		cin >> K;
		int l = 0, r = p.size() - 1;
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			if (p[m] > K) r = m;
			else l = m;
		}
		if (p[r] == K || p[l] == K) cout << 0 << '\n';
		else cout << p[r] - p[l] << '\n';
	}
}

// https://www.acmicpc.net/problem/3896
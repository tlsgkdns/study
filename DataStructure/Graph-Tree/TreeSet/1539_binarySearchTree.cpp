#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

set<int> T;
int P, N, H[250001];
long long ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P;
		if (i == 0)
		{
			H[P] = 1;
			T.insert(P);
		}
		else
		{
			auto iter = T.lower_bound(P);
			if (iter == T.begin())
				H[P] = H[*T.begin()] + 1;
			else if (iter == T.end())
			{
				--iter;
				H[P] = H[*iter] + 1;
			}
			else
			{
				H[P] = H[*iter] + 1; --iter;
				H[P] = max(H[P], H[*iter] + 1);
			}
			T.insert(iter, P);
		}
	}
	for (int i = 0; i < N; i++) ans += H[i];
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1539
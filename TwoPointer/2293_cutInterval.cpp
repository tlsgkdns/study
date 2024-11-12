#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000001;
int N, K, E[MAX], A, B, ans1 = 0, ans2 = 0, L[MAX], s = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		E[A]++;
		E[B]--;
	}
	for (int i = 0; i < MAX; i++)
	{
		s += E[i];
		L[i] = s;
	}
	int l = 0, r = 1; s = L[0];
	while (r < MAX)
	{
		if (s == K)
		{
			ans1 = l;
			ans2 = r;
			break;
		}
		else if (s > K)
		{
			while (l < r && s > K)
			{
				s -= L[l];
				++l;
			}
		}
		else
		{
			while (r < MAX && s < K)
			{
				s += L[r];
				++r;
			}
		}
	}
	cout << ans1 << " " << ans2 << '\n';
}

// https://www.acmicpc.net/problem/2283
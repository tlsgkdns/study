#include <cmath>
#include <iostream>
#include <set>
using namespace std;
int H[300001], N, A;
set<int> s;
long long ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if (i == 0)
		{
			H[A] = 0;
			s.insert(A);
			cout << 0 << '\n';
		}
		else
		{
			auto l = s.lower_bound(A);
			if (l == s.end()) H[A] = H[*(--l)] + 1;
			else if (l == s.begin()) H[A] = H[*l] + 1;
			else
			{
				H[A] = H[*l] + 1;
				H[A] = max(H[A], H[*(--l)] + 1);
			}
			ans += H[A];
			s.insert(A);
			cout << ans << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/2957
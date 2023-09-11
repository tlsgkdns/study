#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> prime;
int N, T;
bool P[1000003];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(P, true, sizeof(P));
	P[0] = P[1] = true;
	for (long long n = 2; n <= 1000001; n++)
	{
		if (!P[n]) continue;
		prime.push_back(n);
		for (long long num = n * n; num <= 1000001; num += n)
			P[num] = false;
	}
	cin >> T;
	while (T--)
	{
		cin >> N;
		int ans = 0;
		for (int i = 0; i < prime.size() && prime[i] <= (N / 2); i++)
			if (P[N - prime[i]])
				++ans;
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/17103
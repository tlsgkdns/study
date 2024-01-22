#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
long long ans1 = 0;
vector<int> P, D;
bool v[500001], isPrime[500001];
int ans2 = 0, ans3 = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(isPrime, true, sizeof(isPrime));
	cin >> N;
	for (int i = 3; i <= N; i++) ans1 += ((i - 1) / 2);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= N; i++)
		if (isPrime[i])
		{
			for (int j = i * i; j <= N; j += i)
				isPrime[j] = false;
		}
	for (int i = 2; i <= N; i++)
		if (isPrime[i])
			P.push_back(i);
	for (int n = 1; n + n <= N; n++)
		if (N % n == 0)
		{
			v[n] = true;
			D.push_back(n);
		}
	v[N] = true;
	for (int i = 0; i < D.size(); i++)
		for (int j = i; j < D.size(); j++)
			if (D[i] + D[j] <= N && v[D[i] + D[j]])
				++ans2;
	for (int i = 0; i < P.size(); i++)
		for (int j = i; j < P.size(); j++)
			if (P[i] + P[j] <= N && isPrime[P[i] + P[j]])
				++ans3;
	cout << ans1 << '\n' << ans2 << '\n' << ans3 << '\n';
}

// https://www.acmicpc.net/problem/1843
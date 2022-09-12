#include <iostream>
#include <cmath>
using namespace std;

string P;
int K, R = -1;
bool sieve[1000001];

int div(int num)
{
	int n = 0;
	for (int i = 0; i < P.size(); i++)
	{
		n *= 10;
		n += (P[i] - '0');
		n %= num;
	}
	return n;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> P >> K;
	sieve[0] = sieve[1] = true;
	for (int i = 2; i <= K; i++)
	{
		if (sieve[i]) continue;
		for (int j = i + i; j * j <= K; j += i)
			sieve[j] = true;
	}
	for (int i = 2; i < K; i++)
	{
		if (sieve[i]) continue;
		if (div(i) == 0)
		{
			R = i;
			break;
		}
	}
	if (R < 0) cout << "GOOD\n";
	else cout << "BAD " << R << '\n';
}

// https://www.acmicpc.net/problem/1837
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> prime(10000001, true);

int main(void)
{
	int k, cnt = 0;
	cin >> k;

	prime[0] = prime[1] = false;
	for (int i = 2; i < sqrt(prime.size()); i++)
	{
		if (prime[i])
			for (int j = i * i; j < prime.size(); j += i)
			{
				prime[j] = false;
			}
	}
	int ans = 0;
	for (int i = 0; i < prime.size(); i++)
		if (prime[i])
		{
			cnt++;
			if (cnt == k)
			{
				ans = i;
				break;
			}
		}

	cout << ans << endl;
}

// https://www.acmicpc.net/problem/15965
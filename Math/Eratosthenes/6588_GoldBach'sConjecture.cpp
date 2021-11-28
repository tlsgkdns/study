#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

bool prime[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(prime, true, sizeof(prime));
	for (int i = 2; i <= sqrt(1000001); i++)
		if (prime[i])
			for (int j = i * i; j < 1000001; j += i)
			{
				prime[j] = false;
			}
	int n;
	vector<int> l, r;
	while (true)
	{
		cin >> n;
		if (n == 0) break;
		for (int i = 2; i <= (n / 2); i++)
		{
			if (prime[i] && prime[n - i])
			{
				l.push_back(i);
				r.push_back(n - i);
				break;
			}
		}
	}
	for (int i = 0; i < l.size(); i++)
		cout << (l[i] + r[i]) << " = " << l[i] << " + " << r[i] << '\n';

}

// https://www.acmicpc.net/problem/6588
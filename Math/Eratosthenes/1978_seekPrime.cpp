#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int n, s = 0;
bool isPrime[1001];

int main()
{
	cin >> n;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= sqrt(1001); i++)
	{
		if (isPrime[i])
			for (int j = i * i; j < 1001; j += i)
				isPrime[j] = false;
	}
	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		if (isPrime[num]) s++;
	}
	cout << s << '\n';
}

// https://www.acmicpc.net/problem/1978
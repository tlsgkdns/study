#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = unsigned long long int;
const int MAX = 10000001;
bool P[MAX];
ll A, B, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	for (int i = 2; i * i <= MAX; i++)
	{
		if (P[i]) continue;
		for (int j = i * i; j <= MAX; j += i)
			P[j] = true;
	}
	for (ll n = 2; n <= MAX; n++)
		if (!P[n])
		{
			ll num = n * n;
			while (num <= B)
			{
				if (num >= A) ++ans;
				if ((B / n) < num) break;
				num *= n;
			}
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1456
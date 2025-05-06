#include <iostream>
#include <cmath>
using namespace std;

int sta, sto, b, cnt = 1;
int P[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 2; i <= 1000000; i++)
		for (int j = i + i; j <= 1000000; j += i)
			P[j] += i;
	while (true)
	{
		cin >> sta >> sto >> b;
		if (sta == 0 && sto == 0 && b == 0) break;
		int ans = 0;
		for (int s = sta; s <= sto; s++)
			ans += (abs(P[s] + 1 - s) <= b);
		cout << "Test " << cnt++ << ": " << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/9213
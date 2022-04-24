#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int A, P, ans = 0;
int v[250001], idx = 0;
int getNext(int num)
{
	int ret = 0;
	while (num > 0)
	{
		int n = num % 10;
		ret += pow(n, P);
		num /= 10;
	}
	return ret;
}

void dfs(int num)
{
	if (v[num] != -1)
	{
		ans = v[num];
		return;
	}
	v[num] = idx++;
	dfs(getNext(num));
}
int main()
{
	cin >> A >> P;
	memset(v, -1, sizeof(v));
	dfs(A);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2331
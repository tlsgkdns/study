#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cache[1001];

int tiling(int n)
{
	if (n == 0) return 1;
	if (n < 0) return 0;
	int& ret = cache[n];
	if (ret != -1) return ret;
	ret = (tiling(n - 1) + tiling(n - 2)) % 10007;

	return ret;
}
int main(void)
{
	int n;
	memset(cache, -1, sizeof(cache));
	cin >> n;

	int answer = tiling(n);

	cout << answer << endl;
	return 0;
}

// https://www.acmicpc.net/problem/11726
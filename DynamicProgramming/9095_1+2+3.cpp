#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int c[11];

int how(int n)
{
	if (n < 0) return 0;
	int& ret = c[n];
	if (ret != -1)	return ret;

	ret = how(n - 1) + how(n - 2) + how(n - 3);

	return ret;
}
int main(void)
{
	vector<int> input;
	int n, tmp;
	memset(c, -1, sizeof(c));
	c[0] = 1;
	c[1] = 1;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		input.push_back(tmp);
	}

	for (int e : input) cout << how(e) << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/9095
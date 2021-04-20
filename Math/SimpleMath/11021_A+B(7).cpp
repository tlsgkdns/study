#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;

	cin >> n;

	vector<int> answer(n);
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		answer[i] = a + b;
	}


	for (int c = 1; c <= n; c++)
		cout << "Case #" << c << ": " << answer[c - 1] << '\n';

	return 0;

}

// https://www.acmicpc.net/problem/11021
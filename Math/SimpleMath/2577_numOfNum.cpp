#include <iostream>
#include <vector>
using namespace std;
vector<int> num(10, 0);
int main()
{
	int a, b, c, m;
	cin >> a >> b >> c;
	m = a * b * c;
	while (m != 0)
	{
		num[m % 10]++;
		m /= 10;
	}
	for (int n : num) cout << n << '\n';
}

// https://www.acmicpc.net/problem/2577
#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
	vector<int> a, b;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ae, be;
		cin >> ae >> be;
		a.push_back(ae);
		b.push_back(be);
	}

	for (int j = 1; j <= n; j++)
		cout << "Case #" << j << ": " << a[j - 1] << " + " << b[j - 1] << " = " << a[j - 1] + b[j - 1] << '\n';
}

// https://www.acmicpc.net/problem/11022

/*
simple Problem
*/
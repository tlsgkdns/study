#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<bool> r;
	int a, b;
	do
	{
		bool f = false;
		cin >> a >> b;
		if (a > b) f = true;
		r.push_back(f);
	} while (a != 0 || b != 0);
	r.pop_back();
	for (bool a : r) (a) ? cout << "Yes" << '\n' : cout << "No" << '\n';
}

// https://www.acmicpc.net/problem/4101

/*
simple problem
*/
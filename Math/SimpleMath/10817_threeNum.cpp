#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> abc;
	abc.push_back(a);
	abc.push_back(b);
	abc.push_back(c);
	sort(abc.begin(), abc.end());
	cout << abc[1] << endl;

	return 0;
}

// https://www.acmicpc.net/problem/10817

/*
simple problem
*/
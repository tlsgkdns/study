#include <iostream>
#include <vector>
using namespace std;
vector<int> s;
int a, b;
int main()
{
	do
	{
		cin >> a >> b;
		s.push_back(a + b);

	} while (!cin.eof());
	s.pop_back();
	for (int sum : s) cout << sum << '\n';
}

// https://www.acmicpc.net/problem/10951
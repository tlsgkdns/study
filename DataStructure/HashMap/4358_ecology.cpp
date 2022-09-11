#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, double> um;
string str;
double N = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		getline(cin, str);
		if (cin.eof()) break;
		um[str]++;
		N++;
	}
	cout.precision(4);
	for (auto p : um)
		cout << fixed << p.first << " " << (p.second / N) * 100 << '\n';
}

// https://www.acmicpc.net/problem/4358
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s1, s2;

int main()
{
	cin >> s1 >> s2;
	swap(s1[0], s1[2]); swap(s2[0], s2[2]);
	cout << max(stoi(s1), stoi(s2)) << '\n';
}

// https://www.acmicpc.net/problem/2908
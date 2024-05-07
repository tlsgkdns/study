#include <iostream>

using namespace std;

int d[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, s = 0, M, D;
string m[7] = { "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday" };
int main()
{
	cin >> D >> M;
	for (int i = 0; i < M - 1; i++) s += d[i];
	s += (D - 1);
	cout << m[s % 7] << '\n';
}

// https://www.acmicpc.net/problem/2948
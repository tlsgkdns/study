#include <iostream>

using namespace std;

int X, Y, D = 0;
int M[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string date[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> X >> Y;
	for (int i = 0; i < X - 1; i++) D += M[i];
	D += Y; D %= 7;
	cout << date[D] << '\n';
}

// https://www.acmicpc.net/problem/1924
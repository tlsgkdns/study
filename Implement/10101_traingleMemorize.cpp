#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	if ((a + b + c) != 180) cout << "Error" << endl;
	else if (a == 60 && b == 60 && c == 60) cout << "Equilateral" << endl;
	else if (a == b || b == c || a == c) cout << "Isosceles" << endl;
	else cout << "Scalene" << endl;

}

// https://www.acmicpc.net/problem/10101
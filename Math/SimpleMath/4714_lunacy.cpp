#include <iostream>

using namespace std;
double X, Y;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> X;
		if (X < 0) break;
		Y = X * 0.167;
		cout << fixed; cout.precision(2);
		cout << "Objects weighing " << X << " on Earth will weigh " << Y << " on the moon." << '\n';
	}
}

// https://www.acmicpc.net/problem/4714
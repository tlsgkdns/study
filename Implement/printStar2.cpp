#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < n - i; j++) cout << ' ';
		for (int k = 0; k < i; k++) cout << '*';
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2439

/*
print star~~
*/
#include <iostream>

using namespace std;


int main(void)
{
	int n;
	cin >> n;

	if (n % 2 == 0) cout << "I LOVE CBNU" << endl;
	else
	{
		int c = (n / 2) + 1;
		for (int i = 0; i < n; i++)
			cout << "*";
		cout << '\n';
		for (int a = 0; a < c; a++)
		{
			for (int j = 0; j < c - a - 1; j++)
				cout << " ";
			if (a == 0) cout << "*";
			else
			{
				cout << "*";
				for (int s = 0; s < 2 * a - 1; s++)
					cout << " ";
				cout << "*";
			}

			cout << '\n';
		}
	}

	return 0;
}
// https://www.acmicpc.net/problem/14624

/*
	watch out the space
*/
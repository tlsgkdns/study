#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int n = 1; n <= N; n++)
	{
		cout << "Hello World, Judge " << n << "!\n";
	}
}

// https://www.acmicpc.net/problem/9316
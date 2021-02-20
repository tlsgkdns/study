#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<char> result = { 'F', 'D', 'C', 'B', 'A' };
	int n;
	cin >> n;
	int index = (n - 60 >= 0) ? (n == 100) ? 4 : (n - 50) / 10 : 0;

	cout << result[index] << endl;

	return 0;
}

// https://www.acmicpc.net/problem/9498

/*
just implement it
*/
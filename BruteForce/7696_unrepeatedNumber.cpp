#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> arr;
bool chk(int num)
{
	bool a[10] = { false };
	while (num > 0)
	{
		if (a[num % 10]) return false;
		a[num % 10] = true;
		num /= 10;
	}
	return true;
}
int main()
{
	int cnt = 0, n = 1;
	while (true)
	{
		if (chk(n)) arr.push_back(n);
		if (arr.size() == 1000000) break;
		++n;
	}
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		cout << arr[N - 1] << '\n';
	}
}

// https://www.acmicpc.net/problem/7696
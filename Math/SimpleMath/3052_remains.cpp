#include <iostream>
#include <vector>
using namespace std;

vector<bool> arr(43, false);
int main()
{
	int ans = 0, n;
	for (int i = 0; i < 10; i++)
	{
		cin >> n;
		if (arr[n % 42]) continue;
		arr[n % 42] = true;
		ans++;
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/3052
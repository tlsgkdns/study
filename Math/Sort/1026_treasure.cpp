#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, s = 0;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	for (int i = 0; i < n; i++) s += a[i] * b[i];
	cout << s << endl;
}

// problem: https://www.acmicpc.net/problem/1026
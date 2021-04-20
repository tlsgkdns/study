#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


int main(void)
{
	int n, x;
	string tmp;
	vector<int> a;
	cin >> n >> x;
	getline(cin, tmp);
	getline(cin, tmp);

	istringstream ss(tmp);
	string buf;
	while (getline(ss, buf, ' '))
		a.push_back(stoi(buf));

	for (int i = 0; i < n; i++)
		if (a[i] < x)
			cout << a[i] << ' ';

	return 0;
}

// https://www.acmicpc.net/problem/10871
#include <iostream>
#include <list>

using namespace std;

int main(void)
{
	int n, k;
	list<int> l;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) l.push_back(i);
	auto it = l.begin();
	cout << "<";
	while (true)
	{
		if (l.size() == 1) break;

		for (int a = 0; a < k - 1; a++)
		{
			if (it == l.end()) it = l.begin();
			it++;
			if (it == l.end()) it = l.begin();
		}
		cout << *it << ", ";
		it = l.erase(it);
	}

	cout << *l.begin() << ">\n";

	return 0;
}

// https://www.acmicpc.net/problem/1158
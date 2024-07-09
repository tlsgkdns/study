#include <iostream>
#include <vector>
#include <string>
using namespace std;
int C, V, T;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> C >> V;
		cout << "You get " << (C / V) << " piece(s) and your dad gets " << (C % V) << " piece(s).\n";
	}
}

// https://www.acmicpc.net/problem/10178
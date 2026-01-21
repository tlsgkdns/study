#include <iostream>
#include <string>

using namespace std;

string K;
int a[3], idx = 0;
string c = "";
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K;
	K.push_back('/');
	for (int i = 0; i < K.size(); i++)
	{
		if (K[i] == '/')
		{
			a[idx++] = stoi(c);
			c = "";
		}
		else
			c.push_back(K[i]);
	}
	if (a[0] + a[2] < a[1] || a[1] == 0) cout << "hasu\n";
	else cout << "gosu\n";
}

// https://www.acmicpc.net/problem/20499
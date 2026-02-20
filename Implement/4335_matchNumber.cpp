#include <string>
#include <iostream>
#include <vector>

using namespace std;

int N;
string C;
vector<int> h, l;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		getline(cin, C);
		getline(cin, C);
		if (C == "right on")
		{
			bool f = true;
			string ans = "Stan may be honest\n";
			for (int i = 0; i < l.size(); i++)
				if (l[i] >= N)
					f = false;
			for (int i = 0; i < h.size(); i++)
				if (h[i] <= N)
					f = false;
			if (f) cout << "Stan may be honest\n";
			else cout << "Stan is dishonest\n";
			h.clear(); l.clear();
		}
		if (C == "too low")
		{
			l.push_back(N);
		}
		if (C == "too high")
		{
			h.push_back(N);
		}
	}
}

// https://www.acmicpc.net/problem/4335
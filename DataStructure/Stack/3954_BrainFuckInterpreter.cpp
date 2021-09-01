#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int END = 50000000;
int T;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<pair<int, int>> ans;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		string prog, input;
		int sm, sc, si;
		cin >> sm >> sc >> si;
		cin >> prog;
		cin >> input;
		int cmdp = 0, arrp = 0, inpp = 0, cnt = 0;
		stack<int> brack;
		vector<int> bracketPair(sc + 1, -1);
		vector<unsigned char> arr(sm, 0);
		stack<pair<int, int>> loop;
		for (int i = 0; i < sc; i++)
		{
			if (prog[i] == '[') brack.push(i);
			if (prog[i] == ']')
			{
				bracketPair[i] = brack.top();
				bracketPair[brack.top()] = i;
				brack.pop();
			}
		}
		for (; cnt <= END; cnt++)
		{
			if (cmdp == sc) break;
			if (bracketPair[cmdp] == -1)
			{
				switch (prog[cmdp])
				{
				case '+':
					arr[arrp]++;
					break;
				case '-':
					arr[arrp]--;
					break;
				case '<':
					arrp = (arrp == 0) ? sm - 1 : arrp - 1;
					break;
				case '>':
					arrp = (arrp == sm - 1) ? 0 : arrp + 1;
					break;
				case ',':
					if (inpp >= si)
						arr[arrp] = 255;
					else
					{
						arr[arrp] = input[inpp];
						inpp++;
					}
					break;
				}
			}
			else if ((cmdp < bracketPair[cmdp] && arr[arrp] == 0) || (cmdp > bracketPair[cmdp] && arr[arrp] != 0))
				cmdp = bracketPair[cmdp];
			cmdp++;
		}
		if (cnt >= END && cmdp != sc)
		{
			int l = sc, r = -1;
			for (cnt = 0; cnt <= END; cnt++)
			{
				l = min(cmdp, l); r = max(cmdp, r);
				if (cmdp == sc) break;
				if (bracketPair[cmdp] == -1)
				{
					switch (prog[cmdp])
					{
					case '+':
						arr[arrp]++;
						break;
					case '-':
						arr[arrp]--;
						break;
					case '<':
						arrp = (arrp == 0) ? sm - 1 : arrp - 1;
						break;
					case '>':
						arrp = (arrp == sm - 1) ? 0 : arrp + 1;
						break;
					case ',':
						if (inpp >= si)
							arr[arrp] = 255;
						else
						{
							arr[arrp] = input[inpp];
							inpp++;
						}
						break;
					}
				}
				else if ((cmdp < bracketPair[cmdp] && arr[arrp] == 0) || (cmdp > bracketPair[cmdp] && arr[arrp] != 0))
					cmdp = bracketPair[cmdp];
				cmdp++;
			}
			ans.push_back({ l - 1, r });
		}
		else
			ans.push_back({ -1, -1 });
	}
	for (auto a : ans)
	{
		if (a.first < 0) cout << "Terminates\n";
		else cout << "Loops " << a.first << " " << a.second << '\n';
	}
}

// https://www.acmicpc.net/problem/3954
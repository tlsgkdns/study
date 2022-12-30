#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

const int ERR = 1000000001;
string cmd;
int N, V, X;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		vector<string> cmds;
		vector<int> nums;
		cin >> cmd;
		if (cmd == "QUIT") break;
		cmds.push_back(cmd);
		if (cmd == "NUM")
		{
			cin >> X;
			nums.push_back(X);
		}
		while (cmd != "END")
		{
			cin >> cmd;
			if (cmd == "END") break;
			if (cmd == "NUM")
			{
				cin >> X;
				nums.push_back(X);
			}
			cmds.push_back(cmd);
		}
		cin >> N;
		vector<int> ans;
		while (N--)
		{
			cin >> V;
			bool e = false; int idx = 0;
			stack<int> s;
			s.push(V);
			for (int i = 0; i < cmds.size(); i++)
			{
				if (cmds[i] == "NUM")
					s.push(nums[idx++]);
				else if (cmds[i] == "POP")
				{
					if (s.empty())
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					s.pop();
				}
				else if (cmds[i] == "INV")
				{
					if (s.empty())
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					s.top() = -s.top();
				}
				else if (cmds[i] == "DUP")
				{
					if (s.empty())
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					s.push(s.top());
				}
				else if (cmds[i] == "SWP")
				{
					if (s.size() < 2)
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					int tmp1 = s.top(), tmp2 = 0;
					s.pop();
					tmp2 = s.top();
					s.pop();
					s.push(tmp1);
					s.push(tmp2);
				}
				else if (cmds[i] == "ADD")
				{
					if (s.size() < 2)
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					int sm = s.top();
					s.pop();
					sm += s.top();
					s.pop();
					if (abs(sm) >= ERR)
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					s.push(sm);
				}
				else if (cmds[i] == "SUB")
				{
					if (s.size() < 2)
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					int sm = s.top();
					s.pop();
					sm -= s.top();
					sm = -sm;
					s.pop();
					if (abs(sm) >= ERR)
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					s.push(sm);
				}
				else if (cmds[i] == "MUL")
				{
					if (s.size() < 2)
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					long long sm = s.top();
					s.pop();
					sm *= s.top();
					s.pop();
					if (abs(sm) >= ERR)
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					s.push(sm);
				}
				else if (cmds[i] == "DIV")
				{
					if (s.size() < 2 || s.top() == 0)
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					int d1 = s.top(), d2 = 0;
					s.pop();
					d2 = s.top();
					s.pop();
					int d = abs(d2) / abs(d1);
					if ((d1 < 0 || d2 < 0) && !(d1 < 0 && d2 < 0))
						d = -d;
					if (abs(d) >= ERR)
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					s.push(d);
				}
				else if (cmds[i] == "MOD")
				{
					if (s.size() < 2 || s.top() == 0)
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					int d1 = s.top(), d2 = 0;
					s.pop();
					d2 = s.top();
					s.pop();
					int d = abs(d2) % abs(d1);
					if (d2 < 0) d = -d;
					if (abs(d) >= ERR)
					{
						ans.push_back(ERR);
						e = true;
						break;
					}
					s.push(d);
				}
			}
			if (s.size() == 1 && !e)
				ans.push_back(s.top());
			else if (!e)
				ans.push_back(ERR);
		}
		for (int a : ans)
		{
			if (a >= ERR) cout << "ERROR\n";
			else cout << a << '\n';
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/3425
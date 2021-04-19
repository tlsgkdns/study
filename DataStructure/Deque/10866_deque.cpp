#include <iostream>
#include <vector>
using namespace std;

struct Deque
{
	vector<int> arr;
	int size;
	Deque()
	{
		arr = vector<int>();
		size = 0;
	}
	void push_front(int x)
	{
		arr.insert(arr.begin(), x);
		size++;
	}
	void push_back(int x)
	{
		arr.push_back(x);
		size++;
	}
	int pop_front()
	{
		if (size == 0) return -1;
		int a = arr.front();
		arr.erase(arr.begin());	size--;
		return a;
	}
	int pop_back()
	{
		if (size == 0) return -1;
		int b = arr.back();
		arr.pop_back(); size--;
		return b;
	}
	int front()
	{
		if (size == 0) return -1;
		return arr.front();
	}
	int back()
	{
		if (size == 0) return -1;
		return arr.back();
	}
	int empty()
	{
		if (size == 0) return 1;
		return 0;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Deque dq;
	vector<int> ans;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "front")
			ans.push_back(dq.front());
		if (cmd == "back")
			ans.push_back(dq.back());
		if (cmd == "empty")
			ans.push_back(dq.empty());
		if (cmd == "size")
			ans.push_back(dq.size);
		if (cmd == "push_back")
		{
			int a; cin >> a;
			dq.push_back(a);
		}
		if (cmd == "push_front")
		{
			int a; cin >> a;
			dq.push_front(a);
		}
		if (cmd == "pop_back")
			ans.push_back(dq.pop_back());
		if (cmd == "pop_front")
			ans.push_back(dq.pop_front());
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/10866
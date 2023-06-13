#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
string str[7];
bool onlyLast(int r, int c)
{
	return str[r][c] == '.' && str[r][c + 1] == '.'
		&& str[r][c + 2] == '.' && str[r][c + 3] == '.' && str[r][c + 4] == 'x';
}
bool bothSide(int r, int c)
{
	return str[r][c] == 'x' && str[r][c + 1] == '.'
		&& str[r][c + 2] == '.' && str[r][c + 3] == '.' && str[r][c + 4] == 'x';
}
bool onlyFirst(int r, int c)
{
	return str[r][c] == 'x' && str[r][c + 1] == '.'
		&& str[r][c + 2] == '.' && str[r][c + 3] == '.' && str[r][c + 4] == '.';
}
bool full(int r, int c)
{
	return str[r][c] == 'x' && str[r][c + 1] == 'x'
		&& str[r][c + 2] == 'x' && str[r][c + 3] == 'x' && str[r][c + 4] == 'x';
}
bool isOne(int idx)
{
	for (int i = 0; i < 7; i++)
		if (!onlyLast(i, idx))
			return false;
	return true;
}
bool isTwo(int idx)
{
	return full(0, idx) && full(3, idx) && full(6, idx) &&
		onlyLast(1, idx) && onlyLast(2, idx) && onlyFirst(4, idx) && onlyFirst(5, idx);
}
bool isThree(int idx)
{
	return full(0, idx) && onlyLast(1, idx) && onlyLast(2, idx)
		&& full(3, idx) && onlyLast(4, idx) && onlyLast(5, idx) && full(6, idx);
}
bool isFour(int idx)
{
	return bothSide(0, idx) && bothSide(1, idx) && bothSide(2, idx) &&
		full(3, idx) && onlyLast(4, idx) && onlyLast(5, idx) && onlyLast(6, idx);
}
bool isFive(int idx)
{
	return full(0, idx) && onlyFirst(1, idx) && onlyFirst(2, idx)
		&& full(3, idx) && onlyLast(4, idx) && onlyLast(5, idx) && full(6, idx);
}
bool isSix(int idx)
{
	return full(0, idx) && onlyFirst(1, idx) && onlyFirst(2, idx)
		&& full(3, idx) && bothSide(4, idx) && bothSide(5, idx) && full(6, idx);
}
bool isSeven(int idx)
{
	if (!full(0, idx)) return false;
	for (int i = 1; i < 7; i++)
		if (!onlyLast(i, idx))
			return false;
	return true;
}
bool isEight(int idx)
{
	return full(0, idx) && bothSide(1, idx) && bothSide(2, idx)
		&& full(3, idx) && bothSide(4, idx) && bothSide(5, idx) && full(6, idx);
}
bool isNine(int idx)
{
	return full(0, idx) && bothSide(1, idx) && bothSide(2, idx)
		&& full(3, idx) && onlyLast(4, idx) && onlyLast(5, idx) && full(6, idx);
}
bool isZero(int idx)
{
	return full(0, idx) && bothSide(1, idx) && bothSide(2, idx)
		&& bothSide(3, idx) && bothSide(4, idx) && bothSide(5, idx) && full(6, idx);
}
void printFull()
{
	cout << "xxxxx";
}
void printBoth()
{
	cout << "x...x";
}
void printLast()
{
	cout << "....x";
}
void printFirst()
{
	cout << "x....";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 7; i++) cin >> str[i];
	N = str[0].size() - 5;
	int d = 1, s = 0, n = 0;
	for (int i = N; i >= 0; i -= 6)
	{
		int num = 0;
		if (isZero(i)) num = 0;
		else if (isOne(i)) num = 1;
		else if (isTwo(i)) num = 2;
		else if (isThree(i)) num = 3;
		else if (isFour(i)) num = 4;
		else if (isFive(i)) num = 5;
		else if (isSix(i)) num = 6;
		else if (isSeven(i)) num = 7;
		else if (isEight(i)) num = 8;
		else if (isNine(i)) num = 9;
		else
		{
			s += n;
			n = 0; d = 1;
			continue;
		}
		n += d * num;
		d *= 10;
	}
	s += n;
	string ans = to_string(s);
	for (int r = 0; r < 7; r++)
	{
		for (int c = 0; c < ans.size(); c++)
		{
			if (ans[c] == '0')
			{
				if (r == 0 || r == 6) printFull();
				else printBoth();
			}
			if (ans[c] == '1') printLast();
			if (ans[c] == '2')
			{
				if (r % 3 == 0) printFull();
				else if (r < 3) printLast();
				else printFirst();
			}
			if (ans[c] == '3')
			{
				if (r % 3 == 0) printFull();
				else printLast();
			}
			if (ans[c] == '4')
			{
				if (r < 3) printBoth();
				else if (r > 3) printLast();
				else printFull();
			}
			if (ans[c] == '5')
			{
				if (r % 3 == 0) printFull();
				else if (r < 3)	printFirst();
				else printLast();
			}
			if (ans[c] == '6')
			{
				if (r % 3 == 0) printFull();
				else if (r < 3)	printFirst();
				else printBoth();
			}
			if (ans[c] == '7')
			{
				if (r == 0) printFull();
				else printLast();
			}
			if (ans[c] == '8')
			{
				if (r % 3 == 0) printFull();
				else printBoth();
			}
			if (ans[c] == '9')
			{
				if (r % 3 == 0)printFull();
				else if (r < 3) printBoth();
				else printLast();
			}
			if (c != ans.size() - 1) cout << ".";
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/11613
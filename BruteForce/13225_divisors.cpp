#include <iostream>
int C, N, A; int main() { std::cin >> C; while (C--) { std::cin >> N; A = 0; for (int i = N; i; i--)A += !(N % i); std::cout << N << ' ' << A << '\n'; } }

// https://www.acmicpc.net/problem/13225
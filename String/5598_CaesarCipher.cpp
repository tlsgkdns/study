#include <iostream>
#include <algorithm>
std::string C; int main() { std::cin >> C; transform(C.begin(), C.end(), C.begin(), [](char c) {return((c - 'A' + 23) % 26 + 'A'); }); std::cout << C; }

// https://www.acmicpc.net/problem/5598
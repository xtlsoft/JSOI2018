/*
根结点
左：i 个结点（0, 1, ..., n - 1）
右：n - 1 - i 个结点

F0 = 1
F1 = 1
F2 = F0 * F1 + F1 * F0 = 1 * 1 + 1 * 1 = 2
F3 = F0 * F2 + F1 * F1 + F2 * F0 = 1 * 2 + 1 * 1 + 2 * 1 = 5
Fn = F0 * Fn - 1 + F1 * Fn - 2 ...... +Fn - 2 * F1 + Fn - 1 * F0
*/

#include <iostream>

using namespace std;

int main() {



}
/*
已知先序和中序遍历的结果，请你输出二叉树的后序遍历的结果。

get_result.in
ABDEGKHCFI
DBKGEHAFIC

get_result.out


思路：找先序遍历第一个为根节点，然后在中序中一分为二，判断出左右子树的长度，然后递归遍历左右子树。

*/

#include <iostream>
#include <string>

using namespace std;

string s1, s2;

void doTask(int left1, int right1, int left2, int right2) {
    int middle;
    middle = s2.find(s1[left1]);
    if(middle > left2) doTask(left1 + 1, left1 + middle - left2, left2, middle - 1);
    if(middle < right2) doTask(left1 + middle - left2 + 1, right1, middle + 1, right2);
    cout << s1[left1];
}

int main () {

    cin >> s1 >> s2;

    doTask(0, s1.length() - 1, 0, s2.length() - 1);

    return 0;

}
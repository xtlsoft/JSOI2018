// Copied from http://net.pku.edu.cn/~yhf/UsingSTL.htm
#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define SIZE 100
int iarray[SIZE];
 
int main()
{
  iarray[20] = 50;
  int* ip = find(iarray, iarray + SIZE, 50);
  cout << ip << " " << (iarray+SIZE) << endl;
  if (ip == iarray + SIZE)
    cout << "50 not found in array" << endl;
  else
    cout << *ip << " found in array" << endl;
  return 0;
}
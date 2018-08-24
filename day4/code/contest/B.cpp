#include <iostream>
#include <cmath>

using namespace std;

int getDepth(long long id) {

    return floor(log2(id)) + 1;

}

long long getFullNodes(int depth) {
    return (pow(2, depth) - 1);
}

long long getEndNode(long long start, int depth) {
    
    long long rslt = start;

    for (int i = 1; i < depth; ++ i) {
        rslt *= 2;
        rslt += 1;
    }

    return rslt;

}

long long getStartNode(long long start, int depth) {

    long long rslt = start;

    for (int i = 1; i < depth; ++ i) {
        rslt *= 2;
    }

    return rslt;

}

int main() {

    int m, n;

    cin >> m >> n;

    int fullDepth = getDepth(n);
    int tinyDepth = getDepth(m);

    int rsltDepth = fullDepth - tinyDepth + 1;

    long long endNode = getEndNode(m, rsltDepth);
    long long startNode = getStartNode(m, rsltDepth);
    
    long long deltaNodes;
    
    if (startNode > n) {
        deltaNodes = endNode - startNode + 1;
    } else {
        if (endNode > n) {
            deltaNodes = endNode - n;
        } else {
            deltaNodes = 0;
        }
    }

    long long rsltNodes = getFullNodes(rsltDepth);

    long long rslt = rsltNodes - deltaNodes;

    std::cout << rslt << endl;

    return 0;

}
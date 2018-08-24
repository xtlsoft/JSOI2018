#include <iostream>
#include <cstring>

using namespace std;

int mp[4] = {'+', '-', '*'};

int d, data[52];

int count = 0;

int curr[200], ptr = 0, ptr2 = 0;

int calcTmp[200];

int calc() {
    
    memset(calcTmp, 0, sizeof(calcTmp));

    int ta;
    int tmpCount = 0;

    for (int i = 1; i < ptr; i += 2) {
        switch (curr[i]) {
            case '+':
                calcTmp[tmpCount++] = curr[i - 1];
                calcTmp[tmpCount++] = curr[i + 1];
                break;
            case '-':
                calcTmp[tmpCount++] = 0 - curr[i - 1];
                calcTmp[tmpCount++] = 0 - curr[i + 1];
                break;
            case '*':
                tmpCount--;
                ta = curr[i - 1] * curr[i + 1];
                if(calcTmp[tmpCount] < 0) ta = -ta;
                calcTmp[tmpCount++] = ta;
                break;
            // case '/':
            //     if (curr[i + 1] == 0) return 0;
            //     tmpCount--;
            //     ta = curr[i - 1] / curr[i + 1];
            //     if(calcTmp[tmpCount] < 0) ta = -ta;
            //     calcTmp[tmpCount++] = ta;
        }
    }

    int rslt = 0;

    for (int i = 0; i < tmpCount; ++ i) {

        rslt += calcTmp[i];

    }

    return rslt;

}

int dfs(int depth) {

    if (depth == d) {

        if (calc() == 24) {
            ++count;
        }

    } else for (int i = 0; i < 3; ++ i) {
        curr[ptr ++] = mp[i];
        curr[ptr ++] = data[ptr2 ++];
        dfs(depth + 1);
        ptr --;
        ptr --;
        ptr2 --;
    }

}

int main() {

    cin >> d;

    for (int i = 0; i < d; ++ i) {
        cin >> data[i];
    }

    curr[ptr ++] = data[ptr2 ++];
    dfs(0);

    cout << ( count / 2 );

    return 0;

}
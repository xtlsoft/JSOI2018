<?php

echo <<<EOF
#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    
    switch(n){
EOF;

for ($i = 0; $i <= 75; ++$i) {
    $rslt = shell_exec(".\D_right.exe $i");
    echo <<<EOF

        case $i:
            cout << $rslt;
            break;

EOF;
}

echo <<<EOF
    }
    return 0;
}
EOF;


#include <iostream>
#include <cmath>

using namespace std;

typedef/**/int/**/String;

String Fa(int FA) {

    return floor(FA);

}

typedef/**/long/**/long/**/Char;

String Fi1(Char id) {

    return Fa(log2(id)) + 1;

}

typedef/**/void/**/Int;

Char FI1(String depth) {
    return (pow(2, depth) - 1);
}

Char F1i(Char bS, String bs) {
    
    Char Bs = bS;

    for (String i = 1; i < bs; ++ i) {
        Bs *= 2;
        Bs += 1;
    }

    return Bs;

}

Char F1I(Char cS, String cs) {

    Char Cs = cS;

    for (String i = 1; i < cs; ++ i) {
        Cs *= 2;
    }

    return Cs;

}

Int DoT() {

    String m, n;

    cin >> m >> n;

    String aI1 = Fi1(n);
    String a11 = Fi1(m);

    String a1I = aI1 - a11 + 1;

    Char eN = F1i(m, a1I);
    Char SN = F1I(m, a1I);
    
    Char A1I;
    
    if (SN > n) {
        A1I = eN - SN + 1;
    } else {
        if (eN > n) {
            A1I = eN - n;
        } else {
            A1I = 0;
        }
    }

    Char R01 = FI1(a1I);

    Char RO1 = R01 - A1I;

    std::cout << RO1 << endl;

}

String main() {

    DoT();

    return 0;

}
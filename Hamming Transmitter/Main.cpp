

#include <iostream>

using namespace std;

bool hCode[7];
//bool* h = hCode;

void setToBool(int, bool*, int);
void setDataBits(int, bool*);
void setMemBits(bool*);
int sTot(bool, bool, bool);
bool* sVal(int, bool*, int);
void displayCode(bool*);

int main() {
    int num;

    cout << "\tHamming Transmitter\n\n";
    cout << "Enter decimal number to be transmitted:  ";
    cin >> num;
    setDataBits(num, hCode);
    setMemBits(hCode);
    cout << "\nAssociated Hamming Code: ";
    displayCode(hCode);

}

//void getHCode() {}
void setDataBits(int n, bool* b) {
    int temp[4];
    for (int i = 0; n > 0; i++) {
        temp[i] = n % 2;
        n = n / 2;
    }
    setToBool(temp[0], b, 6);
    setToBool(temp[1], b, 5);
    setToBool(temp[2], b, 4);
    setToBool(temp[3], b, 2);

}
void setToBool(int i2b, bool* b, int loc) {
    if (i2b == 1) {
        b[loc] = true;
    }
    else {
        b[loc] = false;
    }
}

void setMemBits(bool* h) {
    int s1, s2, s4;

    s1 = sTot(h[2], h[4], h[6]);
    sVal(s1, h, 0);
    s2 = sTot(h[2], h[5], h[6]);
    sVal(s2, h, 1);
    s4 = sTot(h[4], h[5], h[6]);
    sVal(s4, h, 3);

}
int sTot(bool l1, bool l2, bool l3) {
    int value = 0;
    if (l1 == true)
        value += 1;
    if (l2 == true)
        value += 1;
    if (l3 == true)
        value += 1;

    return value;
}
bool* sVal(int s, bool* h, int loc) {
    if (s % 2 == 0)
        h[loc] = 0;
    else
        h[loc] = 1;

    return h;
}

void displayCode(bool* h) {
    for (int i = 0; i < 7; i++) {
        cout << h[i];
    }
    cout << endl;
}
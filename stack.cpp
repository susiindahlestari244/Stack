#include<iostream>
#include<conio.h>
using namespace std;

int main (){
    int a, b, c;

    cout << "menentukan nilai terbesar 3 buah input \n";
    cout << "masukkan nilai 1 : "; cin >> a;
    cout << "masukkan nilai 2 : "; cin >> b;
    cout << "masukkan nilai 3 : "; cin >> c;

    if ( (a > b )&& (a > c )){

        cout << "nilai terbesar   : " << a << endl;

    } else if ((b > a) && (b > c ))
        cout << "nilai terbesar   : " << b << endl;
    else
        cout << "nilai terbesar   : " << c << endl;

    getch();
}

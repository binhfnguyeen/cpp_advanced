#include <iostream>
using namespace std;
struct Phong{
    int i;
    long double k;
    double d;
    char c;
};
int main(){
    Phong p;
    cout << "byte cua long double " << sizeof(long double) << endl;
    cout << "byte cua int " << sizeof(int) << endl;
    cout << "byte cua long " << sizeof(long) << endl;
    cout << "byte cua double " << sizeof(double) << endl;
    cout << sizeof(p);

}
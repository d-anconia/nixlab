#include <iostream>
#include "Complex.cpp"


using namespace std;

int main(int argc, const char * argv[]) {

    Complex number(2,3);
    Complex number2(3,3);
    Complex number3 = number + number2;
    Complex number4 = number + 12;

    cout<< number4<<endl;

    return 0;
}

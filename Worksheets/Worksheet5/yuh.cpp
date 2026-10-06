#include <iostream>
#include <memory>
using namespace std;
int main(void){
    int x = 1;
    shared_ptr<int> a = make_shared<int>();
    *a = 15;
    shared_ptr<int> b = a;
    for (int i = 0; i < 3; i++){
        unique_ptr<int> u1 = make_unique<int>(4);
        *b = i+1;
        shared_ptr<int>c = make_shared<int>(i);
        a = c;
        //Diagram here
    }
    cout << "*a = " << *a << "\n";
    cout << "*b = " << *b << "\n";
    // cout << "*u1 = " << *u1 << "\n";
}
#include <iostream>

using namespace std;

int main(){
    cout<<"Hello world\n";
    cin.get();

    //enter a number
    int number;
    cout<<"Enter a number";
    cin>> number;
    cin.ignore();
    cout<<"You have enter : "<< number << "\n";
    cin.get();
    return 1;
}
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int speed;
    cout << "input your speed" << endl;
    cin >> speed;
    if (speed > 100) {
        if (speed > 130) {
            cout << "you are really speeding!!!" << endl;
        }
        else {
            cout << "you are speeding" << endl;
        }
    }
    else {
        cout << "good!" << endl;
    }
    return 0;
}

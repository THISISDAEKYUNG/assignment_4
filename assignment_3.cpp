#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void draw1(int height);
void draw2(int height);
void draw3(int height);
void draw4(int height);
int Fn1(int num);
int Fn2(int num);

int main() {
  int shape, height;
  cin>>shape>>height;
  switch (shape){
    case 1:
      draw1(height);
      break;
    case 2:
      draw2(height);
      break;
    case 3:
      draw3(height);
      break;
    case 4:
      draw4(height);
      break;
  }
}

//your code starts here (function definition : draw1, draw2, draw3, draw4)
void draw1(int height) {
    int width = height * 2;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void draw2(int height) {
    int width = height * 2;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j + 1 >= (width / 2) - i && j + 1 <= (width / 2) + i + 1) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void draw3(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height; j++) {
            if (j == i) {
                if (Fn1(i + 1) < 10) {
                    cout << Fn1(i + 1) << "*";
                }
                else {
                    cout  << Fn1(i + 1);
                }
            }
            else {
                cout << "**";
            }
        }
        cout << endl;
    }
}

void draw4(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height; j++) {
            if (j == i) {
                if (Fn2(i + 1) < 10) {
                    cout << Fn2(i + 1) << "*";
                }
                else {
                    cout  << Fn2(i + 1);
                }
            }
            else {
                cout << "**";
            }
        }
        cout << endl;
    }
}



int Fn1(int num) {
    int result = 0;
    for (int i = 0; i < num; i++) {
        result += i + 1;
    }
    return result;
}

int Fn2(int num) {
    int a = 1;
    int b = 1;
    int c = 0;
    int result;
    if (num == 1 || num == 2) {
        result = 1;
    }
    else {
        for (int i = 0; i < num - 2; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        result = c;
    }
    return result;
}



//your code ends here
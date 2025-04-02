#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;

class Device {
public:
  void set_resistance(double r);
  void set_price(int p);
  double get_resistance();
  int get_price();
  Device serial_connect(Device right);
  Device parallel_connect(Device right);
  void print_out(double v);

private:
  double resistance;
  int price;
};

void get_input(Device &D) {
  double resistance;
  int price;

  cout << "Enter the resistance of object :" << endl;
  cin >> resistance;
  D.set_resistance(resistance);

  cout << "Enter the price of object :" << endl;
  cin >> price;

  D.set_price(price);
}

Device connect(Device A, Device B) {
  Device AB;
  char choice;

  cin >> choice;

  switch (choice) {
  case 's':
    AB = A.serial_connect(B);
    break;
  case 'p':
    AB = A.parallel_connect(B);
  }

  return AB;
}

int main() {
  Device R1, R2, R3, R12, R123;
  double volt;

  cout << setprecision(4);

  get_input(R1);
  get_input(R2);
  get_input(R3);

  cout << "Enter connection type between R1 and R2 :" << endl;
  R12 = connect(R1, R2);
  cout << "Enter connection type between R12 and R3 :" << endl;
  R123 = connect(R12, R3);

  cout << "Enter the volt :" << endl;
  cin >> volt;

  R123.print_out(volt);
}

// Your code starts here!

void Device::set_resistance(double r) {
    resistance = r;
}
void Device::set_price(int p) {
    price = p;
}
Device Device::serial_connect(Device right) {
    double r = resistance + right.get_resistance();
    int p = price + right.get_price();
    right.set_resistance(r);
    right.set_price(p);
    return right;
}
Device Device::parallel_connect(Device right) {
    double r = resistance * right.get_resistance() / (resistance + right.get_resistance());
    int p = price + right.get_price();
    right.set_resistance(r);
    right.set_price(p);
    return right;
}
double Device::get_resistance() {
    return resistance;
}
int Device::get_price() {
    return price;
}
void Device::print_out(double v) {
    cout << "The current of resistors: " << v / resistance << endl;
    cout << "The total price: " << price << endl;
}

// Your code ends here!
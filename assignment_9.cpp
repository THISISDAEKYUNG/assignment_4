#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class hanoi {
public:
    hanoi(int number_of_disks);
    void print_hanoi(int number_of_disks, int source, int destination, int via);
    void print_total_move();
    //You can add your own member functions
    
private:
    int num_disks_tower0;
    int num_disks_tower1;
    int num_disks_tower2;
    int total_move;
    int plane[3];
};

hanoi::hanoi(int number_of_disks){
    num_disks_tower0 = number_of_disks;
    num_disks_tower1 = 0;
    num_disks_tower2 = 0;
    total_move = 0;
    plane[0] = num_disks_tower0;
    plane[1] = num_disks_tower1;
    plane[2] = num_disks_tower2;
}

void hanoi::print_hanoi(int number_of_disks, int source, int destination, int via){
    //Implement this function
    if (number_of_disks == 1) {
        plane[source] -= 1;
        plane[destination] += 1;
        cout << plane[0] << " " << plane[1] << " " << plane[2] << " (move " <<  source << "->" << destination << ")" << endl;
        total_move++;
        return;
    }
    
    else {
        print_hanoi(number_of_disks - 1, source, via, destination);

        plane[source] -= 1;
        plane[destination] += 1;
        total_move++;
        cout << plane[0] << " " << plane[1] << " " << plane[2] << " (move " <<  source << "->" << destination << ")" << endl;

        print_hanoi(number_of_disks - 1, via, destination, source);
    }
}

void hanoi::print_total_move(){
    cout<<"total_move : " << total_move << endl;
}


int main()
{
    int total_number_of_disks;
    cin >> total_number_of_disks;
    hanoi H(total_number_of_disks);
    H.print_hanoi(total_number_of_disks, 0, 2, 1);
    H.print_total_move();
    return 0;
}

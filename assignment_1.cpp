#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int busMin, taxiMin, walkMin; // Minutes needed for each tansport
    int busFee, taxiFee;          // Fee per minute for each transport
    int budget;
    int numFriends;
    int currHour,
    currMin; // ex. Current time 10:15 -> currHour = 10, currMin = 15

    // get input values (DO NOT change order)
    cin >> busMin >> taxiMin >> walkMin;
    cin >> busFee >> taxiFee;
    cin >> numFriends >> budget;
    cin >> currHour >> currMin;

    // your code starts here    
    int busRealFee = busFee * busMin;

    float taxiFeeF = (float)(taxiFee);
    float numFriendsF = (float)(numFriends);
    float taxiMinF = (float)(taxiMin);

    int taxiRealFee = round((taxiFeeF * taxiMinF) / (numFriendsF + 1.0f));

    int ETAhour, ETAmin;

    cout << "Bus Fee: " << busRealFee << endl;
    cout << "Taxi Fee: " << taxiRealFee << endl;

    if (taxiRealFee <= busRealFee && taxiRealFee <= budget) {
        cout << "\"Going home by taxi\"" << endl;
        
        ETAhour = (currHour + (currMin + taxiMin) / 60) % 24;
        ETAmin = (currMin + taxiMin) % 60;

        // string ETAhourStr = (ETAhour < 10) ? "0" + to_string(ETAhour) : to_string(ETAhour);
        // string ETAminStr = (ETAmin < 10) ? "0" + to_string(ETAmin) : to_string(ETAmin);

        cout << "ETA: ";
        // << ETAhourStr << ":" << ETAminStr << endl;
        if (ETAhour < 10) {
            cout << "0" << ETAhour << ":";
        }
        else {
            cout << ETAhour << ":";
        }

        if (ETAmin < 10) {
            cout << "0" << ETAmin << endl; 
        }
        else {
            cout << ETAmin << endl;
        }
    }

    else if (busRealFee < taxiRealFee && busRealFee <= budget) {
        cout << "\"Going home by bus\"" << endl;
        
        ETAhour = (currHour + (currMin + busMin) / 60) % 24;
        ETAmin = (currMin + busMin) % 60;
        cout << "ETA: ";

        if (ETAhour < 10) {
            cout << "0" << ETAhour << ":";
        }
        else {
            cout << ETAhour << ":";
        }

        if (ETAmin < 10) {
            cout << "0" << ETAmin << endl; 
        }
        else {
            cout << ETAmin << endl;
        }

    }

    else {
        cout << "\"Going home on foot\"" << endl;
        
        ETAhour = (currHour + (currMin + walkMin) / 60) % 24;
        ETAmin = (currMin + walkMin) % 60;
        cout << "ETA: ";

        if (ETAhour < 10) {
            cout << "0" << ETAhour << ":";
        }
        else {
            cout << ETAhour << ":";
        }

        if (ETAmin < 10) {
            cout << "0" << ETAmin << endl; 
        }
        else {
            cout << ETAmin << endl;
        }


    }


    // your code ends here

    return 0;
}

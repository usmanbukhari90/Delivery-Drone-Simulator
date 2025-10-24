#include <iostream>
#include <cstdlib>  // for rand(), srand()
#include <ctime>    // for time()
using namespace std;
bool fly;

void weather(bool &fly) {
    int num = 1 + rand() % 3;    // 1=Sunny, 2=Windy, 3=Rainy
    int temp = 30 + rand() % 16; // Temperature between 30°C and 45°C
    int windspeed = 5 + rand() % 21;

    switch (num) {
    case 1:
        cout << "Today the weather is Sunny";
        cout << " and the temperature is: " << temp << "°C";
        fly = true;
        if (temp > 40) {
            cout << "(Alarmingly hot!)" << endl;
        }
        break;
    case 2:
        cout << "Today the weather is Windy and the  wind speed is: " << windspeed << "m/s" << endl;
        fly = true;
        break;
        
    case 3:
        cout << "Today the weather is Rainy " << endl;
        cout << " We can't fly in rainy weather ";
        fly= false;
        break;
    default:
        cout << "Today the weather is: Unknown" << endl;
        break;
    }
}
                  //OBSTACLE POSSIBLITY(1 chance in 5)
bool obstacle() {
    int probability = 1 + rand() % 5; //1 in a five chance of an obstacle;
    if (probability == 1) {
        bool desire;
        cout << "There's an obstacle midway,We have to change the route" << endl;
        cout << "Do you want to change the route(Enter 1) or return to the base(Enter 0)?  ";
        cin >> desire;
        if (desire == 1) {
            cout << "Changing the route! JOURNEY CONTINUES";
            return true;
        }
        else {
            cout << "Returning to Base";
            return false;
        }
    }
    else {
        cout << "No obstacle in the route. Proceeding smoothly." << endl;
        return false;
    }
    }


int main() {
    srand(time(0));  // Initialize random seed
    char location;
    weather(fly);
    if (!fly) {
        cout << "Mission Canceled";
        return 0;
   }
 
    cout << endl;
    cout << "Choose a location where you want to deliever the package(A,B or C): ";
    cin >> location;
    cout << endl;
    obstacle();
  

    return 0;
}

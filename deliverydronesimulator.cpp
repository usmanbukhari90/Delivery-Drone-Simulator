#include<iostream>
#include<conio.h>
#include<algorithm>
#include<iomanip>
#include<math.h>
using namespace std;
                          // WEATHER FUNCTION
void weather() {
    int num = 1 + rand() % 3;    // 1=Sunny, 2=Windy, 3=Rainy
    int temp = 30 + rand() % 16; // Temperature between 30°C and 45°C
    int windspeed = 5 + rand() % 21;
   switch (num) {
        case 1:
            cout << "Today the weather is Sunny";
            cout << " and the temperature is: " << temp << "°C" << endl;
            if (temp > 40) {
                cout << "Alarmingly hot!" << endl;
            }
            break;
        case 2:
            cout << "Today the weather is Windy and the  wind speed is: "<<windspeed<<"m/s" << endl;
            break;
        case 3:
            cout << "Today the weather is: Rainy" << endl;
            break;
        default:
            cout << "Today the weather is: Unknown" << endl;
            break;
    }
}
int main()
{
cout<<"Drone Delivery Simulator!";
_getch();
return 0;
}

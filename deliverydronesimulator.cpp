#include <iostream>
#include <conio.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <ctime>
using namespace std;
int battery = 100;
int success = 0, delayed = 0, failed = 0, deliveries_given = 0;

int LOCATION(char x);
void OBSTACLES(int x);
void WEATHER_CHECK(int x);
void DISPLAY_SUMMARY(int a, int b, int c, int d, int e);

int LOCATION(char x)
{
    if (x == 'A' || x == 'a')
        return -10;
    else if (x == 'B' || x == 'b')
        return -14;
    else if (x == 'C'|| x == 'c')
        return -16;
    else if (x != 'A' && x != 'B' && x != 'C'&&x != 'a' && x != 'b' && x != 'c')
    {
        cout << endl
             << endl
             << "    Invalid Location Sorry" << endl
             << endl;
        DISPLAY_SUMMARY(success, delayed, failed, battery, deliveries_given);
        exit(0);
    }
}
//weather funtion by Nouman Majeed





int main()
{
    cout << "    Drone Delivery Simulator!" << endl;
    cout<<"---------------------------------"<<endl<<endl;
    char location;
    cout << "   Initial Battery: " << battery << "%" << endl;
    int start;
    cout << " Lets Start our Delivery Day!" << endl;
    cout << " Press 1 for Yes & 0 for No: ";
    //Changes in main Function by Nouman Majeed for adding Weather Function Module



    
_getch();
return 0;
}

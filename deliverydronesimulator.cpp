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
//Location Checking Function
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
//End Summary Function
void DISPLAY_SUMMARY(int a, int b, int c, int d, int e)
{
    cout << " Summary of Today's Deliveries! " << endl
         << endl;
    cout << "Deliveries given to Drone = " << e << endl;
    cout << "Deliveries Delivered Successfuly = " << a << endl;
    cout << "Deliveries Delayed but Delivered = " << b << endl;
    cout << "Deliveries Failed to Deliver = " << c << endl;
    cout << "   Battery Remaining: " << d << "%" << endl
         << endl;
    cout << " ******** THANK YOU! ********";
}
//weather funtion by Nouman Majeed
 //Weather Checking Report Started from Here in main
    int weather;
    cout <<endl<< "   Weather Checking Report!" << endl
         << endl;
    srand(time(0));
    weather = 1 + rand() % 3; // 1=sunny,2=windy,3=rainy
    if (weather == 1)
    {
        success++;
    }
    else if (weather == 2)
    {
        success++;
        delayed++;
        battery = battery - 5;
    }
    else if (weather == 3)
    {
        failed++;
        battery = battery*1;
    }
    WEATHER_CHECK(weather);
    if (weather == 2 && battery < 40)
    {
        cout << "    Bettery is Less then 40% " << endl;
        cout << "        Delivery Delayed " << endl;
        cout << "Returning to base for Recharge! " << endl;
        battery = battery - 10;
    }
    else if (weather == 2)
    {
        cout << "      Delivery Delayed" << endl;  
    }
    cout << "________________________________" << endl
         << endl;







int main()
{
    cout << "    Drone Delivery Simulator!" << endl;
    cout<<"---------------------------------"<<endl<<endl;
    char location;
    cout << "   Initial Battery: " << battery << "%" << endl;
    int start;
    cout << " Lets Start our Delivery Day!" << endl;
    cout << " Press 1 for Yes & 0 for No: ";
     while (true)
    {
        cin >> start;
        switch (start)
        {
        case 1:
        {
            cout << "    System is Loading..." << endl;
            goto continue_program;
            break;
        }
        case 0:
        {
            cout << "        GOOD BYE!  " << endl
                 << endl;
            cout << "_______________________________" << endl
                 << endl;
            DISPLAY_SUMMARY(success, delayed, failed, battery, deliveries_given);
            return 0;
            break;
        }
        default:
        {
            cout << "Please Enter the Correct Input!" << endl;
            cout << "_______________________________" << endl
                 << endl;
            cout << " Press 1 for Yes & 0 for No: ";
            continue;
        }
        }
    }
continue_program:
    cout << "Select a Location!(A or B or C) ";
    deliveries_given++;
    cin >> location;
    if (location != 'A' && location != 'B' && location != 'C' && location != 'a'&& location != 'b'&& location != 'c')
    {
        failed++;
    }
    cout << endl;
    cout << "________________________________"<<endl;
    battery = battery + LOCATION(location);
    if (battery < 20)
    {
        cout << "More Deliveries are aborted for now" << endl;
        cout << "  Returning to Base for Recharge" << endl;
         DISPLAY_SUMMARY(success, delayed, failed, battery, deliveries_given);
            return 0;
    }
    //Changes in main Function by Nouman Majeed for adding Weather Function Module


    

    
_getch();
return 0;
}

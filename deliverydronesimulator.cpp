#include <iostream>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
#include <thread>   // for sleep
#include <chrono>   // for sleep
using namespace std;

bool fly;
int battery = 100;
int success = 0;
int failed = 0;
int delayed = 0;

void weather(bool& fly) {
    int num = 1 + rand() % 3;    // 1=Sunny, 2=Windy, 3=Rainy
    int temp = 30 + rand() % 16; // Temperature between 30°C and 45°C
    int windspeed = 5 + rand() % 21;

    switch (num) {
    case 1:
        cout << "Today the weather is Sunny";
        cout << " and the temperature is: " << temp << "°C";
        fly = true;
        if (temp > 40) {
            cout << " (Alarmingly hot!)";
        }
        cout << endl;
        break;

    case 2:
        cout << "Today the weather is Windy and the wind speed is: "
            << windspeed << " m/s" << endl;
        fly = true;
        break;

    case 3:
        cout << "Today the weather is Rainy." << endl;
        cout << "We can't fly in rainy weather!" << endl;
        fly = false;
        break;

    default:
        cout << "Today the weather is: Unknown" << endl;
        fly = false;
        break;
    }
}

// OBSTACLE POSSIBILITY (1 chance in 5)
bool obstacle() {
    int probability = 1 + rand() % 5; // 1 in 5 chance of an obstacle
    if (probability == 1) {
        bool desire;
        cout << "There's an obstacle midway! We have to change the route." << endl;
        cout << "Do you want to change the route (Enter 1) or return to base (Enter 0)? ";
        cin >> desire;

        if (desire == 1) {
            cout << "Changing the route! Journey continues." << endl;
            battery -= 10;
            return true;  // rerouted successfully
        }
        else {
            battery -= 10;
            cout << "Returning to Base." << endl;
            return false; // failed because returned
        }
    }
    else {
        cout << "No obstacle in the route. Proceeding smoothly." << endl;
        return true; // no obstacle, successful route
    }
}

int main() {
    srand(time(0));  // Initialize random seed
    char location;

    cout << "=== Drone Delivery Simulation Started ===" << endl;
    cout << "Initial battery: " << battery << "%" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 1; i <= 10; i++) {
        cout << "\nDelivery Attempt #" << i << endl;
        weather(fly);

        // Rainy Weather → Delay
        if (!fly) {
            int delay = 30 + rand() % 30;
            cout << "Flight delayed due to rain for approximately "
                << delay << " minutes." << endl;
            delayed++;
            std::this_thread::sleep_for(std::chrono::seconds(2)); // simulate waiting
            cout << "----------------------------------" << endl;
            continue;
        }

        // Ask for delivery location
        cout << "Choose a location where you want to deliver the package (A, B, or C): ";
        cin >> location;

        // Random system malfunction (10% chance)
        int malfunction = rand() % 10;
        if (malfunction == 0) {
            cout << "⚠ System malfunction! Delivery failed." << endl;
            failed++;
            battery -= 15;
            cout << "Remaining battery: " << battery << "%" << endl;
            cout << "----------------------------------------" << endl;
            continue;
        }

        // Check for obstacle
        bool routeSuccess = obstacle();

        if (routeSuccess) {
            cout << "Package delivered successfully!" << endl;
            success++;
            battery -= 20;
        }
        else {
            cout << "Delivery failed due to route issue!" << endl;
            failed++;
        }

        cout << "Remaining battery: " << battery << "%" << endl;
        cout << "----------------------------------------" << endl;

        // Low battery handling
        if (battery <= 20) {
            cout << "Battery is low (<20%). Returning to base for recharge..." << endl;
            battery = 100;
            cout << "Battery recharged to 100%." << endl;
        }
    }

    // Final Summary
    cout << "\n=== Delivery Simulation Summary ===" << endl;
    cout << " Successful Deliveries: " << success << endl;
    cout << " Failed Deliveries: " << failed << endl;
    cout << " Delayed Deliveries: " << delayed << endl;
    cout << " Final Battery Level: " << battery << "%" << endl;
    int total = success + failed + delayed;
 double successrate = (double(success) / (total)) * 100;
    cout << "Success Rate= " << successrate <<"%"<< endl;
    cout << "===================================" << endl;

    return 0;
}
  //Usman Adding Code not finalzed Still
  #include <iostream>
#include <conio.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <ctime>
using namespace std;
int battery = 100;
char LOCATION(char x)
{
    if (x == 'A')
        return -10;
    else if (x == 'B')
        return -14;
    else if (x == 'c')
        return -16;
    else if (x != 'A' && x != 'B' && x != 'C')
        cout << "Invalid Location Sorry";
}
void OBSTACLES(int x)
{
    if (x == 3)
    {
        cout << "         WARNNING!     " << endl;
        cout << "     Birds are Present     " << endl;
        cout << "  The drone is rerouted!   " << endl;
        battery = battery - 5;
    }
    else if (x == 5)
    {
        cout << "         WARNNING!     " << endl;
        cout << "        DANGER ZONE     " << endl;
        cout << "  The drone is rerouted!  " << endl;
        battery = battery - 5;
    }
    else if (x == 1)
    {
        cout << "         Welcome      " << endl;
        cout << "  Their are no Obstacles " << endl;
        cout << "Drone is ready to take off " << endl;
    }
    else if (x == 2)
    {
        cout << "         Welcome      " << endl;
        cout << "  Their are no Obstacles " << endl;
        cout << "Drone is ready to take off " << endl;
    }
    else if (x == 4)
    {
        cout << "         Welcome      " << endl;
        cout << "  Their are no Obstacles " << endl;
        cout << "Drone is ready to take off " << endl;
    }
}
void WEATHER_CHECK(int x)
{
    if (x == 1)
    {
        cout << "        Weather is Sunny" << endl;
        cout << "    Perfect day for delivery" << endl;
        cout << "Package is Delivered Sucessfully" << endl;
    }
    else if (x == 2)
    {
        cout << "        Weather is Windy" << endl;
    }
    else if (x == 3)
    {
        cout << "    Weather is rainy" << endl;
        cout << "    Delivery Delayed" << endl;
    }
}
int main()
{

    cout << "Drone Delivery Simulator!" << endl
         << endl;

    char location;
    cout << "Select a Location!(A or B or C) ";
    cin >> location;
    battery = 100 + LOCATION(location);
    if (battery < 20)
    {
        cout << "More Deliveries are aborted for now";
        cout << "Returning to Base for Recharge";
        battery = 100;
    }
    int obstacles;
    srand(time(0));
    obstacles = 1 + rand() % 5;
    cout << endl
         << endl
         << "      Obstacles Report! " << endl
         << endl;
    OBSTACLES(obstacles);
    int weather;
    cout << "     Weather Checking Report!" << endl
         << endl;
    srand(time(0));
    weather = 1 + rand() % 3; // 1=sunny,2=windy,3=rainy
    WEATHER_CHECK(weather);
    if (weather == 2 && battery < 40)
    {
        cout << "    Bettery is Less then 40% " << endl;
        cout << "        Delivery Delayed " << endl;
        cout << "Returning to base for Recharge! " << endl;
        battery = battery + 10;
    }
    else if (weather == 2)
    {
        cout << "       Delivery Delayed" << endl;
    }
    cout << battery;

    _getch();
    return 0;
}
  
//till there code by Usman
    return 0;
}

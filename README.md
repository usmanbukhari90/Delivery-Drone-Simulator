# Delivery Drone System
## Course: CS110 – Fundamentals of Computer Programming
### Assignment: 1
#### Group:
| Name | Role | CMS ID|
|------|------|-----------|
| Syed Muhammad Usman Shah | Progammer ! (Team Lead)  | 543991  |
| Muhammad Salman Ali Malik | Logic Designer, Tester & Documenter| 552795 |
| Muhammad Nouman Majeed | Progammer 2 | 551285 |
-------------------------------------------------------------------------------
### Overview:
The Delivery Drone Simulator model is an autonomous delivery drone which deliver packages to
three locations (A, B & C) and operates under changing environmental conditions and reacts to 
weather, battery levels, and obstacles. 
This problem reflects real-world challenges faced by delivery drones such as energy efficiency,
decision-making, and mission optimization all done using C++ programming logic.

-------------------------------------------------------------------------------------
### Program Design & Logic:
####Functions:
The simulator was designed using modular programming. Following fuctions were used.
-------------------------------------------------------------------------------------
##### Location Function
Purpose:
To determine the amount of battery consumed based on the chosen delivery location.

Details:
There are three possible delivery points — A, B, and C
- Location A reduces the battery by 10%.
- Location B reduces the battery by 14%.
- Location C reduces the battery by 16%

  If the user enters an invalid input other than A, B, or C, the program displays an error message, shows the summary, and ends the simulation using exit(0)
  This function uses if-else conditions to check the input and return the appropriate battery reduction. It ensures that only valid locations are processed in the program.


DISPLAY_SUMMARY Function  
Purpose:
To display the complete report of the drone’s performance once the simulation end.
 Details:
This function prints:
- Total number of deliveries attempted
- Successful deliveries
- Delayed deliveries
- Failed deliveries
- emaining battery percentage

  It is called at the end of the simulation, or whenever the user exits early or an error/invalid condition occurs.
It uses cout statements to display data clearly and ensures that the operator always receives a proper summary of the drone’s activities.

   WEATHER_CHECK Function
Purpose:
To simulate random weather conditions that affect delivery results and battery usage.

Details:
Weather conditions are generated randomly using rand() and srand(time(0)), producing values between 1 and 3:

-Sunny weather (delivery successful)
- Windy weather (delivery delayed, battery decreases)
-Rainy weather (delivery failed, program ends)

The logic of this function uses if-else conditions to determine what happens based on the weather condition.
If the weather is rainy, the program immediately displays the summary and stops further operations.
This function adds unpredictability and real-world simulation to the project


OBSTACLES Function

  Purpose:
To simulate potential obstacles that may occur during drone flight.

Details:
A random number from 1 to 5 is generated to represent obstacle conditions

- 1, 2, 4 → No obstacles, delivery successful
- 3 → Birds detected, drone rerouted, battery decreases by 5%
- 5 → Danger zone detected, drone rerouted, battery decreases by 5%

The function uses if-else statements to print appropriate messages and update the battery level.
This module makes the delivery simulation more dynamic and realistic by introducing random challenges in the drone’s route


Main Function Logic

Purpose:
To control the overall flow of the simulation and coordinate all modules together.

Details:
The main function begins by displaying a welcome message and asking the user whether they want to start deliveries or exit. This uses a switch statement to handle input:

-Press 1 to start deliveries.
-Press 0 to exit.
- Any invalid input displays an error message and re-prompts the user

When the simulation starts, the user is asked to choose a location (A, B, or C). The LOCATION function is then called to update the battery based on distance. If the battery becomes too low, the drone automatically returns to base.

Next, the WEATHER_CHECK function determines current weather using a random value. Depending on whether the weather is sunny, windy, or rainy, the delivery may succeed, be delayed, or fail.

After that, the OBSTACLES function checks for random obstacles. Depending on the result, messages are displayed and the battery may decrease further if rerouting occurs.

At the end of each delivery, the remaining battery is shown.
If the battery is above 20%, the user can decide whether to start another delivery or send the drone back to base.
This choice is managed through another switch statement:

Press 1 to start another delivery (the program jumps using goto continue_program).

Press 0 to return to base and show the summary.

Invalid input causes the program to ask again.

Finally, when the drone stops or the user ends the session, the DISPLAY_SUMMARY function is called to print all final results.

GLOBAL VARIABLES:
Purpose:
To track important statistics throughout the simulation.

List of Global Variables:

- battery: Tracks remaining battery percentage.
- success: Counts successful deliveries.
- delayed: Counts deliveries that were delayed but completed.
- failed: Counts deliveries that failed.
- deliveries_given: Tracks total number of delivery attempts.
  
These variables are used and updated within different functions and are displayed in the summary at the end



#### Logic Flow:

<img width="886" height="1641" alt="flow drawio" src="https://github.com/user-attachments/assets/67b12f0e-1991-4269-8e81-7ad32dfcad89" />


1. The program starts with a welcome note and sets battery to 100%.
2. It then asks user to begin delivery.
3. Asks to set location.
4. Randomly generates weather condition.
5. If weather is RAINY, delivery is delayed.
6. If weather is windy, return to base and delivery is delayed.
7. Its then checks for OBSTACLES, like birds or danger zoze, each reducing battery by 5%.
8. Aborts delivery if battery is less than 20%.
9. Shows summary of deliveries at the end of each delivery.

    SAMPLE OUTPUT:
           Drone Delivery Simulator
         \ ---------------------------\

            Initial Battery:100%
        Lets Start Our Delivery Day!
       Press 1 for Yes & 0 for NO:_1_
          System i=is Loading...
      Select Locatiom!(A or B or C):_A_
     \----------------------------------\

          Weather Checking Report!

             Weather is Sunny
        Perfect day for delivery
    Package is delivered Successfully
    \--------------------------------\
         Obstacles Checking Report!
                 WARNING!
            Birds are Present
          The Drone is Rerouted!
    \----------------------------------\
    Battery Remaining after 1 delivery = 85%
    \-----------------------------------\
     if you want to start another delivery press 1
     if you want drone to return to base press 0
     \--------------------------------------------\
           Summary of todays deliveries!
      Deliveries given to drone = 1
      Deliveries Delivered Successfully= 1
      deliveries Delayed but Delivered = 0
      Deliveries failed to deliver = 0
           Battery remaining = 85%
     \****** THANK YOU! ******\
   
   


    \-------------------------------------\
   
 --------------------------------------------------------------------------------------
 ### Execution Instructions:
#### Requirments
- A C++ compiler
#### File:
- deliverydronesimulatorf.

  Compile and run the code. The sample output is also provided.
  
 ----------------------------------------------------------------------------------------
 ### Team Collaboration Summary

 Our team collaborated using GitHub for version control.
Each member maintained a separate branch for updates and testing before merging to the main branch.

-Syed Muhammad Usman Shah handled the development of main functions including LOCATION, OBSTACLES, DISPLAY_SUMMARY, and the main program logic.

-Muhammad Nouman Majeed contributed the WEATHER_CHECK function and integrated random environmental effects.

-Muhammad Salman Ali worked as the Logic Designer and was responsible for creating the Program Testing Flowchart and ensuring that all modules connected correctly in the simulation.





 -----------------------------------------------------------------------------------------
 ### AI Tool Used
We made use of followind AI models in the following areas:
- Use of ChatGPT and Copilot for grammer check and understanding GitHub for improving README formatting.
- Used Gemini and Draw.io for flowchart.
  
 
 -----------------------------------------------------------------------------------------
 ### Future Improvements 
 This project can be made even better if we learn and use more advanced C++ topics in the future.
 Some possible improvements are:
- Instead of handling each delivery separately, we can store information (location, weather, battery used, etc.) for all deliveries in an array or vector and then display it at the end- - In the future, we can use simple graphics libraries to make the simulator look more like a real drone control panel.
- Add a basic scoring system that gives points for successful deliveries and deducts points for failures or delays.

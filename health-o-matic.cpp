#include <iostream>
using namespace std;

// 1. Displays a welcome msg to the user
void display_greetings();
// 2. Displays the menu and reads the user input as option
int display_menu();
// 3. Legs of walk: prompts and returns the number of legs in walk
int number_of_legs();
// 4. Total number of steps is calculated by numbr of legs factorial
int display_steps(int leg_count);
// 5. Anxiety Level: Prompts user and returns the anziety level.
int anxiety_level();
// 6. Day of week: Prompts user and returns the day of week.
int weekday();
// 7. Pills to take: requires the axeinty level and the day of the week to compute pill dosage
int dosage(int anxienty, int day);
// 8. Display pill dosage: prints pill dosage
void display_dosage(int dose);
// 9. Prompts user for the hours slept
int sleep_time();
// 10. Nap recommendation: takes in hours slept, distance walked and numnber of pills recommended to compute a nap time reccomentdation
int nap_time(int steps, int dose, int hours_slept);
// 11. Display the recommended nap time
void display_nap_time(int nap_time);
// 12. Caloric burn formula: Computes the calories burned according to the weight, height, room temp, and distance walked.
int caloric_burn(int dist_walked);
// 13. Display's the calories burned
void display_calories_burned(int calories);

int main()
{
    int navigator;
    unsigned int option1_info;
    unsigned int option2_info;
    bool is_option1_selected = false;
    bool is_option2_selected = false;



    display_greetings();
    
    do { 
        navigator = display_menu();
        switch(navigator)
        {
            case 1:
                {
                    int leg_count = number_of_legs();
                    option1_info = display_steps(leg_count);
                    is_option1_selected = true;
                    break;
                }
            case 2:
                {
                    int anxiety = anxiety_level();
                    int day = weekday();
                    int dose = dosage(anxiety, day);
                    display_dosage(dose);
                    option2_info = dose;
                    is_option2_selected = true;
                    break;
                }
            case 3:
                {   
                    if (!is_option1_selected || !is_option2_selected)
                    {
                        cout << "Information from option 1 and option 2 is required." << endl;
                        break;
                    }
                    int hours_slept = sleep_time();
                    unsigned int minutes = nap_time(option1_info, option2_info, hours_slept);
                    display_nap_time(minutes);
                    break;
                }
            case 4:
                {
                    if (!is_option1_selected) 
                    {
                        cout << "Information from option 1 is required." << endl;
                        break;
                    }
                    int calories = caloric_burn(option1_info);
                    display_calories_burned(calories);

                    break;
                }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Value of Navigator: "<< navigator << endl;
                cout << "Invalid option." << endl;
                break;
        }
        
    } while ( navigator != 5 );

    return 0;
}


void display_greetings() {
    cout << endl <<"Welcome to your Health Manager.";
    cout << endl << "Here is a list of options:" << endl;
}

int display_menu()
{
    cout << endl << "Health-o-Matic Options";
    cout << endl << "----------------------" << endl;

    cout << "1. Taking a Walk!" << endl;
    cout << "2. Your Medications" << endl;
    cout << "3. Nap Time!!" << endl;
    cout << "4. Caloric Intake" << endl;
    cout << "5. Quit" << endl << endl;

    unsigned int option;;
    cin >> option;

    return option;
}

int number_of_legs()
{
    int legs = -1;
    while(legs < 0) {
        cout << "Please enter a positve number of legs in walk: ";
        cin >> legs;
    }
    return legs;
}

int display_steps(int leg_count)
{
    unsigned int total_steps = 1;
    for (int i = 1; i < leg_count+1; i++) total_steps *= i;;
    cout << "Congratulations on taking "<< total_steps << " steps!"<< endl;
    return total_steps;
}

int anxiety_level()
{
    int level = -1;
    while(level < 1 || level > 10) {
        cout << "Rate your anxiety from 1-10: ";
        cin >> level;
    }
    return level;
}

int weekday()
{
    int weekday = -1;
    while(weekday < 1 || weekday > 7) {
        cout << "Enter a day from 1-7: ";
        cin >> weekday;
    }
    return weekday;
}

int dosage(int anxiety, int day)
{
    int number_of_pills = (anxiety - day) < 0  ? 0 : anxiety - day;
    return number_of_pills;
}

void display_dosage(int dose) 
{
    cout << "The recommended dose is " << dose << " pills." << endl;
}

int sleep_time()
{
    int sleeptime = -1;
    while(sleeptime < 0) {
        cout << "How many hours did you sleep last night? ";
        cin >> sleeptime;
    }
    return sleeptime;
}

int nap_time(int steps, int dose, int hours_slept)
{
    int divisor = dose == 0 ? 1 : dose;
    unsigned int minutes = (hours_slept + steps)/divisor;
    return minutes;
}

void display_nap_time(int minutes)
{

    cout << "It is reccomended you nap for ";
    if (minutes / 60 > 1) cout << minutes / 60 << " hours." << endl;
    else cout << minutes << " minutes." << endl;
}

int caloric_burn(int dist_walked)
{
    int weight, height;
    float room_temperature;
    float calories;
    weight = height = -1;
    // Lightest person in the world was 4.7 lbs
    while(weight < 4 || weight > 800) 
    {
        cout << "Please enter your body wieght:  ";
        cin >> weight;
    }
    // Tallest person was under 9ft and shortest was over 1 ft
    while(height < 12 || height > 108) 
    {
        cout << "Please enter your height in inches:  ";
        cin >> height;
    }
    // Room temperature is evaluated at 77 F, program accepts 77 +/- 10 F  
    while(room_temperature < 67 || room_temperature > 87) 
    {
        cout << "Please enter the room temperature:  ";
        cin >> room_temperature;
    }
    calories = 6 * weight + 2 * height +  1/room_temperature + dist_walked;
    return calories;
}

void display_calories_burned(int calories)
{
    cout << "You burned " << calories << " calories!" << endl;
}
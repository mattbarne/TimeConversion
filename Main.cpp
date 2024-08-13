#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void timeCollection(vector<int> &time, string &amOrPm){
    // Remove colons for easier manipulation
    char colons;

    // Collect initial time
    cout << "Enter time in HH:MM:SS AM/PM format: ";
    cin >> time[0] >> colons >> time[1] >> colons >> time[2] >> amOrPm;

    // Verify all values are within correct margins
    while(time[0] > 24 || time[0] < 0){
        cout << "Please enter an hour from 0 - 24: ";
        cin >> time[0];
    }
    while(time[1] > 59 || time[1] < 0){
        cout << "Please enter a minute from 0 - 60: ";
        cin >> time[1];
    }
    while(time[2] > 59 || time[2] < 0){
        cout << "Please enter seconds from 0 - 60: ";
        cin >> time[2];
    }
    while(amOrPm != "AM" && amOrPm != "PM"){
        cout << "Please enter format in AM/PM: ";
        cin >> amOrPm;
    }
}

void timeConversion(vector<int> &time, const string &amOrPm){
    int hour = time[0];
    int hour24 = hour;
    
    // First conversion check
    if (amOrPm == "AM"){
        if (hour == 12){
            hour24 = 0;
        }
    } 
    else if (amOrPm == "PM") 
    {
        if (hour != 12) 
        {
            hour24 = hour + 12;
        }
    }

    // Display 24-hour time
    cout << "\n24-Hour Time: ";
    cout << setw(2) << setfill('0') << hour24 << ':'
         << setw(2) << setfill('0') << time[1] << ':'
         << setw(2) << setfill('0') << time[2] << endl;

    // Display 12-hour time
    cout << "12-Hour Time: ";
    cout << setw(2) << setfill('0') << time[0] << ':'
         << setw(2) << setfill('0') << time[1] << ':'
         << setw(2) << setfill('0') << time[2] << ' ' 
         << amOrPm << endl;
}

void timeMenu(vector<int> &time, string &amOrPm){
    bool quit = false;

    while(quit == false){
        int input;
        timeConversion(time, amOrPm);
        // Display menu
        cout << "\n1 - Add one hour" << endl;
        cout << "2 - Add one minute" << endl;
        cout << "3 - Add one second" << endl;
        cout << "4 - Quit program" << endl;

        cin >> input;

        // Check input and validate time convertions a second time
        if(input == 1){
            time[0] += 1;
            if(time[0] > 12){
                time[0] = 1;
                if (amOrPm == "AM"){
                    amOrPm = "PM";
                }
                else{
                    amOrPm = "AM";
                }
            }
        }
        if(input == 2){
            time[1] += 1;
            if(time[1] > 59){
                time[1] = 0;
                time[0] += 1;
                if(time[0] > 12){
                    time[0] = 1;
                    if (amOrPm == "AM"){
                        amOrPm = "PM";
                    } 
                    else{
                        amOrPm = "AM";
                    }
                }
            }
        }
        if(input == 3){
            time[2] += 1;
            if(time[2] > 59){
                time[2] = 0;
                time[1] += 1;
                if(time[1] > 59){
                    time[1] = 0;
                    time[0] += 1;
                    if(time[0] > 12){
                        time[0] = 1;
                        if (amOrPm == "AM"){
                            amOrPm = "PM";
                        } 
                        else{
                            amOrPm = "AM";
                        }
                    }
                }
            }
        }
        if(input == 4){
            quit = true;
            break;
        }
        else{
            while(input < 1 || input > 4){
            cout << "Invalid input: ";
            cin >> input;
            }
        }
    }
}

int main(){
    vector<int> time(3);
    string amOrPm;

    timeCollection(time, amOrPm);
    timeMenu(time, amOrPm);

    return 0;
}
#include <iostream>
#include <chrono>
#include <thread>
#include <utility>
#include <tuple>

#include "horloge.h"
#include <unistd.h>

Horloge::~Horloge() = default;

void Horloge::menu_choice() {
    std::cout<<"What do you want to do ?\n a = display hour, b = set and launch custom clock, c = set alarm : ";
    char choice;
    std::cin>>choice;

   /* if (choice == 'a'){
        std::cout<<"You chose a, it will ask you a format to start a clock and clock will stop after 5 seconds.";
        set_format();
        show_hour();}

    else if (choice == 'b'){
        std::cout<<"You chose b, enter three number to create a custom time position : ";
        int val1, val2, val3;
        std::cin>> val1 >> val2 >> val3;

        auto tup_time = std::make_tuple(val1, val2, val3);
        set_hour(tup_time);}

    else if (choice == 'c'){
        std::cout<<"You chose c, enter three number to create an alarm : ";
        auto tempus = time.strftime("%H:%M:%S");
        std::cout<<"\r" << tempus << std::flush;
        std::string val1, val2, val3;
        std::cin>> val1 >> val2 >> val3;
        auto tup_alarm = std::make_tuple(val1, val2, val3);
        set_alarm(tup_alarm);}
*/}

void Horloge::show_hour() {
    if(format){
        while (status){
            time_t curr_time;
            tm *curr_tm;
            char time_string[100];

            time(&curr_time);
            curr_tm = localtime(&curr_time);

            strftime(time_string, 50, "\rCurrent time is %I:%M:%S%p", curr_tm);
            //print("\r", self.t_time, end="")

            std::cout << "\r" << time_string << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    else{
        while (status) {
            time_t curr_time;
            tm *curr_tm;
            char time_string[100];

            time(&curr_time);
            curr_tm = localtime(&curr_time);

            strftime(time_string, 50, "\rTemps actuel : %H:%M:%S", curr_tm);

            std::cout <<"\r"<< time_string << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    };

void Horloge::set_format() {
    std::cout<<"Which hour format do you want ? \n";
    char choice;
    std::cout<<"Press a for 12 or b for 24 : ";
    std::cin >> choice;
    if (choice == 'a') {
        std::cout << "You chose format 12";
        Horloge::format = true;
    }
    else{
    std::cout<<"You chose format 24";
    }
}

void Horloge::set_hour(int x, int y, int z) {

    char buffer[64];
    const char* fmt = "\r%H:%M:%S";
    time_t  rawTime;
    struct std::tm customTime;

    customTime.tm_hour = x;
    customTime.tm_min = y;
    customTime.tm_sec = z;
    customTime.tm_mday = 12;
    customTime.tm_mon = 7;
    customTime.tm_year = 123;
    customTime.tm_isdst = -1;

    rawTime = mktime(&customTime);
    strftime(buffer, sizeof(buffer), fmt, localtime(&rawTime));
    std::cout << "\r" << buffer << std::flush;
    sleep(1);

}

void Horloge::set_alarm(auto alarm) {

}

int main() {
    Horloge clock;
    clock.show_hour();
    // clock.set_hour(11, 11, 11);
    return 0;
}

//
// Created by kubun on 25/04/23.
//

#ifndef HORLOGE_CPLUS_HORLOGE_H
#define HORLOGE_CPLUS_HORLOGE_H

#include <iostream>
#include <ctime>

class Horloge {
    protected:
        bool status = true;
        bool change, format, pause = false;
        int t = 1;

    public:
        Horloge() = default;
        ~Horloge();

        void menu_choice();
        void show_hour();
        void set_hour(auto tup);
        void set_alarm(auto alarm);
        void set_format();
        void pause_clock();

    void set_hour();
};


#endif //HORLOGE_CPLUS_HORLOGE_H

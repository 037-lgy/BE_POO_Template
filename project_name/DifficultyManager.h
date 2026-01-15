#ifndef DIFFICULTYMANAGER_H_
#define DIFFICULTYMANAGER_H_

#include <Arduino.h>

class DifficultyManager{
    private:
        int spawndelaymode1;
        int spawndelaymode2;
        unsigned long harderdelay;
        int intensite;
    public:
        DifficultyManager();
        ~DifficultyManager();
        void resetspawn();
        void harder();
        const int getspawndelaymode1();
        const int getspawndelaymode2();
        const int getintensite();
        void setharderdelay();
};

#endif
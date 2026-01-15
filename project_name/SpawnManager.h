#ifndef SPAWNMANAGER_H_
#define SPAWNMANAGER_H_

class SpawnManager{
    private:
        int spawndelaymode1;
        int spawndelaymode2;
        unsigned long harderdelay;
    public:
        SpawnManager();
        ~SpawnManager();
        void resetspawn();
        void harder();
        const int getspawndelaymode1();
        const int getspawndelaymode2();
};

#endif
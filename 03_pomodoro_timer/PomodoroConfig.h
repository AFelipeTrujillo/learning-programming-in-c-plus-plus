#ifndef POMODOROCONFIG_H
#define POMODOROCONFIG_H

#include <string>

class PomodoroConfig {

    private:
        int work_time_in_mins;
        int break_time_in_mins;
        std::string mode;
    
    public:
        PomodoroConfig(int argc, char* argv[]);
        int getWorkTime();
        int getBreakTime();
};

#endif
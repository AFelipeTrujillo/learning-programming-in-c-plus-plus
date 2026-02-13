#include "PomodoroConfig.h"
#include <iostream>

PomodoroConfig::PomodoroConfig(int argc, char* argv[]) {
    work_time_in_mins = 25;
    break_time_in_mins = 5;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if ((arg == "--work" || arg == "-w") && i + 1 < argc) {
            work_time_in_mins = std::stoi(argv[++i]);
        }

        else if ((arg == "--break" || arg == "-b") && i + 1 < argc) {
            break_time_in_mins = std::stoi(argv[++i]);
        }

        else if ((arg == "--mode" || arg == "-m") && i + 1 < argc) {
            mode = argv[++i];
            if(mode.compare("long") == 0) {
                work_time_in_mins = 50;
                break_time_in_mins = 10;
            } else if (mode.compare("short") == 0) {
                work_time_in_mins = 15;
                break_time_in_mins = 3;
            }
        }

        else if (arg == "--help" || arg == "-h") {
            std::cout << "Usage: ./pomodoro [options]\n"
                      << "Options:\n"
                      << "  -w, --work MINS    Set work time (default 25)\n"
                      << "  -b, --break MINS   Set break time (default 5)\n"
                      << "  -h, --help         Show this help\n";
        }
    }
}

int PomodoroConfig::getWorkTime() {
    return work_time_in_mins;
}

int PomodoroConfig::getBreakTime() {
    return break_time_in_mins;
}
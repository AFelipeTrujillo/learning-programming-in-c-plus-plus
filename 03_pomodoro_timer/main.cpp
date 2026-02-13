#include <iostream>
#include <chrono>
#include <thread>


void startTimer(int minutes, const std::string& label) {
    auto seconds = std::chrono::minutes(minutes);
    auto total_seconds = std::chrono::duration_cast<std::chrono::seconds>(seconds).count();

    std::cout << "\n--- " << label << " starting (" << minutes << " min) ---" << std::endl;
    for (int i = total_seconds; i >= 0; --i) {
        int mins = i / 60;
        int secs = i % 60;

        std::string colo_text_ansi_escape = (mins < 1 )
            ? "\033[31m"
            : "\033[32m"
        ;
        std::string reset = "\033[0m";

        std::cout << "\r"
                  << colo_text_ansi_escape
                  << "Time Remaining: " 
                  << (mins < 10 ? "0" : "") << mins << ":" 
                  << (secs < 10 ? "0" : "") << secs << reset << std::flush;
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "\n\a¡" << label << " done!" << std::endl;
}

int main(int argc, char* argv[]) {
    
    int workTime = 25;
    int breakTime = 5;
    std::string mode;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if ((arg == "--work" || arg == "-w") && i + 1 < argc) {
            workTime = std::stoi(argv[++i]);
        }

        else if ((arg == "--break" || arg == "-b") && i + 1 < argc) {
            breakTime = std::stoi(argv[++i]);
        }

        else if ((arg == "--mode" || arg == "-m") && i + 1 < argc) {
            mode = argv[++i];
            if(mode.compare("long") == 0) {
                workTime = 50;
                breakTime = 10;
            } else if (mode.compare("short") == 0) {
                workTime = 15;
                breakTime = 3;
            }
        }

        else if (arg == "--help" || arg == "-h") {
            std::cout << "Usage: ./pomodoro [options]\n"
                      << "Options:\n"
                      << "  -w, --work MINS    Set work time (default 25)\n"
                      << "  -b, --break MINS   Set break time (default 5)\n"
                      << "  -h, --help         Show this help\n";
            return 0;
        }
    }

    std::cout << "=== C++ POMODORO TIMER ===" << std::endl;
    
    while (true) {
        startTimer(workTime, "WORK SESSION");
        startTimer(breakTime, "BREAK");
        
        std::cout << "\ndo you want to start other session? (s/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 's') break;
    }

    return 0;
}

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
    std::string workTimeStr;
    std::string breakTimeStr;
    int workTime;
    int breakTime;

    try {

        std::cout << "Enter the work time (min): " << std::endl;
        std::cin >> workTimeStr;
        workTime = stoi(workTimeStr);

        std::cout << "Enter the break time (min): " << std::endl;
        std::cin >> breakTimeStr;
        breakTime = stoi(breakTimeStr);

    } catch(const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
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

#include <iostream>
#include <iomanip>
#include <ctime>
#include <thread>     // For sleep
#include <chrono>     // For std::chrono::seconds
#ifdef _WIN32
#include <windows.h>  // For system("cls") on Windows
#else
#include <unistd.h>   // For sleep on Unix systems
#endif

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    while (true) {
        time_t t = time(nullptr);              // Get current time
        tm* now = localtime(&t);               // Convert to tm struct

        clearScreen();                         // Clear the screen
        cout << setfill('0');
        cout << "Digital Clock\n\n";
        cout << setw(2) << now->tm_hour << ":"
             << setw(2) << now->tm_min << ":"
             << setw(2) << now->tm_sec << endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));  // Wait 1 second
    }

    return 0;
}

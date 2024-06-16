#include <iostream>
#include <fstream>
#include <string>

int main() {  // Corrected function name to 'main'
    // main program loop variable
    bool loopOn = false;
    // ask for user input
    std::cout << "Welcome to the Daily Calorie Tracker" << std::endl;
    std::cout << "Begin? Enter 'Y' for yes or 'N' for no: " << std::endl;
    // declare input variable
    std::string userAns;
    std::cin >> userAns;
    // check if user wants to begin
    if (userAns == "Y" || userAns == "y") {  // Corrected string comparison and included both uppercase and lowercase
        loopOn = true;
    } else {
        std::cout << "OK. Goodbye." << std::endl;
        return 0;  // Added return statement to exit if user says no
    }   // end if-else statement to initiate main program loop

    // main program loop
    while (loopOn) {
        // program prompts user for input
        std::cout << "Enter your daily caloric needs (enter positive integers): ";
        // user input stored to declared variable
        int dailyCal;
        std::cin >> dailyCal;
        // open file in append mode
        std::ofstream file("C:\\Users\\jamaa\\Desktop\\CSC450_CT5_mod5.txt", std::ios_base::app);  // Corrected file path
        // check if file is open
        if (!file.is_open()) {
            std::cerr << "File not opened" << std::endl;
            return 1;  // Return from main if file cannot be opened
        }
        // write it to file
        file << "Your daily caloric needs for today: " + std::to_string(dailyCal) << std::endl;
        // prompt user to repeat
        std::cout << "Continue? Enter 'Y' for yes or 'N' for no: ";
        std::cin >> userAns;
        if (userAns != "Y" && userAns != "y") {
        	std::cout << "OK. Goodbye.";
            loopOn = false;  // Condition to exit the loop
        }
    }

    return 0;
}

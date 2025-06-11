#include <iostream> // Include the standard input/output stream library
#include <ctime>    // Include the C time library for random seed

char GetUserChoise(); // Declare function to get user's choice
char GetComputerChoise(); // Declare function to get computer's choice
void NameChoise(char choise); // Declare function to print the name of a choice
void Winner(char player, char computer); // Declare function to determine and print the winner

int main() { // Start of main function
    char player; // Variable to store player's choice
    char computer; // Variable to store computer's choice
    player = GetUserChoise(); // Get the player's choice from input
    std::cout << "Human choise is: "; // Print label for player's choice
    NameChoise(player); // Print the name of the player's choice
    computer = GetComputerChoise(); // Get the computer's random choice
    std::cout << "Computer Choise is: "; // Print label for computer's choice
    NameChoise(computer); // Print the name of the computer's choice
    Winner(player, computer); // Determine and print the winner
}

char GetUserChoise(){ // Function to get the user's choice
    char player; // Variable to store input
    do { // Loop until a valid input is entered
        std::cout << "************************\n"; // Print a line of asterisks
        std::cout << "Rock-Paper-Scissors-Game\n"; // Print game title
        std::cout << "************************\n"; // Print a line of asterisks
        std::cout << std::endl; // Print a blank line
        std::cout << "****Pick your choise****\n"; // Prompt user to pick a choice
        std::cout << "-(r) Rock\n"; // Show option for Rock
        std::cout << "-(p) Paper\n"; // Show option for Paper
        std::cout << "-(s) Scissors\n"; // Show option for Scissors
        std::cin >> player; // Read user input
    }while(player != 'r' && player != 's' && player != 'p' ); // Repeat if input is not valid
    return player; // Return the valid choice
}

char GetComputerChoise(){ // Function to get the computer's random choice
    int num; // Variable to store random number
    srand(time(0)); // Seed the random number generator with current time
    num = rand() % 3 + 1; // Generate a random number between 1 and 3
    switch (num) // Switch based on random number
    {
        case 1: return 'r'; // If 1, return 'r' for Rock
        case 2: return 's'; // If 2, return 's' for Scissors
        case 3: return 'p'; // If 3, return 'p' for Paper
        default: return 'r'; // Default to 'r' (should not happen)

        // No need to type -break;- in this switch bec. when returning values it always -break;-

    }
}

void NameChoise(char choise){ // Function to print the name of a choice
    switch (choise) // Switch based on the choice character
    {
        case 'r': std::cout << "Rock" << std::endl; // If 'r', print Rock
            break; // Exit switch
        case 's': std::cout << "Scissors" << std::endl; // If 's', print Scissors
            break; // Exit switch
        case 'p': std::cout << "Paper" << std::endl; // If 'p', print Paper
            break; // Exit switch
        default: std::cout << "Rock" << std::endl; // For any other input, print Rock
    }
}

void Winner(char player, char computer){ // Function to determine and print the winner
    switch (player) // Switch based on player's choice
    {
        case 'r': // If player chose Rock
            switch (computer) { // Switch based on computer's choice
                case 'r':
                    std::cout << "(It's a tie!)" << std::endl; // Both chose Rock
                    break;
                case 'p':
                    std::cout << "(Computer wins!)" << std::endl; // Computer chose Paper
                    break;
                case 's':
                    std::cout << "(You win!)" << std::endl; // Computer chose Scissors
                    break;
            }
            break;
        case 'p': // If player chose Paper
            switch (computer) {
                case 'r':
                    std::cout << "(You win!)" << std::endl; // Computer chose Rock
                    break;
                case 'p':
                    std::cout << "(It's a tie!)" << std::endl; // Both chose Paper
                    break;
                case 's':
                    std::cout << "(Computer wins!)" << std::endl; // Computer chose Scissors
                    break;
            }
            break;
        case 's': // If player chose Scissors
            switch (computer) {
                case 'r':
                    std::cout << "(Computer wins!)" << std::endl; // Computer chose Rock
                    break;
                case 'p':
                    std::cout << "(You win!)" << std::endl; // Computer chose Paper
                    break;
                case 's':
                    std::cout << "(It's a tie!)" << std::endl; // Both chose Scissors
                    break;
            }
            break;
        default:
            std::cout << "(Invalid input!)" << std::endl; // If player input is invalid
            break;
    }
}
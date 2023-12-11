#include <iostream>
#include <vector>
#include <map>

#include "automaton.h"

using namespace std;


int main() {

    //introduction
    cout << "this automaton accepts a string if the first symbol in alphabet meets even number of times\n\n ";

    // Entering the size of the alphabet
    cout << "Enter the size of the alphabet:  ";
    int alphabetSize;
   cin >> alphabetSize;

    // The size of the alphabet must be non-negative
    if (alphabetSize <= 0) {
        cout << "Invalid alphabet size. Exiting...\n";
        return 1;
    }

    // User Alphabet Input
    vector<char> alphabet;
    cout << "Enter the alphabet characters (separate with spaces, max " << alphabetSize << "): ";
    for (int i = 0; i < alphabetSize; ++i) {
        char symbol;
        cin >> symbol;
        alphabet.push_back(symbol);
    }

    //  User Input of String Length
    cout << "Enter the length of the string: ";
    int stringLength;
    cin >> stringLength;

    // Entering a string to check for the even inclusion of the first character of the alphabet 
    vector<char> input;
    cout << "Enter the string to check (length" << stringLength << "): ";
    char symbol;
    for (int i = 0; i < stringLength; ++i) {
        cin >> symbol;
        input.push_back(symbol);
    }



    // Creating Transitions for a State Machine
    map<std::pair<int, char>, int> transitions;


      //state machine Logic
    transitions[{0, alphabet[0]}] = 1;//  From even to odd (originally even)
    transitions[{1, alphabet[0]}] = 0;//  From odd to even

    //  Transitions for all possible dimensions of the alphabet
    for (int i = 1; i < alphabetSize; ++i)
    {
      transitions[{0, alphabet[i]}] = 0;
     transitions[{1, alphabet[i]}] = 1;
    }

    //Creating a State Machine 
    FiniteAutomaton<int, char> automaton
    (
        { 0, 1 },                // States (0-even1-odd number of the first character of the alphabet in a string)
        alphabet,              // Alphabet (previously entered by the user)
        0,                     // Initial state (initially even(=0))
        0,                     //  Output state (accept a string if the number of inclusions of the first character is even)
        transitions               // Transitions created based on the length of the alphabet 
    );

    // String Validation 
    if (automaton.checkString(input)) {
        cout << "String is accepted (amount of " << alphabet[0] << " is even).\n";// successis the even number of the first character of the alphabet in the entered string 
    }
    else {
        cout << "String is not accepted (amount of " << alphabet[0] << " is odd).\n";// Failure- An odd number of the first character of the alphabet in the entered string 
    }

    return 0;
}

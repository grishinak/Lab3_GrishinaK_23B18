#include <iostream>
#include <vector>
#include <map>
#include <string>


using namespace std;
//class for finite automaton 
template<typename State, typename Alphabet>
class FiniteAutomaton {
public:

    //setters for fields 
  
    void setStates(const vector<State>& states) {
        this->states = states;
    }

    void setAlphabet(const vector<Alphabet>& alphabet) {
        this->alphabet = alphabet;
    }

    void setInitial(const State& initial) {
        this->initial = initial;
    }

    void setFinal(const State & final) {
        this->final = final;
    }

    void setTransitions(const map<pair<State, Alphabet>, State>& transitions) {
        this->transitions = transitions;
    }

    //bool method for fsmN1( .1 and .2)
    bool checkString(const vector<Alphabet>& input) const {
        State currentState = initial;

        for (const auto& symbol : input) {
            auto transition = transitions.find({ currentState, symbol });

            if (transition != transitions.end()) {
                currentState = transition->second;
            }
            else {
                return false;
            }
        }

        return currentState == final;
    }

    // bool method for fsmN2
    bool checkSubstring(const string& input, const string& substring) const {
        vector<Alphabet> inputSymbols(input.begin(), input.end());

        // Check if the substring is found
        for (size_t i = 0; i <= inputSymbols.size() - substring.length(); ++i) {
            if (checkString(vector<Alphabet>(inputSymbols.begin() + i, inputSymbols.begin() + i + substring.length()))) {
                return true;
            }
        }

        return false;
    }


private:

    // class fields 
    vector<State> states;
    vector<Alphabet> alphabet;
    State initial;
    State final;
    map<pair<State, Alphabet>, State> transitions;
};







int main() {


    cout << "FiniteStateMachine N1.1 " << endl;
    // FiniteStateMachine N1.1 (char) realisation


    // Introduction
    cout << "(This automaton accepts a string if the first symbol in the alphabet meets an even number of times.)\n\n";

    // Creating FiniteAutomaton object
    FiniteAutomaton<int, char> automatonIntChar;


    // User input for FiniteAutomaton<int, char>
    int alphabetSize;
    cout << "Enter the size of the alphabet: ";
    cin >> alphabetSize;

    if (alphabetSize <= 0) {
        cout << "Invalid alphabet size. Exiting...\n";
        return 1;
    }

    //user alphabet input 
    vector<char> alphabetChar;
    cout << "Enter the alphabet characters (separate with spaces, max " << alphabetSize << "): ";
    for (int i = 0; i < alphabetSize; ++i) {
        char symbol;
        cin >> symbol;
        alphabetChar.push_back(symbol);
    }

    automatonIntChar.setStates({ 0, 1 });
    automatonIntChar.setAlphabet(alphabetChar);
    automatonIntChar.setInitial(0);
    automatonIntChar.setFinal(0);

    map<pair<int, char>, int> transitionsIntChar;
    transitionsIntChar[{0, alphabetChar[0]}] = 1;
    transitionsIntChar[{1, alphabetChar[0]}] = 0;

    for (int i = 1; i < alphabetSize; ++i) {
        transitionsIntChar[{0, alphabetChar[i]}] = 0;
        transitionsIntChar[{1, alphabetChar[i]}] = 1;
    }

    automatonIntChar.setTransitions(transitionsIntChar);


    // String Validation
    int stringLength;
    cout << "Enter the length of the string: ";
    cin >> stringLength;

    // Validate FiniteAutomaton<int, char>
    vector<char> inputChar;
    cout << "Enter the string to check (length " << stringLength << "): ";
    char symbolChar;
    for (int i = 0; i < stringLength; ++i) {
        cin >> symbolChar;
        inputChar.push_back(symbolChar);
    }

    if (automatonIntChar.checkString(inputChar)) {
        cout << "String is accepted (amount of " << alphabetChar[0] << " is even).\n";
    }
    else {
        cout << "String is not accepted (amount of " << alphabetChar[0] << " is odd).\n\n";
    }





    // FiniteStateMachine N1.2 (int type)
    cout << "\n\nFiniteStateMachine N1.2 (This automaton accepts a int string if the first symbol in the alphabet meets an even number of times.)" << endl;
    // User input for FiniteAutomaton<int, int>
    FiniteAutomaton<int, int> automatonIntInt;

    //alphabet input 
    int alphabetSizeInt;
    cout << "Enter the size of the alphabet: ";
    cin >> alphabetSizeInt;

    if (alphabetSizeInt <= 0) {
        cout << "Invalid alphabet size. Exiting...\n";
        return 1;
    }

    vector<int> alphabetInt;
    cout << "Enter the alphabet characters (separate with spaces, max " << alphabetSizeInt << "): ";
    for (int i = 0; i < alphabetSizeInt; ++i) {
        int symbol;
        cin >> symbol;
        alphabetInt.push_back(symbol);
    }

    //setting up the automaton 
    automatonIntInt.setStates({ 0, 1 });
    automatonIntInt.setAlphabet(alphabetInt);
    automatonIntInt.setInitial(0);
    automatonIntInt.setFinal(0);
    

    //transitiod 
    map<pair<int, int>, int> transitionsIntInt;
    transitionsIntInt[{0, alphabetInt[0]}] = 1;
    transitionsIntInt[{1, alphabetInt[0]}] = 0;

    for (int i = 1; i < alphabetSizeInt; ++i) {
        transitionsIntInt[{0, alphabetInt[i]}] = 0;
        transitionsIntInt[{1, alphabetInt[i]}] = 1;
    }

    automatonIntInt.setTransitions(transitionsIntInt);

    // String Validation
    int IntstringLength;
    cout << "Enter the length of the string: ";
    cin >> IntstringLength;

    // Validate FiniteAutomaton<int, int>
    vector<int> inputInt;
    cout << "Enter the string to check (length " << IntstringLength << "): (after each symbol push space)";
    int symbolInt;
    for (int i = 0; i < IntstringLength; ++i) {
        cin >> symbolInt;
        inputInt.push_back(symbolInt);
    }

    if (automatonIntInt.checkString(inputInt)) {
        cout << "String is accepted (amount of " << alphabetInt[0] << " is even).\n";
    }
    else {
        cout << "String is not accepted (amount of " << alphabetInt[0] << " is odd).\n";
    }




    cout << "\n\nFiniteStateMachine N2 (This automaton find the substring in a string.)" << endl;
    // FiniteStateMachine N2 


         // Input alphabet
    string alphabetString;
    cout << "Enter the alphabet: ";
    cin >> alphabetString;

    // Convert the alphabet string to a vector of characters
    vector<char> alphabet(alphabetString.begin(), alphabetString.end());

    // Input the substring
    string substring;
    cout << "Enter the substring(without spaces): ";
    cin >> substring;

    // Input the main string
    string inputString;
    cout << "Enter the main string(without spaces): ";
    cin >> inputString;

    // Create an instance of FiniteAutomaton
    FiniteAutomaton<int, char> automaton;

    // Set up the automaton transitions based on user input
    automaton.setStates({});
    automaton.setAlphabet(alphabet);
    automaton.setInitial(0);
    automaton.setFinal(substring.length());

    // Inside the main function after setting up the transitions
    map<pair<int, char>, int> transitions;

    for (size_t state = 0; state <= substring.length(); ++state) {
        for (char symbol : alphabet) {
            size_t nextState = min(state + 1, substring.length());
            while (nextState > 0 && substring[nextState - 1] != symbol) {
                nextState = automaton.checkString(
                    vector<char>(substring.begin(), substring.begin() + nextState - 1) ) ? 1 : 0;
            }
            transitions[{state, symbol}] = nextState;
        }
    }

    automaton.setTransitions(transitions);


    // Check if the substring is found
    if (automaton.checkSubstring(inputString, substring)) {
        cout << "Substring " << substring << " was found in a string!" << endl;
    }
    else {
        cout << "Substring " << substring << " was not found in a string." << endl;
    }



    return 0;
}

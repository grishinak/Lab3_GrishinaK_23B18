#pragma once

using namespace std;



template<typename State, typename Alphabet>
class FiniteAutomaton {

public:

    //A class constructor that initializes FSM parameters
    FiniteAutomaton
    (
        const vector<State>& states,
        const vector<Alphabet>& alphabet,
        const State& initial,
        const State & final,
        const map<pair<State, Alphabet>, State>& transitions

    ) : states(states), alphabet(alphabet), initial(initial), final(final), transitions(transitions) {}

    // A Boolean Class Method for Checking a String for the Even Contents of the First Character (by Number) of the Alphabet 
    bool checkString(const vector<Alphabet>& input) const {
        State currentState = initial;

        // Iterate over the characters of the input string
        for (const auto& symbol : input) {
            // Find a transition for the current state and symbol
            auto transition = transitions.find({ currentState, symbol });

            //  If the transition is found, update the current state
            if (transition != transitions.end()) {
                currentState = transition->second;
            }


            else {

                return false;  //If there is no transition, return false (the string does not meet the conditions of the machine)
            }
        }


        return currentState == final; //  End State Reached
    }


private:

    vector<State> states; //State Vector of a Machine

    vector<Alphabet> alphabet;   // Vector alphabet characters

    State initial;// Initial state

    State final;     // Final state 

    map<pair<State, Alphabet>, State> transitions; // transition table

};

#pragma once


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


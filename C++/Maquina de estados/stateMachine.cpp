#include <iostream>

class State {
public: 
    virtual void UpdateState() = 0;
};

class StateA : public State {
public: 
    void UpdateState() { std:: cout << "updating state A" << std::endl;
    }
    stateA() {
        std::cout << "State A is created" << std::endl;
    }
};

class StateB : public State {
public:     
    void UpdateState() { std:: cout << "updating state B" << std::endl;
    }
    stateB() {
        std::cout << "State B is created" << std::endl;
    }
};

class StateC : public State {
public: 
    void UpdateState() { std:: cout << "updating state C" << std::endl;
    }
    stateC() {
        std::cout << "State C is created" << std::endl;
    }
};

class StateD : public State {
public: 
    void UpdateState() { std::cout << "updating state D" << std::endl;
    }
    stateD() {
        std::cout << "State D is created" << std::endl;
    }
};
 
class StateController {
private:
    State* currentState = nullptr;
public:
    void Init() {
        currentState= new StateA();
    }
    void Update() {
        currentState->UpdateState();
    }
    void TransitionTo(char c) {
        delete currentState;
        if (c =='a') {
            currentState = new StateA();
        }
        else if (c =='b') {
            currentState = new StateB();
        }
        else if (c =='c') {
            currentState = new StateC();
        }
        else if (c =='d') {
            currentState = new StateD();
        }
    }
    ~StateController () {
        delete currentState;
    }
};

int main() {
    StateController stateController;
    stateController.Init();
    std::string str = "n";
    while (str[0] != 'q') {
        stateController.Update();
        std::cin >> str;
        std::cout << std::endl;
        if (str[0] == 'a' || str[0] == 'b' ||str[0] == 'c' ||str[0] == 'd') {
            stateController.TransitionTo(str[0]);
        }
    }
}
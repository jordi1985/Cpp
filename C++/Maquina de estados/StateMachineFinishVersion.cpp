#include <iostream>

//global use, D is a initial status.
char sttus = 'A';
char* weComeFromState = &sttus;

class State {
public: 
    virtual void UpdateState() = 0;
};

class StateA : public State {
public: 
    void UpdateState() {
        *weComeFromState = 'A';
        std:: cout << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << "updating state A" << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << std::endl;
        std:: cout << "From State A you can go:" << std::endl;
        std:: cout << "press 'b' to go state B" << std::endl;
        std:: cout << "press 'd' to go state D" << std::endl;
        std:: cout << std::endl;

    }
    stateA() {
        std::cout << "State A is created" << std::endl;
    }
};
class StateB : public State {
public:     
    void UpdateState() {
        *weComeFromState = 'B';
        std:: cout << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << "updating state B" << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << std::endl;
        std:: cout << "From State B you can go:" << std::endl;
        std:: cout << "press 'c' to go state C" << std::endl;
        std:: cout << "press 'd' to go state d" << std::endl;
        std:: cout << std::endl;
    }
    stateB() {
        std::cout << "State B is created" << std::endl;
    }
};
class StateC : public State {
public: 
    void UpdateState() {
        *weComeFromState = 'C'; 
        std:: cout << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << "updating state C" << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << std::endl;
        std:: cout << "From State C you can go:" << std::endl;
        std:: cout << "press 'a' to go state A" << std::endl;
        std:: cout << "press 'd' to go state D" << std::endl;
        std:: cout << std::endl;
    }
    stateC() {
        std::cout << "State C is created" << std::endl;
    }
};
class StateD : public State {
public: 
    void UpdateState() {
        *weComeFromState = 'D';
        std:: cout << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << "updating state D" << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << std::endl;
        std:: cout << "From State D you can go:" << std::endl;
        std:: cout << "press 'b' to go state B" << std::endl;
        std:: cout << "press 'q' to quit" << std::endl;
        std:: cout << std::endl;
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
        currentState= new StateD();
    }
    void Update() {
        currentState->UpdateState();
    }
    void TransitionTo(char c) {
        std::cout << "We Come From State " << weComeFromState << std::endl;
        delete currentState;
        switch  (*weComeFromState) {
            case 'A':
                if (c =='b') {
                    currentState = new StateB();
                } else if (c =='d') { 
                    currentState = new StateD();
                } else { std::cout << "not a correct option" << std::endl; 
                         currentState = new StateA();
                    }
            break;

            case 'B':
                if (c =='c') {
                    currentState = new StateC();
                } else if (c =='d') { 
                    currentState = new StateD();
                } else { std::cout << "not a correct option" << std::endl; 
                         currentState = new StateB();
                    }
            break;

            case 'C':
                if (c =='a') {
                    currentState = new StateA();
                } else if (c =='d') { 
                    currentState = new StateD();
                } else { std::cout << "not a correct option" << std::endl; 
                         currentState = new StateC();
                    }
            break;

            case 'D':
                if (c =='b') {
                    currentState = new StateB();
                } else { std::cout << "not a correct option" << std::endl; 
                         currentState = new StateD();
                    }

            break;                       
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
        } else if (str[0] != 'q') {
            std::cout << std::endl;
            std::cout << "Not a valid option." << std::endl;
            std::cout << std::endl;
        }
    }
    weComeFromState = NULL;
    delete weComeFromState;
}
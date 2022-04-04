#include <iostream>

//for global use, StateInicial is a initial status of the STATE MACHINE.
char sttus = 'D';
char* weComeFromState = &sttus;

//////////////////////////////
// STATES
/////////////////////////////
// Parent Class -> State.
class State {
public: 
    virtual void UpdateState() = 0;
};
//A Status
class StateDisconnected : public State {
public: 
    void UpdateState() {
        *weComeFromState = 'A';
        std:: cout << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << "updating StateDisconnected" << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << std::endl;
        std:: cout << "From State StateConnecting you can go:" << std::endl;
        std:: cout << "press 'b' to go state StateConnecting" << std::endl;
        std:: cout << "press 'd' to go state StateInitial" << std::endl;
        std:: cout << std::endl;

    }
    StateDisconnected() {
        std::cout << "State StateDisconnected is created" << std::endl;
    }
};
//B Status
class StateConnecting : public State {
public:     
    void UpdateState() {
        *weComeFromState = 'B';
        std:: cout << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << "updating StateConnecting" << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << std::endl;
        std:: cout << "From State StateConnecting you can go:" << std::endl;
        std:: cout << "press 'c' to go state StateConnected" << std::endl;
        std:: cout << "press 'd' to go state StateInitial" << std::endl;
        std:: cout << std::endl;
    }
    StateConnecting() {
        std::cout << "State StateConnecting is created" << std::endl;
    }
};
//C status
class StateConnected : public State {
public: 
    void UpdateState() {
        *weComeFromState = 'C'; 
        std:: cout << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << "updating StateConnected" << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << std::endl;
        std:: cout << "From State StateConnected you can go:" << std::endl;
        std:: cout << "press 'a' to go state StateDisconnected" << std::endl;
        std:: cout << "press 'd' to go state StateInitial" << std::endl;
        std:: cout << std::endl;
    }
    StateConnected() {
        std::cout << "StateConnected is created" << std::endl;
    }
};
//D status
class StateInitial : public State {
public: 
    void UpdateState() {
        *weComeFromState = 'D';
        std:: cout << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << "updating StateInitial" << std::endl;
        std:: cout << "#################" << std::endl;
        std:: cout << std::endl;
        std:: cout << "From StateInitial you can go:" << std::endl;
        std:: cout << "press 'b' to go state StateConnecting" << std::endl;
        std:: cout << "press 'q' to quit" << std::endl;
        std:: cout << std::endl;
    }
    StateInitial() {
        std::cout << "State StateInitial is created" << std::endl;
    }
};
 
class StateController {
private:
    State* currentState = nullptr;
public:
    void Init() {
        currentState= new StateInitial();
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
                     currentState = new StateDisconnected();
                } else if (c =='d') { 
                     currentState = new StateInitial();
                } else { std::cout << "not a correct option" << std::endl; 
                         currentState = new StateDisconnected();
                    }
            break;

            case 'B':
                if (c =='c') {
                    currentState = new StateConnected;
                } else if (c =='d') { 
                     currentState = new StateInitial();
                } else { std::cout << "not a correct option" << std::endl; 
                         currentState = new StateConnecting();
                    }
            break;

            case 'C':
                if (c =='a') {
                     currentState = new StateDisconnected();
                } else if (c =='d') { 
                     currentState = new StateInitial();
                } else { std::cout << "not a correct option" << std::endl; 
                         currentState = new StateConnected();
                    }
            break;

            case 'D':
                if (c =='b') {
                    currentState = new StateConnecting();
                } else { std::cout << "not a correct option" << std::endl; 
                         currentState = new StateInitial();
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
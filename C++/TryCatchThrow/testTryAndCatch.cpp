
#include <iostream>
class A { 
public:
    A(){}
    ~A()noexcept(false) {
        throw 42;
    }
};

int main(int argc, char* argv[]) {

    try {
        A a;
        throw 32;
    } catch (int a) {
        std::cout << a;
    }

    system("pause>0");
    return 0;
} 

/* int main () {
  try
  {
    throw 20;
  }
  catch (int e)
  {
    std::cout << "An exception occurred. Exception Nr. " << e << std::endl;
  }
  return 0;
} */

/* int main(int argc, char** argv) {
    std::cout << "Have " << argc << " arguments:" << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
} */
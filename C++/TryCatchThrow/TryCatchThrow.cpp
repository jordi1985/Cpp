#include <iostream>

class Printer {
    private:
        std::string _name;
        int _avaliblePaper;
    public:
        Printer (std::string name,int paper) {
            _name = name;
            _avaliblePaper = paper;
        }

        void Print (std::string txtDocument) {
            // simulamos que se pueden imprimir un maximo de 10 palabras por hoja, por ejemplo si hay 40 palabras se necesitan 4 hojas.
            int requiredPaper = txtDocument.length() / 10;
            if (requiredPaper > _avaliblePaper)
                throw 101;
            
            std::cout << "printing..." << txtDocument << std::endl;
            _avaliblePaper -= requiredPaper;


        }
};


int main() {

    Printer miImpresora ( "OnionIndustries MK1", 5);
    try {

        miImpresora.Print("Primera impresora de Onion Industries!");
        miImpresora.Print("Primera impresora de Onion Industries!");
        miImpresora.Print("Primera impresora de Onion Industries!");
    }

    catch ( const char * txtException) {
        std::cout << "Exception: " << txtException << std::endl;
    }

/*     catch (int exCode) {
        std::cout << "Exception: " << exCode << std::endl;
    } */
    
    // los handling por defecto siempre al final, sino da error ya que no puedes hacer un control especifico, siempre entra por el "por defecto".
    catch (...) {
        std::cout << "Exception happened!" << std::endl;
    }
    
    system("pause>0");
    return 0;
}
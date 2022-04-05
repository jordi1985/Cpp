#include <iostream>
#include <memory>
int PunteroU (std::unique_ptr<int> P) {
    //mostramos el contenido del puntero unico por segunda vez.
    std::cout << *P.get() << std::endl;
    return 0;
}

char PunteroC (std::shared_ptr<char> P) {
    std::cout << *P.get() << std::endl;
}

int main(){
    //unique_pointer
    std::unique_ptr<int> punteroUnico = std::make_unique<int>(25);
    //mostramos el contenido de puntero unico por primera vez
    std::cout << *punteroUnico << std::endl;
    //movemos hacia una funcion el contenido de puntero unico- vamos a la funcion
    PunteroU (move(punteroUnico));
    std::cout << "Vuelta de la funcion 'PunteroU' " << std::endl;
    // intentamos mostrar el contenido de puntero unico por tercera vez pero no sale nada...
    //Como se ha borrado el contenido del puntero y se está intentando mostrar el programa termina aquí.
    //std::cout << *punteroUnico << std::endl;
    std::cout << "si solo aparece 2 veces el num, es que se ha borrado!" << std::endl;
    //shared_pointer
    std::cout<<"Test puntero compartido"<<std::endl;
    //creamos puntero compartido con un char.
    std::shared_ptr<char>punteroCompartido = std::make_shared<char>('R');
    //mostramos el contenido del puntero compartido.
    std::cout << *punteroCompartido << std::endl;
    //mostramos las entidades que lo estan usando
    std::cout << punteroCompartido.use_count() << std::endl;
    {
        {
        std::shared_ptr<char>punteroCompartido2 = punteroCompartido;
        //mostramos de nuevo las entidades y esta debe haber aumentado en 1
        std::cout << punteroCompartido.use_count() << std::endl;
        }
        //al salir del scope el contador de entidades que lo usan ha disminuido en 1.
        std::cout << punteroCompartido.use_count() << std::endl;
        std::shared_ptr<char>punteroCompartido3 = punteroCompartido;
        //aumenta de nuevo
        std::cout << punteroCompartido.use_count()  << std::endl;
    }
    //sale del scope y disminuie de nuevo
    std::cout << punteroCompartido.use_count()  << std::endl;
    
    system("pause>0");
    return 0;
}


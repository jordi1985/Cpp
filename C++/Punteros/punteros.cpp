#include <iostream>
using namespace std;

//////////////////////////////
//Basico
/////////////////////////////

/*
int main() {
    //basics
    int i = 5;
    cout << &i << endl;
    int* ptr = &i;
    cout << ptr << endl;
    //desreferenciar
    cout << *ptr << endl;
    *ptr = 10;
    cout << *ptr << endl;
    cout << i << endl;

    int v;
    int* ptr2 = &v;
    *ptr2 = 7;
    cout << ptr2 << endl;
    cout << v << endl;

    system("pause");
    return 0;

}
*/

/////////////////////////////////////////
//void pointers
/////////////////////////////////////////

/*
void printNumber (int* numberPtr) {
    cout << *numberPtr << endl;
}

void printChar (char* charPtr) {
    cout << *charPtr << endl;
}

void print (void*ptr,char type) {
    switch (type) {
        case 'i': cout << *((int*)ptr) << endl; break;      //hace un cast y trata int* desreferenciandolo
        case 'c': cout << *((char*)ptr) << endl; break;     //hace un cast y trata Char* desreferenciandolo
        case 'f': cout << *((float*)ptr) << endl; break;    //hace un cast y float float*desreferenciandolo
        // idem con cada type
    }
}

int main() {
    
    int number = 8;
    char letter = 'J';
    float Gravity = 9.81;

    //printChar (&letter);
    //printNumber(&number);
    char*puntero = &letter;

    cout << "&letter es:" << &letter << endl; //mostramos el contenido
    cout << "&puntero es:" << &puntero << endl; //mostramos el contenido
    cout << "*puntero es:" << *puntero << endl; //mostramos el contenido
    cout << "puntero es:" << puntero << endl; //mostramos el contenido

    print (&letter, 'c'); //enviamos a la funcion print el contenido de letter
    print(&number, 'i');
    print(&Gravity, 'f');

    system("pause");
    return 0;
}

*/

////////////////////////////////////////////////
//array con Punteros 1
///////////////////////////////////////////////

/*
int main() {
    //int numerosSuerte[5] { 1,2,3,4,5 };
    //cout << numerosSuerte << endl;
    //cout << &numerosSuerte[1] << endl;
    //cout << numerosSuerte[4] << endl;
    //cout << *(numerosSuerte + 4) << endl;

    int numerosSuerte[5];

    for  (int i = 0; i <= 4; i++) {
        cout << "Number: ";
        cin >> numerosSuerte[i];
    }

    for  (int i = 0; i <= 4; i++) {
        cout << *(numerosSuerte + i) << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
*/

////////////////////////////////////////////////
//array con Punteros 2
///////////////////////////////////////////////

/*
int getMin (int num[], int size){
    int min = num[0];
    for (int i = 1; i < size; i++) {
        if (num[i] < min) {
            min = num[i];
        }
    }
    return min;
}

int getMax (int num[], int size){
    int max = num[0];
    for (int i = 1; i < size; i++) {
        if(num[i] > max) {
            max = num[i];
        }
    }
    return max;
}

void getMinAndMax (int num[], int size, int* min, int* max) {

      for (int i = 1; i < size; i++) {
        if (num[i] < *min)
                 *min = num[i];
        if(num[i] > *max)
            *max = num[i];
    }

}

int main(){

    int numeros[5] = { 32,1,4,5,99 };
    //cout << "Min num is " << getMin(numeros,5) << endl;
    //cout << "Max num is " << getMax(numeros,5) << endl;
    int min = numeros[0];
    int max = numeros[0];

    getMinAndMax (numeros, 5, &min, &max);
    cout << "Min es: " << min << endl;
    cout << "Max es: " << max << endl; 

    system ("pause");
    return 0;
}

*/

////////////////////////////////////////////////
//array dinamicas con Punteros
///////////////////////////////////////////////


//no return porque esta en el puntero! BLACK MAGIC!
void getMinAndMax (int num[], int size, int* min, int* max) {

      for (int i = 1; i < size; i++) {
        if (num[i] < *min)
                 *min = num[i];
        if(num[i] > *max)
            *max = num[i];
    }
}

int main () {
    int size;
    cout << "Medida o posiciones de la array: " << endl;
    cin >> size;
    int *miArray = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Numero a insertar en Array[ " << i << "]: ";
        cin >> miArray[i];
    }

    for (int i = 0; i < size; i++) {
        cout << miArray[i] << " ";
    }

    int min = miArray[0];
    int max = miArray[0];

    cout << endl;

    getMinAndMax (miArray, size, &min, &max);
    cout << "Min es: " << min << endl;
    cout << "Max es: " << max << endl;

    system("pause");
    return 0;
}
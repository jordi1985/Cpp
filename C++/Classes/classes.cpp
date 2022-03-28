#include <iostream>
#include <list>
using namespace std;

//////////////////////////////////////////////
//Basics
//////////////////////////////////////////////
/* class youtubeChannel {
    //Atributos por defecto son privados
    public:
        string Name;
        string OwnerName;
        int SubscribersCount;
        list<string> PublishedVideoTitles;
};

int main() {
    youtubeChannel ytChanel;
    ytChanel.Name = "CodeB";
    ytChanel.OwnerName = "Jordi";
    ytChanel.SubscribersCount = 0;
    ytChanel.PublishedVideoTitles = {"C++ OOP", "CNC", "Selenium"};

    cout << ytChanel.Name << endl;
    cout << ytChanel.OwnerName <<  endl;
    cout << ytChanel.SubscribersCount << endl;
    for(string videoTitle: ytChanel.PublishedVideoTitles) {
        cout << videoTitle << endl;
    }

    system("pause");
    return 0;
} */

//////////////////////////////////////////////
// Constructores y metodos
/////////////////////////////////////////////
/* 
class youtubeChannel {
    //Atributos por defecto son privados
    public:
        string Name;
        string OwnerName;
        int SubscribersCount;
        list<string> PublishedVideoTitles;


    //constructor
    youtubeChannel(string name, string ownerName) {
            Name = name;
            OwnerName = ownerName;
            SubscribersCount = 0;
    }
    //metodo
    void GetInfo() {
        cout << Name << endl;
        cout << OwnerName <<  endl;
        cout << SubscribersCount << endl;

        for(string videoTitle: PublishedVideoTitles) {
            cout << videoTitle << endl;
        }
    }
};

int main() {
    youtubeChannel ytChanel ("Jordi1985", "JordiM");
    youtubeChannel ytChanel2 ("Nu", "Nu_S");
    ytChanel.PublishedVideoTitles.push_back("First video");
    ytChanel.PublishedVideoTitles.push_back("second video");
    
    ytChanel.GetInfo();
    ytChanel2.GetInfo();

    system("pause");
    return 0;
}
 */
/////////////////////////////////////////////
// Encapsulado
/////////////////////////////////////////////
/* class youtubeChannel {
    //Atributos por defecto son privados
    private:
        string Name;
        string OwnerName;
        int SubscribersCount;
        list<string> PublishedVideoTitles;

    public:
    //constructor
    youtubeChannel(string name, string ownerName) {
            Name = name;
            OwnerName = ownerName;
            SubscribersCount = 0;
    }
    //metodos
    void GetInfo() {
        cout << Name << endl;
        cout << OwnerName <<  endl;
        cout << SubscribersCount << endl;

        for(string videoTitle: PublishedVideoTitles) {
            cout << videoTitle << endl;
        }
    }

    void Subscribe() {
        SubscribersCount++;
    }

    void UnSubscribe() {
        if (SubscribersCount > 0)
                SubscribersCount--;
    }

    void PublishVideo(string title) {
        PublishedVideoTitles.push_back(title);
    }
};

int main() {
    youtubeChannel ytChanel ("Jordi1985", "JordiM");
    youtubeChannel ytChanel2 ("Nu", "Nu_S");

    ytChanel.Subscribe();
    ytChanel.Subscribe();
    ytChanel.Subscribe();

    ytChanel2.Subscribe();
    ytChanel2.Subscribe();

    ytChanel.PublishVideo("First video");
    ytChanel.PublishVideo("second video");

    ytChanel.GetInfo();
    ytChanel2.GetInfo();

    system("pause");
    return 0;
} */

/////////////////////////////////////////////
// Herencia
/////////////////////////////////////////////
/* 
class youtubeChannel {
    //Atributos por defecto son privados
    private:
        string Name;
        int SubscribersCount;
        list<string> PublishedVideoTitles;
    protected:
         string OwnerName;

    public:
    //constructor
    youtubeChannel(string name, string ownerName) {
            Name = name;
            OwnerName = ownerName;
            SubscribersCount = 0;
    }
    //metodos
    void GetInfo() {
        cout << Name << endl;
        cout << OwnerName <<  endl;
        cout << SubscribersCount << endl;

        for(string videoTitle: PublishedVideoTitles) {
            cout << videoTitle << endl;
        }
    }
    void Subscribe() {
        SubscribersCount++;
    }
    void UnSubscribe() {
        if (SubscribersCount > 0)
                SubscribersCount--;
    }
    void PublishVideo(string title) {
        PublishedVideoTitles.push_back(title);
    }
};
//Heredando la parte publica de la clase madre.
class CookingYoutubeChanel:public youtubeChannel {
public: 
    //usando el constructor de la clase padre
    CookingYoutubeChanel(string name, string ownerName):youtubeChannel(name, ownerName) {

    }
    void Practice() {
        cout << OwnerName << " asdf fasdf,asfd ttqerq9452345" << endl;
    }

};

int main() {

    CookingYoutubeChanel ytChannel3("Jordi picant codi", "Jordi1985");
    CookingYoutubeChanel ytChannel4("Nu moda", "Nu_s");


    ytChannel3.GetInfo();
    ytChannel3.Practice();

    ytChannel4.GetInfo();
    ytChannel4.Practice();

    system("pause");
    return 0;
} */

/////////////////////////////////////////////
// Polimorfismo
/////////////////////////////////////////////
/*
class youtubeChannel {
    //Atributos por defecto son privados
    private:
        string Name;
        int SubscribersCount;
        list<string> PublishedVideoTitles;
    protected:
         string OwnerName;
         int ContentQuality;

    public:
    //constructor
    youtubeChannel(string name, string ownerName) {
            Name = name;
            OwnerName = ownerName;
            SubscribersCount = 0;
            ContentQuality = 0;
    }
    //metodos
    void GetInfo() {
        cout << Name << endl;
        cout << OwnerName <<  endl;
        cout << SubscribersCount << endl;

        for(string videoTitle: PublishedVideoTitles) {
            cout << videoTitle << endl;
        }
    }
    void Subscribe() {
        SubscribersCount++;
    }
    void UnSubscribe() {
        if (SubscribersCount > 0)
                SubscribersCount--;
    }
    void PublishVideo(string title) {
        PublishedVideoTitles.push_back(title);
    }
    void CheckAnalitics() {
        if (ContentQuality < 5) 
            cout << Name << "has bad quality." << endl;
        else 
            cout << Name << "has good quality." << endl;   
    }
};
//Heredando la parte publica de la clase madre.
class CookingYoutubeChanel:public youtubeChannel {
public: 
    //usando el constructor de la clase padre
    CookingYoutubeChanel(string name, string ownerName):youtubeChannel(name, ownerName) {

    }
    void Practice() {
        cout << "practicando recetas y nuevos platos" << endl;
        ContentQuality++;
    }

};
//Heredando la parte publica de la clase madre.
class SingerYoutubeChannel:public youtubeChannel {
public: 
    //usando el constructor de la clase padre
    SingerYoutubeChannel(string name, string ownerName) :youtubeChannel(name, ownerName) {

    }
    void Practice() {
        cout << "cantando nuevas canciones y versiones" << endl;
        ContentQuality++;
    }

};

int main() {

    CookingYoutubeChanel singYtChannel("Jordi cantant", "Jordi1985");
    SingerYoutubeChannel cookYtChannel("Nu kitchen", "Nu_s");
    singYtChannel.GetInfo();
    cookYtChannel.GetInfo();

    singYtChannel.Practice();
    singYtChannel.Practice();
    singYtChannel.Practice();

    cookYtChannel.Practice();
    cookYtChannel.Practice();
    cookYtChannel.Practice();
    cookYtChannel.Practice();
    cookYtChannel.Practice();
    cookYtChannel.Practice();

    youtubeChannel* yt1= &singYtChannel;
    youtubeChannel* yt2= &cookYtChannel;

    yt1->CheckAnalitics();
    yt2->CheckAnalitics();

    system("pause");
    return 0;
}
*/

/////////////////////////////////////////////
//Virtuales y abstractas + herencia + 
/////////////////////////////////////////////
/*

class Instrument {
public:
    virtual void MakeSound() = 0;
};

class Guitarra:public Instrument {
public:
    void MakeSound(){
        cout << "Guitarra sonando..." << endl;
    }
};

class Piano:public Instrument {
    void MakeSound(){
            cout << "Piano sonando..." << endl;
        }
};

int main (){
    //instrumento es un puntero que apunta un objeto tipo instrumento, en este caso Guitarra.
    Instrument* i1=new Guitarra;
    //i1->MakeSound();
    Instrument* i2=new Piano;
    //i2->MakeSound();

    Instrument* instruments[2]= { i1,i2 };
    for (int i=0; i<2;i++) {
        instruments[i]->MakeSound();
    }

    system("pause");
    return 0;
 }
 */
 
/////////////////////////////////////////////
//Sobrecarga de funciones
/////////////////////////////////////////////

int main() {
    car1 +
}

/////////////////////////////////////////////
//clases y funciones amigas 
/////////////////////////////////////////////
/*
class EquilaterTriangle {
private:
    float a;
    float circumference;
    float area;
public:
    void setA(float length){
        a = length;
        circumference = a*3;
        //raiz de 3 = 1,73
        area = (1.73*a*a)/4;
    }

//funcion amiga    
//friend void PrintResults(EquilaterTriangle);
//clase amiga
friend class Homework;

};
class Homework {
public:
    void PrintResults(EquilaterTriangle et) {
        cout << "Circumference = " << et.circumference << endl;
        cout << "area = " << et.area << endl;
    }
};
//funcion global
/* void PrintResults(EquilaterTriangle et) {
    cout << "Circumference = " << et.circumference << endl;
    cout << "area = " << et.area << endl;
}
int main() {

    EquilaterTriangle et;
    et.setA(3);
    Homework h;
    h.PrintResults(et);

    system("pause");
    return 0;
}
*/
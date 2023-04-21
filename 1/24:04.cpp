#include <iostream>

class Samolot{
public:
    int paliwo, dystans, x, y, z, wysokosc;
    char sygnatura;
    
    Samolot(int paliwo, int dystans, int x, int y, int z, int wysokosc,char sygnatura) {
        this->paliwo = paliwo;
        this->dystans = dystans;
        this->x = x;
        this->y = y;
        this->z = z;
         this->dystans = dystans;
         this->wysokosc = wysokosc;
        this->sygnatura = sygnatura;
     }
    
};
void wypisz(Samolot samolot1){
    std::cout<<samolot1.paliwo<<std::endl;
    std::cout<<samolot1.dystans<<std::endl;
    std::cout<<samolot1.x<<std::endl;
    std::cout<<samolot1.y<<std::endl;
    std::cout<<samolot1.z<<std::endl;
    std::cout<<samolot1.wysokosc<<std::endl;
    std::cout<<samolot1.sygnatura<<std::endl;
}
void mniejsza_wysokosc(Samolot dane, int korekta){
    Samolot kopia(dane);
    kopia.wysokosc = kopia.wysokosc - korekta;
    std::cout<<kopia.wysokosc<<std::endl;
    
    
}
int main(){
    Samolot samolot1(500,200,0,0,0,100,1);
    Samolot samolot2(1200,3200,2,5,4,1100,1);
    wypisz(samolot2);
    mniejsza_wysokosc(samolot2, 100);
    
    
}


/*
 Dodaj tablice dynamiczną znaków(*char) jako pole Sygnatura do klasy Samolot czynimy ponownie
 pola prywatne publicznymi
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
// Struktura przechowująca dane o filmach
struct Film {
    string tytul;
    double akcja;
    double romantycznosc;
    double komedia;
    double dramatycznosc;
    double realizm;
    double familijnosc;
};

string rekomendowanyFilm;
Film prUz;
// Algorytm adaptacyjny - próg podobieństwa
    double prog;

int liczbaZmniejszen;
int iloscSerii=0;

    fstream fw;
    bool wyjscie=false;
    int baza_los[50]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};

void pytania(){
    string wybor;
    srand(time(0));
    int losowanie;
    int wylosowana;
    for(int i=0;i<10;i++){
        do{
            losowanie=(rand() % 50)+1;
            wylosowana=baza_los[losowanie-1];
        }while(wylosowana==0);
        baza_los[losowanie-1]=0;
        switch(wylosowana){
            case 1:
            cout <<"Czy lubisz filmy science fiction?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.2;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.2;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.2;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;
            
            case 2:
            cout <<"Czy lubisz filmy akcji?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.3;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.3;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            
            break;

            case 3:
            cout <<"Czy preferujesz filmy dramatyczne?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.3;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.3;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 4:
            cout <<"Czy interesuja Cie filmy komediowe?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.3;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            else{
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.3;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            
            break;

            case 5:
            cout <<"Czy preferujesz filmy animowane?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.2;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.2;
            }
            else{
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.0;
                if(prUz.realizm<3)prUz.realizm+=0.2;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.2;
            }
            break;
            case 6:
            cout <<"Czy lubisz filmy romantyczne?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.3;
                if(prUz.komedia<3)prUz.komedia+=0.2;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            else{
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.2;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            break;

            case 7:
            cout <<"Czy interesuja Cie filmy kryminalne?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 8:
            cout <<"Czy preferujesz filmy przygodowe?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            break;

            case 9:
            cout <<"Czy lubisz filmy fantasy?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.2;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            else{
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.2;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            break;

            case 10:
            cout <<"Czy interesuja Cie filmy dokumentalne?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.2;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 11:
            cout <<"Czy lubisz filmy historyczne?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.2;
                if(prUz.familijnosc<3)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 12:
            cout <<"Czy preferujesz filmy muzyczne?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.0;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            else{
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.0;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            break;

            case 13:
            cout <<"Czy interesuja cie filmy grozy?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.2;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.2;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.0;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 14:
            cout <<"Czy preferujesz thrillery?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.2;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 15:
            cout <<"Czy lubisz filmy familijne?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.2;
                if(prUz.komedia<3)prUz.komedia+=0.2;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.3;
            }
            else{
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            break;

            case 16:
            cout <<"Czy lubisz starsze filmy (przed latami 60.)?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.0;
            }
            else{
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.0;
            }
            break;

            case 17:
            cout <<"Czy preferujesz filmy wojenne?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.2;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 18:
            cout <<"Czy lubisz westerny?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 19:
            cout <<"Czy interesuja Cie filmy detektywistyczne?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja-=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.0;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 20:
            cout <<"Czy lubisz filmy z superbohaterami?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.2;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.0;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.0;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.0;
            }
            break;

            case 21:
            cout <<"Czy preferujesz filmy nowsze (po roku 2015)?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 22:
            cout <<"Czy interesuja Cie filmy gangsterskie?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.2;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 23:
            cout <<"Czy lubisz nurt szeroko pojetego cyberpunk?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 24:
            cout <<"Czy preferujesz filmy psychologiczne?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.2;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 25:
            cout <<"Czy interesuja Cie filmy biograficzne?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja>0)prUz.akcja-=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.2;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.0;
            }
            else{
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.2;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.0;
            }
            break;

            case 26:
            cout <<"Czy lubisz filmy Sergio Leona? (Dobry, zly i brzydki, Pewnego razu..): ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.2;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 27:
            cout <<"Czy lubisz filmy Christophera Nolana?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.2;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 28:
            cout <<"Czy lubisz filmy Stanleya Kubricka?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 29:
            cout <<"Czy lubisz filmy Stevena Spielberga?: ";
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.2;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.2;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            cin>>wybor;
            break;

            case 30:
            cout <<"Czy lubisz filmy Quentina Tarantino?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.2;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.0;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.0;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 31:
            cout <<"Czy lubisz filmy Martina Scorsese?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.2;
                if(prUz.realizm>0)prUz.realizm-=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 32:
            cout <<"Czy lubisz filmy Stanislawa Bareji?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.2;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.0;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            break;

            case 33:
            cout <<"Czy lubisz filmy Francisa Forda Coppoli?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 34:
            cout <<"Czy lubisz filmy Marvela?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.2;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.0;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.0;
            }
            break;

            case 35:
            cout <<"Czy lubisz filmy Woody'ego Allena?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            else{
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.0;
            }
            break;

            case 36:
            cout <<"Czy lubisz filmy Tima Burtona?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.2;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 37:
            cout <<"Czy lubisz filmy Clinta Eastwooda?: (rez. Snajper, Gran Torino) ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.2;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 38:
            cout <<"Czy lubisz filmy Jamesa Camerona?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.2;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.0;
                if(prUz.realizm>0)prUz.realizm-=0.2;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.0;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;
            
            case 39:
            cout <<"Czy lubisz filmy Denisa Villeneuve?: (Blade Runner 2049, Diuna): ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.2;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;
            
            case 40:
            cout <<"Czy lubisz filmy Davida Finchera?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.2;
                if(prUz.realizm>0)prUz.realizm-=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.0;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;
            
            case 41:
            cout <<"Czy lubisz filmy Ridleya Scotta?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.2;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;
            
            case 42:
            cout <<"Czy lubisz filmy Franka Darabonta? (Skazani na Shawshank, Zielona Mila): ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.2;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.0;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.0;
            }
            break;
            
            case 43:
            cout <<"Czy lubisz filmy Wesa Andersona?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.0;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.0;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.0;
            }
            break;
            
            case 44:
            cout <<"Czy lubisz filmy braci Coen? (To nie jest kraj dla starych ludzi, Big Lebowski): ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc-=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.0;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc+=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.0;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.0;
            }
            break;
            
            case 45:
            cout <<"Czy lubisz filmy Andrzeja Wajdy?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.0;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.0;
                if(prUz.romantycznosc>0)prUz.romantycznosc+=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm-=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.0;
            }
            break;
            
            case 46:
            cout <<"Czy lubisz filmy Davida Lyncha?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.2;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.0;
                if(prUz.romantycznosc>0)prUz.romantycznosc+=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.2;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.1;
            }
            break;

            case 47:
            cout <<"Czy lubisz filmy Billa Condona? (Saga Zmierzch, Piekna i Bestia): ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.0;
                if(prUz.romantycznosc<3)prUz.romantycznosc+=0.2;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.0;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.0;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.0;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.0;
            }
            break;

            case 48:
            cout <<"Czy lubisz animacje Toma McGratha? (Madagaskar, Megamocny): ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.0;
                if(prUz.realizm>0)prUz.realizm-=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc+=0.2;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.0;
                if(prUz.romantycznosc>0)prUz.romantycznosc+=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.0;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            break;
            
            case 49:
            cout <<"Czy lubisz filmy Chrisa Columbusa (Harry Potter, Kevin sam w domu): ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.1;
                if(prUz.romantycznosc<3)prUz.romantycznosc-=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.1;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.0;
                if(prUz.realizm>0)prUz.realizm-=0.0;
                if(prUz.familijnosc>0)prUz.familijnosc+=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.1;
                if(prUz.romantycznosc>0)prUz.romantycznosc+=0.0;
                if(prUz.komedia>0)prUz.komedia-=0.1;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.0;
                if(prUz.realizm<3)prUz.realizm+=0.1;
                if(prUz.familijnosc<3)prUz.familijnosc-=0.1;
            }
            break;

            case 50:
            cout <<"Czy lubisz filmy J.J. Abramsa?: ";
            cin>>wybor;
            if(wybor=="TAK"){
                if(prUz.akcja<3)prUz.akcja+=0.2;
                if(prUz.romantycznosc>0)prUz.romantycznosc-=0.1;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc<3)prUz.dramatycznosc+=0.1;
                if(prUz.realizm>0)prUz.realizm-=0.2;
                if(prUz.familijnosc>0)prUz.familijnosc+=0.1;
            }
            else{
                if(prUz.akcja>0)prUz.akcja-=0.2;
                if(prUz.romantycznosc>0)prUz.romantycznosc+=0.0;
                if(prUz.komedia<3)prUz.komedia+=0.0;
                if(prUz.dramatycznosc>0)prUz.dramatycznosc-=0.1;
                if(prUz.realizm<3)prUz.realizm+=0.2;
                if(prUz.familijnosc>0)prUz.familijnosc-=0.1;
            }
            break;
        }
    }
}

// Funkcja polecajaca filmy na podstawie algorytmu adaptacyjnego
vector<string> rekomendowaneFilmy(const vector<Film>& daneFilmow, const Film& prUz, double prog) {
        vector<string> zarekomendowaneFilmy;
        bool poleconyFilm=false;
        prog=1.00;
        liczbaZmniejszen=0;
    do{
    for (const auto& Film : daneFilmow) {
    double podobienstwo = 0.0;
    double sumaWagi = 0.0;

    // Obliczanie podobienstwa dla kazdej kategorii
    double akcjaRoznica =   abs(Film.akcja - prUz.akcja);
    podobienstwo += (3.0 - akcjaRoznica);
    sumaWagi += 3.0;

    double romantycznoscRoznica = abs(Film.romantycznosc - prUz.romantycznosc);
    podobienstwo += (3.0 - romantycznoscRoznica);
    sumaWagi += 3.0;

    double komediaRoznica = abs(Film.komedia - prUz.komedia);
    podobienstwo += (3.0 - komediaRoznica);
    sumaWagi += 3.0;

    double dramatycznoscRoznica = abs(Film.dramatycznosc - prUz.dramatycznosc);
    podobienstwo += (3.0 - dramatycznoscRoznica);
    sumaWagi += 3.0;

    double realizmRoznica = abs(Film.realizm - prUz.realizm);
    podobienstwo += (3.0 - realizmRoznica);
    sumaWagi += 3.0;

    double familijnoscRoznica = abs(Film.familijnosc - prUz.familijnosc);
    podobienstwo += (3.0 - familijnoscRoznica);
    sumaWagi += 3.0;

    // Normalizacja podobienstwa
    podobienstwo /= sumaWagi;

    // Sprawdzanie, czy film spelnia prĂłg podobienstwa
    if (podobienstwo >= prog) {
    zarekomendowaneFilmy.push_back(Film.tytul);
    poleconyFilm=true;
    }
    }
    
    prog-=0.01;
    liczbaZmniejszen++;
    }while(poleconyFilm==false);

    return zarekomendowaneFilmy;
}

void resetPytan(){
    for(int j=0;j<50;j++){
    baza_los[j]=j+1;
    }
    iloscSerii=0;
}

void wyswietlanieWag(){
    cout <<"\nAkcja: "<<prUz.akcja<<endl;
    cout <<"Romantycznosc: "<<prUz.romantycznosc<<endl;
    cout <<"Komedia: "<<prUz.komedia<<endl;
    cout <<"Dramatycznosc: "<<prUz.dramatycznosc<<endl;
    cout<<"Realizm: "<<prUz.realizm<<endl;
    cout<<"Familijnosc: "<<prUz.familijnosc<<endl;
}

void zapisIWyjscie(){
    fw.open("wagi.txt", ios::out);
    if (fw.is_open())
    {
        fw << prUz.akcja << "\n";
        fw << prUz.romantycznosc << "\n";
        fw << prUz.komedia << "\n";
        fw << prUz.dramatycznosc << "\n";
        fw << prUz.realizm << "\n";
        fw << prUz.familijnosc << "\n";
        fw.close();
        wyjscie=true;
    }
    else{ cout << "Blad otwarcia pliku, sproboj ponownie";
    }
}

int main() {
    // przykładowe filmy z ocenami w sześciu kategoriach
    vector<Film> daneFilmow = {
    {"Ojciec Chrzestny (1972)", 2.3, 0.8, 0.3, 2.5, 2.3, 0.3},
    {"Skazani na Shawshank (1994)", 2, 0.3, 0.1, 2, 2.2, 0.2},
    {"Pulp Fiction (1994)", 2.5, 0.5, 1, 1.2, 2.3, 0.2},
    {"Mroczny Rycerz (2008)", 2.6, 0.3, 1, 1.3, 1.9, 0.7},
    {"Lista Schindlera (1993)", 0.3, 1.9, 0.1, 2.5, 2.8,0.5},
    {"Wladca Pierscieni (2001)", 2.5, 1, 2, 1.8, 0.9, 2.6},
    {"Fight Club (1999)", 2.4, 1, 0.5, 1.8,2.5,0.8},
    {"Chlopcy z ferajny (1990)", 2,1,0.5,1.8,2.7,0.5},
    {"Incepcja (2010)",2.5,0.8,0.8,2,1.8,0.9},
    {"Matrix (1999)",2.6,1,0.8,1.9,1.9,1.2},
    {"Star Wars (1980)",2.1,0.8,0.8,1.4,1,1.3},
    {"Siedmiu samurajow (1954)",1.9,1.3,1,1.8,2,0.5},
    {"Miasto Boga (2002)",1.7,1.7,0.8,2.5,2.6,0.8},
    {"Milczenie owiec (1991)", 1.2,0.2,0.4,2.1,2,0.6},
    {"Podejrzani (The Usual Suspects) (1995)", 1.7,0.6,0.6,2,2,0.6},
    {"Casablanca (1942)",1.8,2.3,1,1.6,2.3,1},
    {"Krol Lew (1994)",2,1.8,2,1.6,1.5,3},
    {"Forrest Gump (1994)",1.5,2.2,1.3,2,2.1,1.8},
    {"Przeminelo z wiatrem (1939)", 0.8,2,1.2,2,2.6,1},
    {"Czarnoksieznik z Oz (1939)", 1.2,1.1,2.1,1,1.8,2.7},
    {"Dzwieki muzyki (1965)",0.7,2.5,1.7,2,2.4,1.5},
    {"Lawrence z Arabii (1962)", 1.8,1,0.5,1.8,2.8,1},
    {"Powrot do Przyszlosci (1985)",1.9,0.7,1.6,1.5,1.4,2.2},
    {"Zakochany bez pamieci (2004)", 0.8, 2.8,0.5,2.7,2.5,1.3},
    {"Whiplash (2014)",1,1.8,0.7,2.7,2.5,0.8},
    {"Infiltracja (2006)",2,0.7,1,2,2.3,0.8},
    {"Gladiator (2000)",2.1,1.5,0.4,2,1.9,0.9},
    {"Zielona Mila (1999)",0.8,1,0.3,2.7,2.7,1},
    {"Czas Apokalipsy (1979)",2,0.5,0.5,2.5,2.5,0.3},
    {"Lsnienie (1980)",1.9,0.3,0.2,1.9,2,0.2},
    {"Dobry, Zly i Brzydki (1966)",2,0.5,0.7,1.6,1.9,0.7},
    {"The Grand Budapest Hotel (2014)",1.2,1,2.1,2.1,2,0.9},
    {"Blade Runner (1982)",1.8,1,0.4,2,1.3,0.4},
    {"Wielki Gatsby (2013)",1,0.8,1.2,2,2.2,1},
    {"The Social Network (2010)",0.9,0.5,0.5,1.5,2.9,1.6},
    {"Bekarty wojny (2009)", 2.3,0.8,1.8,1.5,1.6,0.5},
    {"Requiem dla snu (2000)",0.9,2,0.8,2,2.6,0.9},
    {"Avatar (2009)",2.7,1,0.8,1.5,1,1.9},
    {"Joker (2019)",1.7,0.9,0.9,2.7,2.4,0.3},
    {"Diuna (2021)",2.3,1,1,1.7,0.9,1.3},
    {"Leon Zawodowiec (1994)",1.5,1.4,0.8,1.9,2.6,0.8},
    {"Czlowiek z blizna (1983)",2.1,0.7,0.7,1.9,2.7,0.7},
    {"Coco (2017)",1.9,1.5,2,1,1.5,3},
    {"Szeregowiec Ryan (1998)",2.4,1,0.7,2,2.5,0.8},
    {"Avengers Wojna bez granic (2018)",2.8,0.9,1.3,1,1.5,2.4},
    {"Dzien Swira (2002)",1.5,0.8,2.5,2.3,2.7,1},
    {"Mis (1981)",1.3,0.5,2.8,1.8,2.7,1.2},
    {"Jestes Bogiem (2012)",1.4,1.3,0.8,2.1,2.8,0.7}
    };

    // Przykładowy film użytkownika, dla którego chcemy polecić inne filmy
    prUz.akcja = 0.5;
    prUz.romantycznosc = 0.5;
    prUz.komedia = 0.5;
    prUz.dramatycznosc=0.5;
    prUz.realizm=0.5;
    prUz.familijnosc=0.5;

    // Zczytywanie wag z pliku txt
    fw.open("wagi.txt", ios::in);
    if (fw.is_open()){
        string wa;
        float linia[6];
        int N=0;
        while(getline(fw, wa)){
            linia[N]=stof(wa);
            N++;
        }
        fw.close();
        
        prUz.akcja=linia[0];
        prUz.romantycznosc=linia[1];
        prUz.komedia=linia[2];
        prUz.dramatycznosc=linia[3];
        prUz.realizm=linia[4];
        prUz.familijnosc=linia[5]; 
    }

    cout <<"DORADCA FILMOWY\n";
    cout <<"Program zadaje 10 z 50 pytan TAK/NIE dotyczacych gustow filmowych, po czym poleci Tobie film bazujac na Twoich wyborach.\n";
    cout <<"ODPOWIEDZI NALEZY PODAWAC DUZYMI LITERAMI TAK LUB NIE.\n";
    
    int menu;
    do{
        cout <<"\nMenu:\n";
        cout <<"1. Seria pytan i rekomendacja filmu\n";
        cout <<"2. Reset puli pytan\n";
        cout <<"3. Wyswietlenie wartosci wag uzytkownika\n";
        cout <<"4. Wyjscie i zapis wag uzytkownika\n";
        cout <<"Opcja: ";
        cin>>menu;
        switch(menu){
            case 1:{
                if(iloscSerii<5){
                iloscSerii++; 
                pytania();
                // Polecanie filmu użytkownikowi
                vector<string> zarekomendowaneFilmy = rekomendowaneFilmy(daneFilmow, prUz, prog);
                // Wyświetlanie polecanego filmu
                cout << "\nZarekomendowany Film:" << endl;
                for (const auto& Film : zarekomendowaneFilmy) {
                    cout << Film << endl;
                }
                cout<<"Ilosc potrzebnych zmniejszen progu pasujacego filmu: "<<liczbaZmniejszen-1<<"\n";
                }
                else{
                    cout<<"*************\nZresetuj pule pytan.\n*************\n";
                }
                break;
             }
             case 2:{
                resetPytan();
                break;
             }
             case 3:{
                wyswietlanieWag();
                break;
             }
             case 4:{
                zapisIWyjscie();
                break;
             }
             default: {
                cout <<"Bledna opcja\n";
                break;
             }
            }
    }while(wyjscie==false);
}
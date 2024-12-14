#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;
void generate_kartu (string cards[]){
    string lambang[]= {"waru","hati","wajik","keriting"};
    string angka []= {"as","2","3","4","5","6","7","8","9","10","jack","queen","king"};
    for (int i = 0;i<4;i++){
        for (int j=0;j<13;j++){
            cards[i*13+j]=angka[j]+ " "+ lambang [i];
        }
    }
}
int main()
{
    int simpanrand;
    char kocok;
    string cards [52];
    string cardsshuffel[52];
    srand(time(0));
    generate_kartu(cards);
    for (int i = 0; i<52;i++){
        cout<< cards[i]<<endl;
    }
    cout << endl<< "input " << "a "<< "to random shuffle: "<<endl;
    cin >> kocok;

    if (kocok == 'a'){

        for (int i = 0;i<52;i++){

            do {
                simpanrand = rand()%52;
                cardsshuffel[i]= cards[simpanrand];
            }while (cards[simpanrand] == "uwow");
            cards[simpanrand]= "uwow";


        }
        for (int i = 0;i<52;i++){
            cout << cardsshuffel[i] <<endl;
        }
    }



    return 0;
} 
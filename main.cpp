#include <iostream>
#include <ctime>
#include <string>

using namespace std;


void generate_kartu(string cards[]){
    string lambang[] = {"Waru", "Hati", "Wajik", "Keriting"};
    string angka[] = {"As", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh", "Jack", "Queen", "King"};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cards[i*13+j] = (angka[j] + " " + lambang[i]);
        }
    }
}

int randomCard(){
    int kartuAcak;
    kartuAcak = rand () % 53;

    return kartuAcak;
}

int main()
{
    srand(time(0));
    string cards[52];
    generate_kartu(cards);
    string tebakan;

    int kartuBot;
    kartuBot = randomCard();

    cout << "= Game Tebak Kartu =" << endl;
    cout << "[?]" << endl;
    cout << "Contoh jawaban tebakan kartu: As Waru" << endl;
//    cout << cards[kartuBot] << endl;
    do {
        cout << "Tebakan: ";
        getline(cin, tebakan);

        if(tebakan == cards[kartuBot]){
            cout << "Tebakan Anda Benar !!!" << endl;
        } else {
            cout << "Tebakan Salah !!! Coba Lagi" << endl;
        }
    }while(tebakan != cards[kartuBot]);

    return 0;
}

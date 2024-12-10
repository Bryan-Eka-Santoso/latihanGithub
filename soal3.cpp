#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

void generate_kartu(string cards[]) {
    string lambang[] = {"Waru", "Hati", "Wajik", "Keriting"};
    string angka[] = {"As", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh", "Jack", "Queen", "King"};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cards[i * 13 + j] = (angka[j] + " " + lambang[i]);
        }
    }
}

int hitung_total(const string &kartus) {
    stringstream ss(kartus);
    string kartu;
    int total = 0;
    int jumlah_as = 0;

    while (ss >> kartu) {
        if (kartu == "Dua") total += 2;
        else if (kartu == "Tiga") total += 3;
        else if (kartu == "Empat") total += 4;
        else if (kartu == "Lima") total += 5;
        else if (kartu == "Enam") total += 6;
        else if (kartu == "Tujuh") total += 7;
        else if (kartu == "Delapan") total += 8;
        else if (kartu == "Sembilan") total += 9;
        else if (kartu == "Sepuluh" || kartu == "Jack" || kartu == "Queen" || kartu == "King") total += 10;
        else if (kartu == "As") {
            total += 11;
            jumlah_as++;
        }
    }

    while (total > 21 && jumlah_as > 0) {
        total -= 10; // Mengubah nilai As dari 11 menjadi 1
        jumlah_as--;
    }

    return total;
}

int main() {
    srand(time(0));

    string cards[52];
    generate_kartu(cards);

    char yn;
    string kartuku, kartumu;
    string hitstay;

    do {
        // Reset kartu
        kartuku = "";
        kartumu = "";

        // Bagi kartu awal
        kartuku += (" " + cards[rand() % 52]);
        kartuku += (" " + cards[rand() % 52]);
        kartumu += (" " + cards[rand() % 52]);

        // Giliran pemain
        do {
            cout << "Your cards: " << kartuku << " (Total: " << hitung_total(kartuku) << ")" << endl;
            cout << "Computer's cards: " << kartumu << " ?   (Total: Hidden)" << endl;
            cout << "Hit or stay: ";
            cin >> hitstay;

            if (hitstay == "hit") {
                kartuku += (" " + cards[rand() % 52]);
            }

        } while (hitstay == "hit" && hitung_total(kartuku) < 21);

        if (hitung_total(kartuku) > 21) {
            cout << "You lose! Your total exceeds 21." << endl;
        } else {
            // Giliran komputer
            kartumu += (" " + cards[rand() % 52]);
            cout << "Your turn is over. Computer will now draw cards." << endl;
            while (hitung_total(kartumu) < 16) {
                kartumu += (" " + cards[rand() % 52]);
            }

            cout << "Your final cards: " << kartuku << " (Total: " << hitung_total(kartuku) << ")" << endl;
            cout << "Computer's final cards: " << kartumu << " (Total: " << hitung_total(kartumu) << ")" << endl;

            // Menentukan pemenang
            if (hitung_total(kartumu) > 21) {
                cout << "You win! Computer's total exceeds 21." << endl;
            } else if (hitung_total(kartuku) > hitung_total(kartumu)) {
                cout << "You win! Your total is higher." << endl;
            } else if (hitung_total(kartuku) < hitung_total(kartumu)) {
                cout << "You lose! Computer's total is higher." << endl;
            } else {
                cout << "It's a tie!" << endl;
            }
        }

        cout << "Play again? (y/n): ";
        cin >> yn;

    } while (yn == 'y');

    return 0;
}

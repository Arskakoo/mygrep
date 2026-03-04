#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string text;
    string fileRoute = "testText.txt"; // Kovakoodattu testText tiedosto jossa valmis teksti

    // Tulostaa tyhjän ja ohjelman nimen
    cout << endl;
    cout << "MyGrep" << endl;

    // Kysytään lause / merkkijono
    cout << "Anna haettava sana tai lause: ";
    getline( cin, text);

    ifstream file(fileRoute);

    // Tarkistetaan onnistuuko tiedoston avaus
    if (!file.is_open()) {
        cout << "Virhe: tiedostoa ei voitu avata."<< endl;
        return 1;
    }

    string row;
    int rowN = 0;

    // Luetaan tiedoston rivi kerrallaan
    while ( getline( file, row)) {
        rowN++; // Rivinumerot

        // Tarkistetaan loytyyko lause / merkkijono riviltä
        if (row.find(text) !=  string::npos) {
            cout << rowN << ": " << row <<  endl;
        }
    }

    file.close(); // sulkee tiedoston
    return 0;
}
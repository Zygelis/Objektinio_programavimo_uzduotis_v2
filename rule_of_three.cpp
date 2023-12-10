#include "headers/my_lib.h"
#include "headers/deklaravimai.h"

int main(){

    Studentas studentas;

    cout << "Ivedamas studentas " << endl;
    cin >> studentas;
    cout << "Isvedamas studentas " << endl;
    cout << studentas << endl;

    cout << "Rule of three demonstravimas " << endl;
    cout << "Studentas s1: " << endl;
    Studentas s1("Vardas", "Pavarde", {10, 9, 7}, 10);
    cout << s1 << endl;

    cout << "Kopijuojamas s1 i s2 ";
    cout << "Studentas s2: " << endl;
    Studentas s2(s1);
    cout << s2 << endl;

    cout << "Priskiriamas s1 s3 ";
    cout << "Studentas s3: " << endl;
    Studentas s3;
    s3 = s1;
    cout << s3 << endl;

    // Paleidimas:
    // g++ rule_of_three.cpp -o rule_of_three

    return 0;
}
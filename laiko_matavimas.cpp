#include "headers/my_lib.h"
#include "headers/deklaravimai.h"

int main(){

    cout << "Pagal ka norite rusiuoti duomenis: ";
    cout << "1 - pagal vardus, 2 - pagal pavardes, 3 - pagal galutini bala" << endl;
    int rusiavimo_pasirinkimas;
    cin >> rusiavimo_pasirinkimas;

    while (rusiavimo_pasirinkimas != 1 && rusiavimo_pasirinkimas != 2 && rusiavimo_pasirinkimas != 3) {
        cout << "Ivestas netinkamas pasirinkimas. Bandykite dar karta: " << endl;
        cout << "1 - pagal vardus, 2 - pagal pavardes, 3 - pagal galutini bala" << endl;
        cin >> rusiavimo_pasirinkimas;
    }

    cout << "Class 1000" << endl;
    laiko_skaicuokle_c(1000, 5, rusiavimo_pasirinkimas);
    cout << "Class 10000" << endl;
    laiko_skaicuokle_c(10000, 5, rusiavimo_pasirinkimas);
    cout << "Class 100000" << endl;
    laiko_skaicuokle_c(100000, 5, rusiavimo_pasirinkimas);
    cout << "Class 1000000" << endl;
    laiko_skaicuokle_c(1000000, 5, rusiavimo_pasirinkimas);
    cout << "Class 10000000" << endl;
    laiko_skaicuokle_c(10000000, 5, rusiavimo_pasirinkimas);

    // Paleidimas:
    // g++ laiko_matavimas.cpp funkcijos.cpp ivestis.cpp -o laiko_matavimas
    //./laiko_matavimas
    
    return 0;
}
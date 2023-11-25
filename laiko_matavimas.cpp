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

    // cout << "List" << endl;
    // laiko_skaicuokle_list(1000, 5, rusiavimo_pasirinkimas);
    // cout << "Vector" << endl;
    // laiko_skaicuokle(1000, 5, rusiavimo_pasirinkimas);

    // cout << "List" << endl;
    // laiko_skaicuokle_list(10000, 5, rusiavimo_pasirinkimas);
    // cout << "Vector" << endl;
    // laiko_skaicuokle(10000, 5, rusiavimo_pasirinkimas);

    // cout << "List" << endl;
    // laiko_skaicuokle_list(100000, 5, rusiavimo_pasirinkimas);
    // cout << "Vector" << endl;
    // laiko_skaicuokle(100000, 5, rusiavimo_pasirinkimas);

    // cout << "List" << endl;
    // laiko_skaicuokle_list(1000000, 5, rusiavimo_pasirinkimas);
    // cout << "Vector" << endl;
    // laiko_skaicuokle(1000000, 5, rusiavimo_pasirinkimas);

    // cout << "List" << endl;
    // laiko_skaicuokle_list(10000000, 5, rusiavimo_pasirinkimas);
    // cout << "Vector" << endl;
    // laiko_skaicuokle(10000000, 5, rusiavimo_pasirinkimas);
    // g++ laiko_matavimas.cpp funkcijos.cpp ivestis.cpp -o laiko_matavimas
    //./laiko_matavimas
    cout << "Class 1000" << endl;
    laiko_skaicuokle_c(1000, 5, rusiavimo_pasirinkimas);
    cout << "Class 10000" << endl;
    laiko_skaicuokle_c(10000, 5, rusiavimo_pasirinkimas);
    // laiko_skaicuokle_c(100000, 5, rusiavimo_pasirinkimas);
    // laiko_skaicuokle_c(1000000, 5, rusiavimo_pasirinkimas);
    // laiko_skaicuokle_c(10000000, 5, rusiavimo_pasirinkimas);

    return 0;
}
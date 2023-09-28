#include "my_lib.h"

int main()
{
    studentas laikinas;
    vector<studentas> grupe;
    char vm_pasirinkimas;
    int n;

    cout << "Pasirinkite ivedimo buda: " << endl;
    cout << "1 - ivedimas is failo" << endl;
    cout << "2 - ivedimas ranka" << endl;
    cout << "3 - sugeneravimas atsitiktinai" << endl;
    int ivedimo_pasirinkimas;
    cin >> ivedimo_pasirinkimas;
    // jei pasirinkimas neteisingas, ivedimas kartojamas
    while (ivedimo_pasirinkimas != 1 && ivedimo_pasirinkimas != 2 && ivedimo_pasirinkimas != 3)
    {
        cout << "Neteisinga pasirinkimo reiksme. Iveskite 1, 2 arba 3." << endl;
        cout << "1 - ivedimas is failo" << endl;
        cout << "2 - ivedimas ranka" << endl;
        cout << "3 - sugeneravimas atsitiktinai" << endl;
        cin >> ivedimo_pasirinkimas;
    }

    cout << "Skaiciuoti galutini bala vidurkiu (v) arba mediana (m)? ";
    cin >> vm_pasirinkimas;
    if (vm_pasirinkimas != 'v' && vm_pasirinkimas != 'm' && vm_pasirinkimas != 'V' && vm_pasirinkimas != 'M')
    {
        cout << "Neteisinga pasirinkimo reiksme. Automatiskai naudojamas vidurkis." << endl;
        vm_pasirinkimas = 'v';
    }

    if (ivedimo_pasirinkimas == 1)
    {
        ivedimas_is_file(grupe, vm_pasirinkimas);
    }
    else
    {
        if (ivedimo_pasirinkimas == 2)
            cout << "Kadangi pasirinkote ivedima ranka." << endl;
        if (ivedimo_pasirinkimas == 3)
            cout << "Kadangi pasirinkote sugeneravima atsitiktinai." << endl;
        cout << "Keliu studentu galutini bala norite suskaiciuoti ? ";
        cin >> n;
        if (n < 1)
        {
            cout << "Neteisinga ivestis. Iveskite skaiciu didesni uz 0." << endl;
            return 0;
        }

        for (int j = 0; j < n; j++)
        {
            if (ivedimo_pasirinkimas == 2)
            {
                // ivedama ranka
                laikinas = rankinis_ivedimas();
                // skaiciuojamas galutinis balas
                laikinas.rez = galutinio_balo_skaiciavimas(vm_pasirinkimas, laikinas);
                grupe.push_back(laikinas);
                laikinas.paz.clear();
                continue;
            }
            else
            {
                // sugeneruojama atsitiktinai
                laikinas = atsitiktinis_ivedimas();
                // skaiciuojamas galutinis balas
                laikinas.rez = galutinio_balo_skaiciavimas(vm_pasirinkimas, laikinas);
                grupe.push_back(laikinas);
                laikinas.paz.clear();
                continue;
            }
        }
    }

    // surusiuojama pagal varda
    // SITOJE VERSIJOJE NERUSIUOJAMA NES TADA LABAI ISSIMETO DUOMENYS LENTELEJE, KADANGI VARDAI YRA VARDAS1 VARDAS2 VARDAS3 IR T.T.
    //std::sort(grupe.begin(), grupe.end(), palyginimas_pagal_varda);
    
    // spausdinama lentele
    if (vm_pasirinkimas == 'm' || vm_pasirinkimas == 'M')
    {
        printf("|%20s|%20s|%20s|\n", "Vardas", "Pavarde", "Galutinis (Med.)");
    }
    else
    {
        printf("|%20s|%20s|%20s|\n", "Vardas", "Pavarde", "Galutinis (Vid.)");
    }
    // spausdinama pagal pasirinkima, arba vidurkis, arba mediana:
    printf("|--------------------|--------------------|--------------------|\n");
    for (auto &a : grupe)
        printf("|%20s|%20s|%20.2f|\n", a.vardas.c_str(), a.pavarde.c_str(), a.rez); // %20.2f - %20 simboliu plotis, 2f skaiciai po kablelio
    // panasiai kaip su - cout << std::fixed << std::setprecision(2) << a.rez << endl;
    printf("|--------------------|--------------------|--------------------|\n");
}
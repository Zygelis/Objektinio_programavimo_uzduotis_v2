#include "my_lib.h"

int main()
{
    studentas laikinas;
    vector<studentas> grupe;
    char vm_pasirinkimas;
    int n;

    cout << "Skaiciuoti galutini bala vidurkiu (v) arba mediana (m)? ";
    cin >> vm_pasirinkimas;
    if (vm_pasirinkimas != 'v' && vm_pasirinkimas != 'm' && vm_pasirinkimas != 'V' && vm_pasirinkimas != 'M')
    {
        cout << "Neteisinga pasirinkimo reiksme. Naudojamas vidurkis." << endl;
        vm_pasirinkimas = 'v';
    }

    cout << "Kiek studentu norite ivesti? ";
    cin >> n;
    if (n < 1)
    {
        cout << "Neteisinga ivestis. Iveskite skaiciu didesni uz 0." << endl;
        return 0;
    }

    for (int j = 0; j < n; j++)
    {
        cout << (j + 1) << "-ojo studento pazymius ir egzamina ivesite patys (p) ar norite sugeneruoti atsitiktinai (a)? ";
        char ivesties_pasirinkimas;
        cin >> ivesties_pasirinkimas;
        // jei pasirinkimas neteisingas, ivedimas kartojamas
        while (ivesties_pasirinkimas != 'p' && ivesties_pasirinkimas != 'a' && ivesties_pasirinkimas != 'P' && ivesties_pasirinkimas != 'A') 
        {
            cout << "Neteisinga pasirinkimo reiksme. Iveskite p arba a." << endl;
            cin >> ivesties_pasirinkimas;
        }
        if (ivesties_pasirinkimas == 'p' || ivesties_pasirinkimas == 'P')
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

    // surusiuojama pagal varda
    std::sort(grupe.begin(), grupe.end(), palyginimas_pagal_varda);
    // spausdinama lentele
    if (vm_pasirinkimas == 'm')
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
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

    for (int j = 0; j < n; j++) {
        cout << "Ar " << (j + 1) << "-ojo studento pazymius norite ivesti ranka? (t/n) ";
        char ivesties_pasirinkimas;
        cin >> ivesties_pasirinkimas;
        // jei pasirinkimas neteisingas, ivedimas kartojamas
        while (ivesties_pasirinkimas != 't' && ivesties_pasirinkimas != 'n')
        {
            cout << "Neteisinga pasirinkimo reiksme. Iveskite t arba n." << endl;
            cin >> ivesties_pasirinkimas;
        }
        if (ivesties_pasirinkimas == 't')
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
    printf("|%20s|%20s|%20s|\n", "Vardas", "Pavarde", "Galutinis (Med.)");
    // spausdinama pagal pasirinkima, arba vidurkis, arba mediana:
    if (vm_pasirinkimas == 'm')
    {
        printf("|--------------------|--------------------|--------------------|\n");
        for (auto &a : grupe)
            printf("|%20s|%20s|%20.2f|\n", a.vardas.c_str(), a.pavarde.c_str(), a.rez); // %20.2f - %20 simboliu plotis, 2f skaiciai po kablelio
        // panasiai kaip su - cout << std::fixed << std::setprecision(2) << a.rez << endl;
        printf("|--------------------|--------------------|--------------------|\n");
    }
    else
    {
        printf("|--------------------|--------------------|--------------------|\n");
        for (auto &a : grupe)
            printf("|%20s|%20s|%20.2f|\n", a.vardas.c_str(), a.pavarde.c_str(), a.rez); // %20.2f - %20 simboliu plotis, 2f skaiciai po kablelio
        // panasiai kaip su - cout << std::fixed << std::setprecision(2) << a.rez << endl;
        printf("|--------------------|--------------------|--------------------|\n");
    }
}
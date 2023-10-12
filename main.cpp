#include "my_lib.h"
#include "deklaravimai.h"

int main()
{
    studentas laikinas;
    vector<studentas> grupe;
    char vm_pasirinkimas;
    int n;

    cout << "Sveiki. Norite skaiciuoti galutini bala vidurkiu (v) ar mediana (m)? ";
    cin >> vm_pasirinkimas;
    if (vm_pasirinkimas != 'v' && vm_pasirinkimas != 'm' && vm_pasirinkimas != 'V' && vm_pasirinkimas != 'M')
    {
        // jei pasirinkimas neteisingas, automatiskai naudojamas vidurkis
        cout << "Neteisinga pasirinkimo reiksme. Automatiskai naudojamas vidurkis." << endl;
        vm_pasirinkimas = 'v';
    }

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

    
    if (ivedimo_pasirinkimas == 1)
    {
        cout << "Pasirinkite sugeneruota duomenu faila: " << endl;
        cout << "1 - Studentai1000.txt" << endl;
        cout << "2 - Studentai10000.txt" << endl;
        cout << "3 - Studentai100000.txt" << endl;
        cout << "4 - Studentai1000000.txt" << endl;
        cout << "5 - Studentai10000000.txt" << endl;

        int failo_pasirinkimas;
        cin >> failo_pasirinkimas;
        // jei pasirinkimas neteisingas, ivedimas kartojamas
        while (failo_pasirinkimas != 1 && failo_pasirinkimas != 2 && failo_pasirinkimas != 3 && failo_pasirinkimas != 4 && failo_pasirinkimas != 5)
        {
            cout << "Neteisinga pasirinkimo reiksme. Iveskite 1, 2 arba 3." << endl;
            cout << "1 - Studentai1000.txt" << endl;
            cout << "2 - Studentai10000.txt" << endl;
            cout << "3 - Studentai100000.txt" << endl;
            cout << "4 - Studentai1000000.txt" << endl;
            cout << "5 - Studentai10000000.txt" << endl;
            cin >> failo_pasirinkimas;
        }

        if (failo_pasirinkimas == 1)
        {
            duomenu_kurimas(1000);
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai1000.txt");
        }
        else if (failo_pasirinkimas == 2)
        {
            duomenu_kurimas(10000);
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai10000.txt");
        }
        else if (failo_pasirinkimas == 3)
        {
            duomenu_kurimas(100000);
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai100000.txt");
        }
        else if (failo_pasirinkimas == 4)
        {
            duomenu_kurimas(1000000);
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai1000000.txt");
        }
        else
        {
            duomenu_kurimas(10000000);
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai10000000.txt");
        }

    }

    else
    {
        if (ivedimo_pasirinkimas == 2)
            cout << "Kadangi pasirinkote ivedima ranka." << endl;
        if (ivedimo_pasirinkimas == 3)
            cout << "Kadangi pasirinkote sugeneravima atsitiktinai." << endl;

        cout << "Keliu studentu galutini bala norite suskaiciuoti ? ";
        cin >> n;
        while (n < 1)
        {
            cout << "Neteisinga ivestis. Iveskite skaiciu didesni uz 0." << endl;
            cin >> n;
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

    // surusiuojama pagal varda jei taip pasirinkta
    cout << "Ar norite surusiuoti pagal varda? (t/n)" << std::endl;
    char surusiuoti;
    cin >> surusiuoti;

    try
    {
        if (surusiuoti == 't' || surusiuoti == 'T')
        {
            sort(grupe.begin(), grupe.end(), palyginimas_pagal_varda);
            cout << "Sarasa surusiuotas pagal varda." << endl;
        }
        else if (surusiuoti == 'n' || surusiuoti == 'N')
        {
            cout << "Nesurusiuojama." << endl;
        }
        else
        {
            throw std::runtime_error("Neteisingas pasirinkimas. Galima pasirinkti tik 't' arba 'n'. Automatiškai nesurusiuojama.");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ivedimo klaida: " << e.what() << endl;
    }


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
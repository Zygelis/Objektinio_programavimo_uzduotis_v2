#include "my_lib.h"
#include "deklaravimai.h"

int main()
{
    studentas laikinas;
    vector<studentas> grupe;

    vector<studentas> galvočiai;
    vector<studentas> nuskriaustukai;
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
        cout << "2 - ivedimas klaviatura" << endl;
        cout << "3 - failu sugeneravimas (jei atskirai)" << endl;
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

        // matuojam file generavima
        auto start_time = std::chrono::high_resolution_clock::now();

        if (failo_pasirinkimas == 1) {
            duomenu_kurimas(1000);
            cout << "Failo is 1000 irasu generavimo laikas:";
        } else if (failo_pasirinkimas == 2) {
            duomenu_kurimas(10000);
            cout << "Failo is 10000 irasu generavimo laikas:";
        } else if (failo_pasirinkimas == 3) {
            duomenu_kurimas(100000);
            cout << "Failo is 100000 irasu generavimo laikas:";
        } else if (failo_pasirinkimas == 4) {
            duomenu_kurimas(1000000);
            cout << "Failo is 1000000 irasu generavimo laikas:";
        } else {
            duomenu_kurimas(10000000);
            cout << "Failo is 10000000 irasu generavimo laikas:";
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        cout  << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << endl;
        cout  << duration.count() / 1000 << " seconds" << endl;

        // matuojam ivedima is file
        start_time = std::chrono::high_resolution_clock::now();

        if (failo_pasirinkimas == 1) {
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai1000.txt");
            cout << "Failo is 1000 nuskaitymo laikas:";
        } else if (failo_pasirinkimas == 2) {
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai10000.txt");
            cout << "Failo is 10000 nuskaitymo laikas:";
        } else if (failo_pasirinkimas == 3) {
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai100000.txt");
            cout << "Failo is 100000 nuskaitymo laikas:";
        } else if (failo_pasirinkimas == 4) {
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai1000000.txt");
            cout << "Failo is 1000000 nuskaitymo laikas:";
        } else {
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai10000000.txt");
            cout << "Failo is 10000000 nuskaitymo laikas:";
        }

        end_time = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        std::cout << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << std::endl;
    }

    else if (ivedimo_pasirinkimas == 2)
    {

        cout << "Pasirinkote ivedima klaviatura. " << endl;
        cout << "Ar norite: " << endl;
        cout << "1 - ivedineti pazymiu duomenis ranka" << endl;
        cout << "2 - sugeneruoti pazymiu duomenis atsitiktinai" << endl;

        int pazymiu_pasirinkimas;
        cin >> pazymiu_pasirinkimas;
    
        while (pazymiu_pasirinkimas != 1 && pazymiu_pasirinkimas != 2)
        {
            cout << "Neteisinga pasirinkimo reiksme. Iveskite 1 arba 2." << endl;
            cout << "1 - ivedineti pazymiu duomenis ranka" << endl;
            cout << "2 - sugeneruoti pazymiu duomenis atsitiktinai" << endl;
            cin >> pazymiu_pasirinkimas;
        }

        cout << "Keliu studentu galutini bala norite suskaiciuoti ? ";
        cin >> n;
        while (n < 1)
        {
            cout << "Neteisinga ivestis. Iveskite skaiciu didesni uz 0." << endl;
            cin >> n;
        }

        for (int j = 0; j < n; j++)
        {
            if (pazymiu_pasirinkimas == 1)
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
    else
    {
        cout << "Pasirinkote duomenu sugeneravima." << endl;
        cout << "Kiek studentu norite sugeneruoti? ";
        cin >> n;
        while (n < 1)
        {
            cout << "Neteisinga ivestis. Iveskite skaiciu didesni uz 0." << endl;
            cin >> n;
        }
        duomenu_kurimas(n);
        ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai" + std::to_string(n) + ".txt");
    }

    // // spausdinama lentele
    // if (vm_pasirinkimas == 'm' || vm_pasirinkimas == 'M')
    // {
    //     printf("|%20s|%20s|%20s|\n", "Vardas", "Pavarde", "Galutinis (Med.)");
    // }
    // else
    // {
    //     printf("|%20s|%20s|%20s|\n", "Vardas", "Pavarde", "Galutinis (Vid.)");
    // }
    // // spausdinama pagal pasirinkima, arba vidurkis, arba mediana:
    // printf("|--------------------|--------------------|--------------------|\n");
    // for (auto &a : grupe)
    //     printf("|%20s|%20s|%20.2f|\n", a.vardas.c_str(), a.pavarde.c_str(), a.rez); // %20.2f - %20 simboliu plotis, 2f skaiciai po kablelio
    // // panasiai kaip su - cout << std::fixed << std::setprecision(2) << a.rez << endl;
    // printf("|--------------------|--------------------|--------------------|\n");

    // surusiuojama pagal rezultata
    auto start_time = std::chrono::high_resolution_clock::now();
    sort(grupe.begin(), grupe.end(), palyginimas_pagal_rezultata);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    cout << "Studentu rusiavimas pagal rezultata uztruko: " << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << std::endl;

    // suskirstoma i dvi grupes
    start_time = std::chrono::high_resolution_clock::now();
    rusiuojame_i_dvi_grupes(grupe, nuskriaustukai, galvočiai);
    end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    cout << "Duomenu padalijimas i dvi grupes uztruko: " << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << std::endl;

    // irasom i file galvocius
    start_time = std::chrono::high_resolution_clock::now();
    issaugojam_duomenis(galvočiai, "galvociai.txt");
    end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    cout << "Galvociu irasymo i faila laikas: " << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << std::endl;

    // irasom i file nuskriaustukus
    start_time = std::chrono::high_resolution_clock::now();
    issaugojam_duomenis(nuskriaustukai, "nuskriaustukai.txt");
    end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    cout << "Nuskriaustuku irasymo i faila laikas: " << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << std::endl;
}
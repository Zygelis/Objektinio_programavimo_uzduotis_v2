#include "my_lib.h"
#include "deklaravimai.h"

void main_vector()
{
    studentas laikinas;
    vector<studentas> grupe;

    vector<studentas> galvociai;
    vector<studentas> nuskriaustukai;
    char vm_pasirinkimas;
    int rusiavimo_pasirinkimas;
    int n;

    // Pasirenkama ar skaiciuoti pagal vidurki ar pagal mediana
    cout << "Sveiki. Norite skaiciuoti galutini bala vidurkiu (v) ar mediana (m)? ";
    cin >> vm_pasirinkimas;
    if (vm_pasirinkimas != 'v' && vm_pasirinkimas != 'm' && vm_pasirinkimas != 'V' && vm_pasirinkimas != 'M')
    {
        cout << "Neteisinga pasirinkimo reiksme. Automatiskai naudojamas vidurkis." << endl;
        vm_pasirinkimas = 'v';
    }

    // Pasirenkama pagal ka rusiuoti
    cout << "Pagal ka norite rusiuoti: " << endl;
    cout << "1 - pagal varda" << endl;
    cout << "2 - pagal pavarde" << endl;
    cout << "3 - pagal galutini bala" << endl;
    cin >> rusiavimo_pasirinkimas;
    
    while (rusiavimo_pasirinkimas != 1 && rusiavimo_pasirinkimas != 2 && rusiavimo_pasirinkimas != 3)
    {
        cout << "Neteisinga pasirinkimo reiksme. Iveskite 1, 2 arba 3." << endl;
        cout << "1 - pagal varda" << endl;
        cout << "2 - pagal pavarde" << endl;
        cout << "3 - pagal galutini bala" << endl;
        cin >> rusiavimo_pasirinkimas;
    }

    // Pasirenkamas ivedimo budas
    cout << "Pasirinkite ivedimo buda: " << endl;
    cout << "1 - ivedimas is failo" << endl;
    cout << "2 - ivedimas ranka manualiai arba atsitiktiniu budu" << endl;
    cout << "3 - studentu sugeneravimas atsitiktinai" << endl;
    int ivedimo_pasirinkimas;
    cin >> ivedimo_pasirinkimas;
    
    while (ivedimo_pasirinkimas != 1 && ivedimo_pasirinkimas != 2 && ivedimo_pasirinkimas != 3)
    {
        cout << "Neteisinga pasirinkimo reiksme. Iveskite 1, 2 arba 3." << endl;
        cout << "1 - ivedimas is failo" << endl;
        cout << "2 - ivedimas ranka manualiai arba atsitiktiniu budu" << endl;
        cout << "3 - studentu sugeneravimas atsitiktinai" << endl;
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
        auto start_time = high_resolution_clock::now();

        if (failo_pasirinkimas == 1) {
            duomenu_kurimas(1000);
            cout << "Failo is 1000 irasu generavimo laikas: ";
        } else if (failo_pasirinkimas == 2) {
            duomenu_kurimas(10000);
            cout << "Failo is 10000 irasu generavimo laikas: ";
        } else if (failo_pasirinkimas == 3) {
            duomenu_kurimas(100000);
            cout << "Failo is 100000 irasu generavimo laikas: ";
        } else if (failo_pasirinkimas == 4) {
            duomenu_kurimas(1000000);
            cout << "Failo is 1000000 irasu generavimo laikas: ";
        } else {
            duomenu_kurimas(10000000);
            cout << "Failo is 10000000 irasu generavimo laikas: ";
        }

        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end_time - start_time);

        cout  << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << endl;

        // matuojam ivedima is file
        start_time = high_resolution_clock::now();

        if (failo_pasirinkimas == 1) {
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai1000.txt");
            cout << "Failo is 1000 nuskaitymo laikas: ";
        } else if (failo_pasirinkimas == 2) {
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai10000.txt");
            cout << "Failo is 10000 nuskaitymo laikas: ";
        } else if (failo_pasirinkimas == 3) {
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai100000.txt");
            cout << "Failo is 100000 nuskaitymo laikas: ";
        } else if (failo_pasirinkimas == 4) {
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai1000000.txt");
            cout << "Failo is 1000000 nuskaitymo laikas: ";
        } else {
            ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai10000000.txt");
            cout << "Failo is 10000000 nuskaitymo laikas: ";
        }

        end_time = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end_time - start_time);

        cout << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << endl;
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
        ivedimas_is_file(grupe, vm_pasirinkimas, "Studentai" + to_string(n) + ".txt");
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
    // panasiai kaip su - cout << fixed << setprecision(2) << a.rez << endl;
    printf("|--------------------|--------------------|--------------------|\n");

    if (rusiavimo_pasirinkimas == 1) {
        // surusiuojama pagal varda
        auto start_time = high_resolution_clock::now();
        sort(grupe.begin(), grupe.end(), palyginimas_pagal_varda);
        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end_time - start_time);

        cout << "Studentu rusiavimas pagal varda uztruko: " << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << endl;
    }
    if (rusiavimo_pasirinkimas == 2) {
        // surusiuojama pagal pavarde
        auto start_time = high_resolution_clock::now();
        sort(grupe.begin(), grupe.end(), palyginimas_pagal_pavarde);
        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end_time - start_time);

        cout << "Studentu rusiavimas pagal pavarde uztruko: " << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << endl;
    }
    else {
        // surusiuojama pagal rezultata
        auto start_time = high_resolution_clock::now();
        sort(grupe.begin(), grupe.end(), palyginimas_pagal_rezultata);
        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end_time - start_time);

        cout << "Studentu rusiavimas pagal rezultata uztruko: " << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << endl;
    }

    // irasom i file bendrus rez
    auto start_time = high_resolution_clock::now();
    issaugojam_duomenis(grupe, "bendri_studentu_rezultatai_vector.txt");
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    cout << "Bendru studentu rezultatu irasymas i faila uztruko: " << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << endl;

    // suskirstoma i dvi grupes
    start_time = high_resolution_clock::now();
    rusiuojame_i_dvi_grupes(grupe, nuskriaustukai, galvociai);
    end_time = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end_time - start_time);

    cout << "Duomenu padalijimas i dvi grupes uztruko: " << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << endl;

    // irasom i file galvocius
    start_time = high_resolution_clock::now();
    issaugojam_duomenis(galvociai, "galvociai.txt");
    end_time = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end_time - start_time);

    cout << "Galvociu irasymo i faila laikas: " << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << endl;

    // irasom i file nuskriaustukus
    start_time = high_resolution_clock::now();
    issaugojam_duomenis(nuskriaustukai, "nuskriaustukai.txt");
    end_time = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end_time - start_time);

    cout << "Nuskriaustuku irasymo i faila laikas: " << duration.count() << " milliseconds (" << duration.count() / 1000.0 << " seconds)" << endl;


    if (ivedimo_pasirinkimas == 2){
    for (auto& studentas : grupe) {
    cout << "Studento objekto saugojimo atmintyje adresas: " << &studentas << endl;
    }

    cout << "Grupes objekto saugojimo atmintyje adresas: " << &grupe << endl;
    }
}   
#include "my_lib.h"
#include "deklaravimai.h"


void duomenu_kurimas(int n_eiluciu) {
    std::ofstream isvesties_file("Studentai" + std::to_string(n_eiluciu) + ".txt");

    // antrastine eilute
    isvesties_file << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i = 1; i <= 15; i++) {
        isvesties_file << std::setw(20) << "ND" + std::to_string(i);
    }
    isvesties_file << std::setw(20) << "Egz." << std::endl;

    // generuojami duomenys
    for (int i = 1; i <= n_eiluciu; i++) {
        isvesties_file << std::left << std::setw(20) << "Vardas" + std::to_string(i) << std::setw(20) << "Pavarde" + std::to_string(i);
        srand((unsigned)time(NULL));

        for (int j = 1; j <= 15; j++) {
            int pazymys = rand() % 10 + 1; 
            isvesties_file << std::setw(20) << pazymys;
        }

        int egzaminas = rand() % 10 + 1; 
        isvesties_file << std::setw(20) << egzaminas << std::endl;
    }

    isvesties_file.close();
}


bool palyginimas_pagal_varda(const studentas &a, const studentas &b)
{
    return a.vardas < b.vardas;
}

double galutinio_balo_skaiciavimas(char vm_pasirinkimas, studentas &laikinas)
{
    if (vm_pasirinkimas == 'v' || vm_pasirinkimas == 'V')
    {
        if (laikinas.paz.empty())
        {
            cout << "Tuscias pazymiu vektorius. Todel galinis rezultatas 0" << endl;
            return 0;
        }
        // skaičiuojama pagal vidurki
        double mean = std::accumulate(laikinas.paz.begin(), laikinas.paz.end(), 0.0) / laikinas.paz.size();
        return 0.4 * mean + 0.6 * laikinas.egz;
    }
    else if (vm_pasirinkimas == 'm' || vm_pasirinkimas == 'M')
    {
        if (laikinas.paz.empty())
        {
            cout << "Tuscias pazymiu vektorius. Todel galinis rezultatas 0" << endl;
            return 0;
        }
        // skaičiuojama pagal mediana
        return 0.4 * medianos_skaiciavimas(laikinas.paz) + 0.6 * laikinas.egz;
    }
    else
    {
        // jei pasirinkimas neteisingas, naudojamas vidurkis
        cout << "Neteisinga pasirinkimo reiksme. Naudojamas vidurkis." << endl;
        double mean = std::accumulate(laikinas.paz.begin(), laikinas.paz.end(), 0.0) / laikinas.paz.size();
        return 0.4 * mean + 0.6 * laikinas.egz;
    }
}

double medianos_skaiciavimas(vector<int> vektorius)
{
    int vektoriaus_ilgis = vektorius.size();

    if (vektoriaus_ilgis == 0)
    {
        return 0; // jei vektoriaus dydis lygus 0, grazinamas 0
    }

    std::sort(vektorius.begin(), vektorius.end()); // vektoriaus elementai surusiuojami didejimo tvarka

    if (vektoriaus_ilgis % 2 == 0)
    {
        // jei vektoriaus dydis lyginis, grazinamas vidurkis tarp dvieju viduriniu elementu
        return (vektorius[vektoriaus_ilgis / 2 - 1] + vektorius[vektoriaus_ilgis / 2]) / 2.0;
    }
    else
    {
        // jei vektoriaus dydis nelyginis, grazinamas vidurinis elementas
        return (vektorius[vektoriaus_ilgis / 2]);
    }
}

vector<int> random_skaicius(int n)
{
    // vektorius, kuriame bus saugomi random skaiciai
    vector<int> random_skaiciai;

    // pasirenkam random skaičių generatoriaus seed kaip laiką, nes laikas nuolat keičiasi, todel skaičiai bus vis kitokie kiekviena karta paleidus programą
    srand((unsigned)time(NULL)); // time(NULL) grazina sekundes nuo 1970-01-01; o (unsigned) reikia nes srand praso unsigned int tipo argumento.

    // generuojam n random skaiciu
    for (int i = 1; i <= n; i++)
    {
        // generuojam random skaiciu nuo 1 iki 10
        int random = 1 + (rand() % 10);
        // pridedam random_skaicius i vektoriu
        random_skaiciai.push_back(random);
    }
    // grazinam vektoriu
    return random_skaiciai;
}
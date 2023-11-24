#include "headers/my_lib.h"
#include "headers/deklaravimai.h"


void issaugojam_duomenis_list(const list<studentas_list>& studentai, const string& file_vard) {
    ofstream isvesties_file(file_vard);

    // antrastine eilute
    isvesties_file << left << setw(20) << "Vardas" << setw(20) << "Pavarde";

    isvesties_file << setw(20) << "Rezultatas" << endl;

    // irasomi duomenys
    for (const auto& student : studentai) {
        isvesties_file << left << setw(20) << student.vardas
                       << setw(20) << student.pavarde
                       << setw(20) << student.rez << endl;
    }

    isvesties_file.close();
}


void duomenu_kurimas_list(int n_eiluciu) {
    ofstream isvesties_file("Studentai" + to_string(n_eiluciu) + ".txt");

    srand((unsigned)time(NULL));

    // antrastine eilute
    isvesties_file << left << setw(20) << "Vardas" << setw(20) << "Pavarde";

    for (int i = 1; i <= 15; i++) {
        isvesties_file << setw(20) << "ND" + to_string(i);
    }
    isvesties_file << setw(20) << "Egz." << endl;

    // generuojami duomenys
    for (int i = 1; i <= n_eiluciu; i++) {
        isvesties_file << left << setw(20) << "Vardas" + to_string(i) << setw(20) << "Pavarde" + to_string(i);

        for (int j = 1; j <= 15; j++) {
            int pazymys = rand() % 10 + 1; 
            isvesties_file << setw(20) << pazymys;
        }

        int egzaminas = rand() % 10 + 1; 
        isvesties_file << setw(20) << egzaminas << endl;
    }

    isvesties_file.close();
}


void laiko_skaicuokle_list(int n_eil, int n, int rusiavimo_pasirinkimas) {
    double bendras_laikas_ivedimo = 0.0;
    double bendras_laikas_rusiavimo = 0.0;
    double bendras_laikas_rusiavimo_dvi = 0.0;
    double bendras_laikas_rusiavimo_dvi_2strategija = 0.0;
    double bendras_laikas_rusiavimo_dvi_3strategija = 0.0;
    double bendras_laikas_rusiavimo_dvi_4strategija = 0.0;
    double bendras_laika_issaugojimo_galvociai = 0.0;
    double bendras_laika_issaugojimo_nuskriaustukai = 0.0;
    
    studentas_list laikinas;
    list<studentas_list> grupe;
    list<studentas_list> grupe2;
    list<studentas_list> galvociai;
    list<studentas_list> galvociai2;
    list<studentas_list> nuskriaustukai;
    list<studentas_list> nuskriaustukai2;
    list<studentas_list> grupe3;
    list<studentas_list> galvociai3;
    list<studentas_list> nuskriaustukai3;
    list<studentas_list> grupe4;
    list<studentas_list> galvociai4;
    list<studentas_list> nuskriaustukai4;


    char vm = 'm';
    string filename = "Studentai" + to_string(n_eil) + ".txt";

    for (int i = 0; i < n; i++) {
        grupe.clear();
        galvociai.clear();
        nuskriaustukai.clear();

        auto laikas_pradzia = high_resolution_clock::now();
        ivedimas_is_file_list(grupe, vm, filename);
        auto laikas_pabaiga = high_resolution_clock::now();
        auto laikas_ivedimo = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laikas_ivedimo += static_cast<double>(laikas_ivedimo.count());

        laikas_pradzia = high_resolution_clock::now();
        if (rusiavimo_pasirinkimas == 1) {
            grupe.sort(palyginimas_pagal_varda_list);
        } else if (rusiavimo_pasirinkimas == 2) {
            grupe.sort(palyginimas_pagal_pavarde_list);
        } else {
            grupe.sort(palyginimas_pagal_rezultata_list);
        }
        laikas_pabaiga = high_resolution_clock::now();
        auto laikas_rusiavimo = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laikas_rusiavimo += static_cast<double>(laikas_rusiavimo.count());

        // naudojam 1 strategija
        laikas_pradzia = high_resolution_clock::now();
        rusiuojame_i_dvi_grupes_list(grupe, nuskriaustukai, galvociai);
        laikas_pabaiga = high_resolution_clock::now();
        auto laikas_rusiavimo_dvi = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laikas_rusiavimo_dvi += static_cast<double>(laikas_rusiavimo_dvi.count());

        // nauodjam 2 strategija
        laikas_pradzia = high_resolution_clock::now();
        galvociai2 = grupe;
        galvociai2.sort(palyginimas_pagal_rezultata_list);

        //laikas_pradzia = high_resolution_clock::now();
        rusiuojame_i_dvi_grupes_list_2(galvociai2, nuskriaustukai2);
        laikas_pabaiga = high_resolution_clock::now();
        auto laikas_rusiavimo_dvi_2strategija = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laikas_rusiavimo_dvi_2strategija += static_cast<double>(laikas_rusiavimo_dvi_2strategija.count());

        // nauodjam 3 strategija
        laikas_pradzia = high_resolution_clock::now();
        galvociai3 = grupe;
        rusiuojame_i_dvi_grupes_list_3(galvociai3, nuskriaustukai3);
        laikas_pabaiga = high_resolution_clock::now();
        auto laikas_rusiavimo_dvi_3strategija = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laikas_rusiavimo_dvi_3strategija += static_cast<double>(laikas_rusiavimo_dvi_3strategija.count());
        

        // nauodjam 4 strategija
        grupe4 = grupe;
        laikas_pradzia = high_resolution_clock::now();
        rusiuojame_i_dvi_grupes_list_4(grupe4, nuskriaustukai4, galvociai4);
        laikas_pabaiga = high_resolution_clock::now();
        auto laikas_rusiavimo_dvi_4strategija = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laikas_rusiavimo_dvi_4strategija += static_cast<double>(laikas_rusiavimo_dvi_4strategija.count());


        laikas_pradzia = high_resolution_clock::now();
        string galvociai_pav = "galvociai" + to_string(n_eil) + ".txt";
        issaugojam_duomenis_list(galvociai, galvociai_pav);
        laikas_pabaiga = high_resolution_clock::now();
        auto laikas_issaugojimo_galvociai = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laika_issaugojimo_galvociai += static_cast<double>(laikas_issaugojimo_galvociai.count());

        laikas_pradzia = high_resolution_clock::now();
        string nuskriaustukai_pav = "nuskriaustukai" + to_string(n_eil) + ".txt";
        issaugojam_duomenis_list(nuskriaustukai, nuskriaustukai_pav);
        laikas_pabaiga = high_resolution_clock::now();
        auto laikas_issaugojimo_nuskriaustukai = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laika_issaugojimo_nuskriaustukai += static_cast<double>(laikas_issaugojimo_nuskriaustukai.count());
    }

    cout << "Skaiciuojamas failo " << filename << " laikas" << endl;

    double vid_bendras_laikas_ivedimo = bendras_laikas_ivedimo / static_cast<double>(n);
    double vid_bendras_laikas_rusiavimo = bendras_laikas_rusiavimo / static_cast<double>(n);
    double vid_bendras_laikas_rusiavimo_dvi = bendras_laikas_rusiavimo_dvi / static_cast<double>(n);
    double vid_bendras_laikas_rusiavimo_dvi_2strategija = bendras_laikas_rusiavimo_dvi_2strategija / static_cast<double>(n);
    double vid_bendras_laikas_rusiavimo_dvi_3strategija = bendras_laikas_rusiavimo_dvi_3strategija / static_cast<double>(n);
    double vid_bendras_laikas_rusiavimo_dvi_4strategija = bendras_laikas_rusiavimo_dvi_4strategija / static_cast<double>(n);
    double vid_bendras_laika_issaugojimo_galvociai = bendras_laika_issaugojimo_galvociai / static_cast<double>(n);
    double vid_bendras_laika_issaugojimo_nuskriaustukai = bendras_laika_issaugojimo_nuskriaustukai / static_cast<double>(n);

    cout << "Vidutinis failo nuskaitymo laikas: " << vid_bendras_laikas_ivedimo << " milliseconds (" << vid_bendras_laikas_ivedimo / 1000.0 << " seconds)" << endl;
    cout << "Vidutinis duomenu rusiavimo laikas: " << vid_bendras_laikas_rusiavimo << " milliseconds (" << vid_bendras_laikas_rusiavimo / 1000.0 << " seconds)" << endl;
    cout << "Vidutinis duomenu padalijimas i dvi grupes laikas (1 strategija): " << vid_bendras_laikas_rusiavimo_dvi << " milliseconds (" << vid_bendras_laikas_rusiavimo_dvi / 1000.0 << " seconds)" << endl;
    cout << "Vidutinis duomenu padalijimas i dvi grupes laikas (2 strategija): " << vid_bendras_laikas_rusiavimo_dvi_2strategija << " milliseconds (" << vid_bendras_laikas_rusiavimo_dvi_2strategija / 1000.0 << " seconds)" << endl;
    cout << "Vidutinis duomenu padalijimas i dvi grupes laikas (3 strategija): " << vid_bendras_laikas_rusiavimo_dvi_3strategija << " milliseconds (" << vid_bendras_laikas_rusiavimo_dvi_3strategija / 1000.0 << " seconds)" << endl;
    cout << "Vidutinis duomenu padalijimas i dvi grupes laikas (4 strategija): " << vid_bendras_laikas_rusiavimo_dvi_4strategija << " milliseconds (" << vid_bendras_laikas_rusiavimo_dvi_4strategija / 1000.0 << " seconds)" << endl;
    cout << "Vidutinis galvociu irasymo i faila laikas: " << vid_bendras_laika_issaugojimo_galvociai << " milliseconds (" << vid_bendras_laika_issaugojimo_galvociai / 1000.0 << " seconds)" << endl;
    cout << "Vidutinis nuskriaustuku irasymo i faila laikas: " << vid_bendras_laika_issaugojimo_nuskriaustukai << " milliseconds (" << vid_bendras_laika_issaugojimo_nuskriaustukai / 1000.0 << " seconds)" << endl;
    cout << "Vidutinis bendras laikas: " << vid_bendras_laikas_ivedimo + vid_bendras_laikas_rusiavimo + vid_bendras_laika_issaugojimo_galvociai + vid_bendras_laika_issaugojimo_nuskriaustukai;
    cout << " milliseconds (" << (vid_bendras_laikas_ivedimo + vid_bendras_laikas_rusiavimo + vid_bendras_laika_issaugojimo_galvociai + vid_bendras_laika_issaugojimo_nuskriaustukai) / 1000.0 << " seconds)" << endl;
    cout << endl;
}


void rusiuojame_i_dvi_grupes_list(list<studentas_list>& grupe, list<studentas_list>& nuskriaustukai, list<studentas_list>& galvociai) {
    for (const auto& student : grupe) {
        if (student.rez >= 5.0) {
            galvociai.push_back(student);
        } else {
            nuskriaustukai.push_back(student);
        }
    }
}


void rusiuojame_i_dvi_grupes_list_2(list<studentas_list>& grupe, list<studentas_list>& nuskriaustukai) {
    nuskriaustukai.clear();

    auto iteratorius = grupe.begin();
    while (iteratorius != grupe.end() && iteratorius->rez >= 5.0) {
        ++iteratorius;
    }

    if (iteratorius != grupe.end()) {
        nuskriaustukai.splice(nuskriaustukai.begin(), grupe, iteratorius, grupe.end());
    }
}


void rusiuojame_i_dvi_grupes_list_3(list<studentas_list>& grupe, list<studentas_list>& nuskriaustukai) {
    auto partition_point = std::partition(grupe.begin(), grupe.end(),
        [](const studentas_list& s) {
            return s.rez >= 5;
        });

    nuskriaustukai.splice(nuskriaustukai.end(), grupe, partition_point, grupe.end());
}


void rusiuojame_i_dvi_grupes_list_4(std::list<studentas_list>& grupe, std::list<studentas_list>& nuskriaustukai, std::list<studentas_list>& galvociai) {
    auto partition_point = std::partition(grupe.begin(), grupe.end(), [](const studentas_list& student) {
        return student.rez >= 5.0;
    });

    nuskriaustukai.splice(nuskriaustukai.end(), grupe, grupe.begin(), partition_point);
    galvociai.splice(galvociai.end(), grupe, partition_point, grupe.end());
}


bool palyginimas_pagal_rezultata_list(const studentas_list& a, const studentas_list& b) {
    return a.rez > b.rez;
}


bool palyginimas_pagal_varda_list(const studentas_list &a, const studentas_list &b)
{
    return a.vardas < b.vardas;
}


bool palyginimas_pagal_pavarde_list(const studentas_list &a, const studentas_list &b)
{
    return a.pavarde < b.pavarde;
}


double galutinio_balo_skaiciavimas_list(char vm_pasirinkimas, studentas_list &laikinas)
{
    if (vm_pasirinkimas == 'v' || vm_pasirinkimas == 'V')
    {
        if (laikinas.paz.empty())
        {
            cout << "Tuscias pazymiu list. Todel galinis rezultatas 0" << endl;
            return 0;
        }
        // skaičiuojama pagal vidurki
        double mean = accumulate(laikinas.paz.begin(), laikinas.paz.end(), 0.0) / laikinas.paz.size();
        return 0.4 * mean + 0.6 * laikinas.egz;
    }
    else if (vm_pasirinkimas == 'm' || vm_pasirinkimas == 'M')
    {
        if (laikinas.paz.empty())
        {
            cout << "Tuscias pazymiu list. Todel galinis rezultatas 0" << endl;
            return 0;
        }
        // skaičiuojama pagal mediana
        return 0.4 * medianos_skaiciavimas_list(laikinas.paz) + 0.6 * laikinas.egz;
    }
    else
    {
        // jei pasirinkimas neteisingas, naudojamas vidurkis
        cout << "Neteisinga pasirinkimo reiksme. Naudojamas vidurkis." << endl;
        double mean = accumulate(laikinas.paz.begin(), laikinas.paz.end(), 0.0) / laikinas.paz.size();
        return 0.4 * mean + 0.6 * laikinas.egz;
    }
}


double medianos_skaiciavimas_list(list<int> listas)
{
    int list_ilgis = listas.size();

    if (list_ilgis == 0)
    {
        return 0;
    }

    list<int> sorted(listas);
    sorted.sort(); // list elementai surusiuojami didejimo tvarka

    list<int>::iterator it = sorted.begin();
    advance(it, list_ilgis / 2);

    if (list_ilgis % 2 == 0)
    {
        list<int>::iterator it2 = it;
        it2--;

        // jei list konteinerio lyginis, grazinamas vidurkis tarp dvieju viduriniu elementu
        return (*it + *it2) / 2.0;
    }
    else
    {
        // jei list konteinerio dydis nelyginis, grazinamas vidurinis elementas
        return *it;
    }
}


list<int> random_skaicius_list(int n)
{
    // listas, kuriame bus saugomi random skaiciai
    list<int> random_skaiciai;

    // pasirenkam random skaičių generatoriaus seed kaip laiką, nes laikas nuolat keičiasi, todel skaičiai bus vis kitokie kiekviena karta paleidus programą
    srand((unsigned)time(NULL)); // time(NULL) grazina sekundes nuo 1970-01-01; o (unsigned) reikia nes srand praso unsigned int tipo argumento.

    // generuojam n random skaiciu
    for (int i = 1; i <= n; i++)
    {
        // generuojam random skaiciu nuo 1 iki 10
        int random = 1 + (rand() % 10);
        // pridedam random_skaicius i lista
        random_skaiciai.push_back(random);
    }
    // grazinam lista su random skaiciais
    return random_skaiciai;
}
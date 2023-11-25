#include "headers/my_lib.h"
#include "headers/deklaravimai.h"


void issaugojam_duomenis_c(const vector<Studentas>& studentai, const string& file_vard) {
    ofstream isvesties_file(file_vard);

    // antrastine eilute
    isvesties_file << left << setw(20) << "Vardas" << setw(20) << "Pavarde"
                   << setw(20) << "Rezultatas" << endl;

    // irasomi duomenys
    for (const auto& student : studentai) {
        isvesties_file << left << setw(20) << student.getVardas()
                       << setw(20) << student.getPavarde()
                       << setw(20) << student.getRez() << endl;
    }

    isvesties_file.close();
}

void duomenu_kurimas(int n_eiluciu) {
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

void laiko_skaicuokle_c(int n_eil, int n, int rusiavimo_pasirinkimas) {
    double bendras_laikas_ivedimo = 0.0;
    double bendras_laikas_rusiavimo = 0.0;
    double bendras_laikas_rusiavimo_dvi = 0.0;
    double bendras_laikas_rusiavimo_dvi_2strategija = 0.0;
    double bendras_laikas_rusiavimo_dvi_3strategija = 0.0;
    double bendras_laikas_rusiavimo_dvi_4strategija = 0.0;
    double bendras_laika_issaugojimo_galvociai = 0.0;
    double bendras_laika_issaugojimo_nuskriaustukai = 0.0;

    vector<Studentas> grupe;
    vector<Studentas> galvociai;
    vector<Studentas> nuskriaustukai;

    char vm = 'm';
    string filename = "Studentai" + to_string(n_eil) + ".txt";

    for (int i = 0; i < n; i++) {
        grupe.clear();
        galvociai.clear();
        nuskriaustukai.clear();

        auto laikas_pradzia = high_resolution_clock::now();
        ivedimas_is_file_c(grupe, vm, filename);
        auto laikas_pabaiga = high_resolution_clock::now();
        auto laikas_ivedimo = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laikas_ivedimo += static_cast<double>(laikas_ivedimo.count());

        laikas_pradzia = high_resolution_clock::now();
        if (rusiavimo_pasirinkimas == 1) {
            sort(grupe.begin(), grupe.end(), palyginimas_pagal_varda_c);
        } else if (rusiavimo_pasirinkimas == 2) {
            sort(grupe.begin(), grupe.end(), palyginimas_pagal_pavarde_c);
        } else {
            sort(grupe.begin(), grupe.end(), palyginimas_pagal_rezultata_c);
        }
        laikas_pabaiga = high_resolution_clock::now();
        auto laikas_rusiavimo = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laikas_rusiavimo += static_cast<double>(laikas_rusiavimo.count());

        // naudojam 1 strategija
        laikas_pradzia = high_resolution_clock::now();
        rusiuojame_i_dvi_grupes_c(grupe, nuskriaustukai, galvociai);
        laikas_pabaiga = high_resolution_clock::now();
        auto laikas_rusiavimo_dvi = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laikas_rusiavimo_dvi += static_cast<double>(laikas_rusiavimo_dvi.count());

        // nauodjam 2 strategija
        laikas_pradzia = high_resolution_clock::now();
        vector<Studentas> galvociai2 = grupe;
        sort(galvociai2.begin(), galvociai2.end(), palyginimas_pagal_rezultata_c);
        rusiuojame_i_dvi_grupes_2_c(galvociai2, nuskriaustukai);
        laikas_pabaiga = high_resolution_clock::now();
        auto laikas_rusiavimo_dvi_2strategija = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laikas_rusiavimo_dvi_2strategija += static_cast<double>(laikas_rusiavimo_dvi_2strategija.count());

        // naudojam 3 strategija
        vector<Studentas> galvociai3 = grupe;
        laikas_pradzia = high_resolution_clock::now();
        rusiuojame_i_dvi_grupes_3_c(galvociai3, nuskriaustukai);
        laikas_pabaiga = high_resolution_clock::now();
        auto laikas_rusiavimo_dvi_3strategija = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laikas_rusiavimo_dvi_3strategija += static_cast<double>(laikas_rusiavimo_dvi_3strategija.count());

        // naudojam 4 strategija
        vector<Studentas> grupe4 = grupe;
        laikas_pradzia = high_resolution_clock::now();
        rusiuojame_i_dvi_grupes_4_c(grupe4, nuskriaustukai, galvociai);
        laikas_pabaiga = high_resolution_clock::now();
        auto laikas_rusiavimo_dvi_4strategija = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laikas_rusiavimo_dvi_4strategija += static_cast<double>(laikas_rusiavimo_dvi_4strategija.count());

        // issaugojam galvociu duomenis
        laikas_pradzia = high_resolution_clock::now();
        string galvociai_pav = "galvociai" + to_string(n_eil) + ".txt";
        issaugojam_duomenis_c(galvociai, galvociai_pav);
        laikas_pabaiga = high_resolution_clock::now();
        auto laikas_issaugojimo_galvociai = duration_cast<milliseconds>(laikas_pabaiga - laikas_pradzia);

        bendras_laika_issaugojimo_galvociai += static_cast<double>(laikas_issaugojimo_galvociai.count());

        // issaugojam nuskriaustuku duomenis
        laikas_pradzia = high_resolution_clock::now();
        string nuskriaustukai_pav = "nuskriaustukai" + to_string(n_eil) + ".txt";
        issaugojam_duomenis_c(nuskriaustukai, nuskriaustukai_pav);
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


void rusiuojame_i_dvi_grupes_c(vector<Studentas>& grupe, vector<Studentas>& nuskriaustukai, vector<Studentas>& galvociai) {
    for (const auto& student : grupe) {
        if (student.getRez() >= 5.0) {
            galvociai.push_back(student);
        } else {
            nuskriaustukai.push_back(student);
        }
    }
}

void rusiuojame_i_dvi_grupes_2_c(vector<Studentas>& grupe, vector<Studentas>& nuskriaustukai) {
    nuskriaustukai.clear();

    auto iteratorius = grupe.begin();
    // randam pirmaji studenta su rez < 5
    while (iteratorius != grupe.end() && iteratorius->getRez() >= 5.0) {
        ++iteratorius;
    }

    // Kai randa pirmaji studenta su rez < 5, kopijuoja visus studentus nuo jo iki galo i nuskriaustukus
    if (iteratorius != grupe.end()) {
        nuskriaustukai.assign(iteratorius, grupe.end());
        grupe.erase(iteratorius, grupe.end());
    }
}

void rusiuojame_i_dvi_grupes_3_c(vector<Studentas>& grupe, vector<Studentas>& nuskriaustukai) {
    auto partition_point = std::partition(grupe.begin(), grupe.end(),
        [](const Studentas& s) {
            return s.getRez() >= 5;
        });

    nuskriaustukai.insert(nuskriaustukai.end(), std::make_move_iterator(partition_point), std::make_move_iterator(grupe.end()));
    grupe.erase(partition_point, grupe.end());
}

void rusiuojame_i_dvi_grupes_4_c(vector<Studentas>& grupe, vector<Studentas>& nuskriaustukai, vector<Studentas>& galvociai) {
    auto partition_point = std::partition(grupe.begin(), grupe.end(), [](const Studentas& student) {
        return student.getRez() >= 5.0;
    });
    // elementai tarp [students.begin(), partition_point) turi rez mazesni uz 5.0
    // elementai tarp [partition_point, students.end()) turi rez didesni arba lygu 5.0
    std::move(grupe.begin(), partition_point, std::back_inserter(nuskriaustukai));
    std::move(partition_point, grupe.end(), std::back_inserter(galvociai));
}


bool palyginimas_pagal_rezultata_c(const Studentas& a, const Studentas& b) {
    return a.getRez() > b.getRez();
}

bool palyginimas_pagal_varda_c(const Studentas &a, const Studentas &b)
{
    return a.getVardas() < b.getVardas();
}

bool palyginimas_pagal_pavarde_c(const Studentas &a, const Studentas &b)
{
    return a.getPavarde() < b.getPavarde();
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
#include "my_lib.h"

struct studentas {
    string vardas, pavarde;
    vector <int> paz;
    int egz;
    double rez;
};

void rusiuojame_i_dvi_grupes(std::vector<studentas>& grupe, std::vector<studentas>& nuskriaustukai, std::vector<studentas>& galvočiai);
void issaugojam_duomenis(const vector<studentas>& studentai, const string& file_vard);
void duomenu_kurimas(int numLines);
double medianos_skaiciavimas(vector<int> vec);
vector<int> random_skaicius(int n);
bool palyginimas_pagal_rezultata(const studentas& a, const studentas& b);
bool palyginimas_pagal_varda(const studentas &a, const studentas &b);
void ivedimas_is_file(vector<studentas>& grupe, char vm_pasirinkimas, const string& duom_vard);
studentas rankinis_ivedimas();
studentas atsitiktinis_ivedimas();
double galutinio_balo_skaiciavimas(char vm_pasirinkimas, studentas& laikinas);
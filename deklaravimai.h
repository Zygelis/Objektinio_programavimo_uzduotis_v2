#include "my_lib.h"

struct studentas {
    string vardas, pavarde;
    vector <int> paz;
    int egz;
    double rez;
};

struct studentas_list {
    string vardas, pavarde;
    list <int> paz;
    int egz;
    double rez;
};

// vector
void main_vector();
void ivedimas_is_file(vector<studentas>& grupe, char vm_pasirinkimas, const string& duom_vard);
void rusiuojame_i_dvi_grupes(vector<studentas>& grupe, vector<studentas>& nuskriaustukai, vector<studentas>& galvočiai);
void rusiuojame_i_dvi_grupes_2(vector<studentas>& grupe, vector<studentas>& nuskriaustukai);
void rusiuojame_i_dvi_grupes_3(std::vector<studentas>& grupe, std::vector<studentas>& nuskriaustukai);
void rusiuojame_i_dvi_grupes_4(std::vector<studentas>& students, std::vector<studentas>& nuskriaustukai, std::vector<studentas>& galvociai);
void issaugojam_duomenis(const vector<studentas>& studentai, const string& file_vard);
void duomenu_kurimas(int numLines);
void laiko_skaicuokle(int n_eil, int n, int rusiavimo_pasirinkimas);
double medianos_skaiciavimas(vector<int> vec);
double galutinio_balo_skaiciavimas(char vm_pasirinkimas, studentas& laikinas);
vector<int> random_skaicius(int n);
bool palyginimas_pagal_rezultata(const studentas& a, const studentas& b);
bool palyginimas_pagal_varda(const studentas &a, const studentas &b);
bool palyginimas_pagal_pavarde(const studentas &a, const studentas &b);
studentas rankinis_ivedimas();
studentas atsitiktinis_ivedimas();

// list
void main_list();
void ivedimas_is_file_list(list<studentas_list> &grupe, char vm_pasirinkimas, const string &duom_vard);
void rusiuojame_i_dvi_grupes_list(list<studentas_list>& grupe, list<studentas_list>& nuskriaustukai, list<studentas_list>& galvočiai);
void rusiuojame_i_dvi_grupes_list_2(list<studentas_list>& grupe, list<studentas_list>& nuskriaustukai);
void rusiuojame_i_dvi_grupes_list_3(std::list<studentas_list>& grupe, std::list<studentas_list>& nuskriaustukai);
void rusiuojame_i_dvi_grupes_list_4(std::list<studentas_list>& grupe, std::list<studentas_list>& nuskriaustukai, std::list<studentas_list>& galvociai);
void issaugojam_duomenis_list(const list<studentas_list>& studentai, const string& file_vard);
void duomenu_kurimas_list(int n_eiluciu);
void laiko_skaicuokle_list(int n_eil, int n, int rusiavimo_pasirinkimas);
double medianos_skaiciavimas_list(list<int> vektorius);
double galutinio_balo_skaiciavimas_list(char vm_pasirinkimas, studentas_list& laikinas);
list<int> random_skaicius_list(int n);
bool palyginimas_pagal_rezultata_list(const studentas_list& a, const studentas_list& b);
bool palyginimas_pagal_varda_list(const studentas_list &a, const studentas_list &b);
bool palyginimas_pagal_pavarde_list(const studentas_list &a, const studentas_list &b);
studentas_list atsitiktinis_ivedimas_list();
studentas_list rankinis_ivedimas_list();
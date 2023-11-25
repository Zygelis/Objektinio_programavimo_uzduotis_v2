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

class Studentas {
private:
    string vardas, pavarde;
    vector<int> paz;
    int egz;
    double rez;

public:
    // constructor
    Studentas() {}
    
    Studentas(const Studentas& s) 
        : vardas(s.vardas), pavarde(s.pavarde), paz(s.paz), egz(s.egz), rez(s.rez) {}


    // destructor
    ~Studentas() {}

    // getters and setters
    string getVardas() const { return vardas; }
    void setVardas(const string& v) { vardas = v; }

    string getPavarde() const { return pavarde; }
    void setPavarde(const string& p) { pavarde = p; }

    vector<int> getPaz() const { return paz; }
    // void setPaz(const vector<int>& pzs) {
    //     paz = pzs;
    //     //calculateRez();
    // }
    void setPazs(int p) {
        paz.push_back(p);
        //calculateRez();
    }
    
    int getEgz() const { return egz; }
    void setEgz(int e) {
        egz = e;
        //calculateRez();
    }

    double getRez() const { return rez; }
    
    void calculateRez(char vm_pasirinkimas) {

        if (vm_pasirinkimas == 'v') {
            double mean = accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
            rez = 0.4 * mean + 0.6 * egz;
        }
        else if (vm_pasirinkimas == 'm') {
            sort(paz.begin(), paz.end());
            double median = 0;
            if (paz.size() % 2 == 0) {
                median = (paz[paz.size() / 2 - 1] + paz[paz.size() / 2]) / 2.0;
            }
            else {
                median = paz[paz.size() / 2];
            }
            rez = 0.4 * median + 0.6 * egz;
        }
        else {
            // default naudojamas medianos skaiciavimas
            sort(paz.begin(), paz.end());
            double median = 0;
            if (paz.size() % 2 == 0) {
                median = (paz[paz.size() / 2 - 1] + paz[paz.size() / 2]) / 2.0;
            }
            else {
                median = paz[paz.size() / 2];
            }
            rez = 0.4 * median + 0.6 * egz;
        }
    }
};

// Class
void main_vector();
void ivedimas_is_file_c(vector<Studentas>& grupe, char vm_pasirinkimas, const string& duom_vard);
void rusiuojame_i_dvi_grupes_c(vector<Studentas>& grupe, vector<Studentas>& nuskriaustukai, vector<Studentas>& galvociai);
void rusiuojame_i_dvi_grupes_2_c(vector<Studentas>& grupe, vector<Studentas>& nuskriaustukai);
void rusiuojame_i_dvi_grupes_3_c(std::vector<Studentas>& grupe, std::vector<Studentas>& nuskriaustukai);
void rusiuojame_i_dvi_grupes_4_c(std::vector<Studentas>& students, std::vector<Studentas>& nuskriaustukai, std::vector<Studentas>& galvociai);
void issaugojam_duomenis_c(const vector<Studentas>& studentai, const string& file_vard);
// void duomenu_kurimas(int numLines);
void laiko_skaicuokle_c(int n_eil, int n, int rusiavimo_pasirinkimas);
// double medianos_skaiciavimas(vector<int> vec);
// double galutinio_balo_skaiciavimas(char vm_pasirinkimas, Studentas& laikinas);
// vector<int> random_skaicius(int n);
bool palyginimas_pagal_rezultata_c(const Studentas& a, const Studentas& b);
bool palyginimas_pagal_varda_c(const Studentas &a, const Studentas &b);
bool palyginimas_pagal_pavarde_c(const Studentas &a, const Studentas &b);
Studentas rankinis_ivedimas_c();
Studentas atsitiktinis_ivedimas_c();

// vector
void main_vector();
void ivedimas_is_file(vector<studentas>& grupe, char vm_pasirinkimas, const string& duom_vard);
void rusiuojame_i_dvi_grupes(vector<studentas>& grupe, vector<studentas>& nuskriaustukai, vector<studentas>& galvociai);
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

// // list
// void main_list();
// void ivedimas_is_file_list(list<studentas_list> &grupe, char vm_pasirinkimas, const string &duom_vard);
// void rusiuojame_i_dvi_grupes_list(list<studentas_list>& grupe, list<studentas_list>& nuskriaustukai, list<studentas_list>& galvociai);
// void rusiuojame_i_dvi_grupes_list_2(list<studentas_list>& grupe, list<studentas_list>& nuskriaustukai);
// void rusiuojame_i_dvi_grupes_list_3(std::list<studentas_list>& grupe, std::list<studentas_list>& nuskriaustukai);
// void rusiuojame_i_dvi_grupes_list_4(std::list<studentas_list>& grupe, std::list<studentas_list>& nuskriaustukai, std::list<studentas_list>& galvociai);
// void issaugojam_duomenis_list(const list<studentas_list>& studentai, const string& file_vard);
// void duomenu_kurimas_list(int n_eiluciu);
// void laiko_skaicuokle_list(int n_eil, int n, int rusiavimo_pasirinkimas);
// double medianos_skaiciavimas_list(list<int> vektorius);
// double galutinio_balo_skaiciavimas_list(char vm_pasirinkimas, studentas_list& laikinas);
// list<int> random_skaicius_list(int n);
// bool palyginimas_pagal_rezultata_list(const studentas_list& a, const studentas_list& b);
// bool palyginimas_pagal_varda_list(const studentas_list &a, const studentas_list &b);
// bool palyginimas_pagal_pavarde_list(const studentas_list &a, const studentas_list &b);
// studentas_list atsitiktinis_ivedimas_list();
// studentas_list rankinis_ivedimas_list();
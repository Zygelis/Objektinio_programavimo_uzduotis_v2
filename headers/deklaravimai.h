#include "my_lib.h"

class Studentas
{
private:
    string vardas, pavarde;
    vector<int> paz;
    int egz;
    double rez;

public:
    // constructor
    Studentas() {}

    // destructor
    ~Studentas() {}

    // getters and setters
    string getVardas() const { return vardas; }
    void setVardas(const string &v) { vardas = v; }

    string getPavarde() const { return pavarde; }
    void setPavarde(const string &p) { pavarde = p; }

    vector<int> getPaz() const { return paz; }
    // void setPaz(const vector<int>& pzs) {
    //     paz = pzs;
    //     //calculateRez();
    // }
    void setPazs(int p)
    {
        paz.push_back(p);
        // calculateRez();
    }

    int getEgz() const { return egz; }
    void setEgz(int e)
    {
        egz = e;
        // calculateRez();
    }

    double getRez() const { return rez; }
    void calculateRez(char vm_pasirinkimas)
    {

        if (vm_pasirinkimas == 'v')
        {
            double mean = accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
            rez = 0.4 * mean + 0.6 * egz;
        }
        else if (vm_pasirinkimas == 'm')
        {
            sort(paz.begin(), paz.end());
            double median = 0;
            if (paz.size() % 2 == 0)
            {
                median = (paz[paz.size() / 2 - 1] + paz[paz.size() / 2]) / 2.0;
            }
            else
            {
                median = paz[paz.size() / 2];
            }
            rez = 0.4 * median + 0.6 * egz;
        }
        else
        {
            // default naudojamas medianos skaiciavimas
            sort(paz.begin(), paz.end());
            double median = 0;
            if (paz.size() % 2 == 0)
            {
                median = (paz[paz.size() / 2 - 1] + paz[paz.size() / 2]) / 2.0;
            }
            else
            {
                median = paz[paz.size() / 2];
            }
            rez = 0.4 * median + 0.6 * egz;
        }
    }
};

// Class
void main_vector();
void ivedimas_is_file_c(vector<Studentas> &grupe, char vm_pasirinkimas, const string &duom_vard);
void rusiuojame_i_dvi_grupes_c(vector<Studentas> &grupe, vector<Studentas> &nuskriaustukai, vector<Studentas> &galvociai);
void rusiuojame_i_dvi_grupes_2_c(vector<Studentas> &grupe, vector<Studentas> &nuskriaustukai);
void rusiuojame_i_dvi_grupes_3_c(std::vector<Studentas> &grupe, std::vector<Studentas> &nuskriaustukai);
void rusiuojame_i_dvi_grupes_4_c(std::vector<Studentas> &students, std::vector<Studentas> &nuskriaustukai, std::vector<Studentas> &galvociai);
void issaugojam_duomenis_c(const vector<Studentas> &studentai, const string &file_vard);
void duomenu_kurimas(int n_eiluciu);
void laiko_skaicuokle_c(int n_eil, int n, int rusiavimo_pasirinkimas);
vector<int> random_skaicius(int n);
bool palyginimas_pagal_rezultata_c(const Studentas &a, const Studentas &b);
bool palyginimas_pagal_varda_c(const Studentas &a, const Studentas &b);
bool palyginimas_pagal_pavarde_c(const Studentas &a, const Studentas &b);
Studentas rankinis_ivedimas_c();
Studentas atsitiktinis_ivedimas_c();

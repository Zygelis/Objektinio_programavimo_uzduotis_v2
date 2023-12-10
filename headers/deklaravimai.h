#include "my_lib.h"

class Studentas
{
private:
    string vardas, pavarde;
    vector<int> paz;
    int egz;
    double rez;

public:
    Studentas() {}

    Studentas(const string &v, const string &p, const vector<int> &pzs, int e, double r) : vardas(v), pavarde(p), paz(pzs), egz(e), rez(r) {}

    Studentas(const Studentas &s) : vardas(s.vardas), pavarde(s.pavarde), paz(s.paz), egz(s.egz), rez(s.rez) {}

    Studentas &operator=(const Studentas &s)
    {
        if (&s == this)
            return *this;
        vardas = s.vardas;
        pavarde = s.pavarde;
        paz = s.paz;
        egz = s.egz;
        rez = s.rez;
        return *this;
    }

    ~Studentas() {}

    friend ostream &operator<<(ostream &output, const Studentas &s)
    {
        output << "Vardas Pavarde: " << s.vardas << " " << s.pavarde;
        output << " Pazymiai: ";
        for (int paz : s.paz)
        {
            output << paz << " ";
        }

        output << "Egzaminas: " << s.egz << " " << "Rezultatas: " << s.rez << endl;
        return output;
    }

    friend istream &operator>>(istream &input, Studentas &s)
    {
        cout << "Iveskite varda: ";
        input >> s.vardas;
        cout << "Iveskite pavarde: ";
        input >> s.pavarde;

        cout << "Iveskite pazymius viena po kito ir paspauskite Enter, kai baigsite. Arba iveskite 'baigti' ir baigsite pazymiu ivedima." << endl;
        string paz_tikrinimas;
        cin.ignore();
        while (true)
        {
            getline(cin, paz_tikrinimas);

            if (paz_tikrinimas == "baigti" || paz_tikrinimas.empty())
            {
                break;
            }

            int input = std::stoi(paz_tikrinimas);

            if (input < 0 || input > 10)
            {
                cout << "Neteisinga ivestis. Iveskite skaicius nuo 0 iki 10." << endl;
                continue;
            }
            s.setPazs(input);
        }

        cout << "Enter Egzaminas: ";
        input >> s.egz;
        
        s.calculateRez('m');
        return input;
    }

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

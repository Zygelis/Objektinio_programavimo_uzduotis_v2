#include "headers/my_lib.h"
#include "headers/deklaravimai.h"

void ivedimas_is_file_c(vector<Studentas> &grupe, char vm_pasirinkimas, const string &duom_vard)
{
    ifstream duomenys(duom_vard);

    if (!duomenys.is_open())
    {
        cout << "Neatsidare duomenys " << endl;
        return;
    }

    string pirma_eilute;
    getline(duomenys, pirma_eilute);

    string eilute;
    while (getline(duomenys, eilute))
    { // kol nera pasiekta failo pabaiga skaitome po eilute
        Studentas laikinas;

        if (eilute.empty() || all_of(eilute.begin(), eilute.end(), ::isspace))
        {
            continue;
        }

        istringstream iss(eilute); // pasiverciame eilute i srauta is kurio galima skaityti lengviau

        string v, p;
        iss >> v >> p;
        laikinas.setVardas(v);
        laikinas.setPavarde(p);

        int pazymiai;

        while (iss >> pazymiai)
        { // kol yra skaiciu tol skaitome
            laikinas.setPazs(pazymiai);
        }

        if (!laikinas.getPaz().empty())
        {
            laikinas.setEgz(laikinas.getPaz().back());
            laikinas.getPaz().pop_back();
        }
        else
        {
            cout << "Error: Vector is empty." << endl;
        }
        // skaiciuojamas galutinis balas
        laikinas.calculateRez(vm_pasirinkimas);

        grupe.push_back(laikinas);
    }

    duomenys.close();
}

Studentas atsitiktinis_ivedimas_c()
{
    Studentas laikinas;
    cout << "Iveskite varda ir pavarde:";
    string vardas, pavarde;
    cin >> vardas >> pavarde;
    laikinas.setVardas(vardas);
    laikinas.setPavarde(pavarde);

    cout << "Kiek pazymiu norite sugeneruoti? ";
    int kiek_pazymiu;
    cin >> kiek_pazymiu;

    // Sugeneruojami pazymiai
    // laikinas.setPaz(random_skaicius(kiek_pazymiu));
    for (auto &a : random_skaicius(kiek_pazymiu))
    {
        laikinas.setPazs(a);
    }
    laikinas.setEgz(random_skaicius(1)[0]);

    cout << "Sugeneruoti pazymiai: ";
    for (auto &a : laikinas.getPaz())
    {
        cout << a << " ";
    }
    cout << endl;

    cout << "Sugeneruotas egzamino rezultatas: " << laikinas.getEgz() << endl;

    return laikinas;
}
#include "my_lib.h"

int main()
{
    studentas laikinas;
    vector<studentas> grupe;
    cout << "Kiek studentu norite ivesti?";
    int n;
    cin >> n;

    for (int j = 0; j < n; j++)
    {
        cout << "Iveskite varda ir pavarde:";
        cin >> laikinas.vardas >> laikinas.pavarde;
        cout << "Kiek paz. turi studentas? ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cout << "Iveskite " << i + 1 << " pazymi: ";
            cin >> k;
            laikinas.paz.push_back(k);
        }
        cout << "Iveskite egzamina: ";
        cin >> laikinas.egz;
        double mean = std::accumulate(laikinas.paz.begin(), laikinas.paz.end(), 0.0) / laikinas.paz.size();
        laikinas.rez = 0.4 * mean + 0.6 * laikinas.egz;

        grupe.push_back(laikinas);
        laikinas.paz.clear();
    }

    for (auto &studentas : grupe)
    {
        cout << studentas.vardas << "  " << studentas.pavarde << "  Semestro pazymiai: ";
        for (auto &pazymys : studentas.paz)
            cout << pazymys << " ";
        cout << " Egzamino rezultatas: " << studentas.egz;
        cout << "  Galutinis rezultatas: " << std::fixed << std::setprecision(2) << studentas.rez << endl;
    }
}
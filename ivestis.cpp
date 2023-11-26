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

Studentas rankinis_ivedimas_c()
{
    Studentas laikinas;

    cout << "Iveskite varda ir pavarde:";
    string vardas, pavarde;
    cin >> vardas >> pavarde;
    laikinas.setVardas(vardas);
    laikinas.setPavarde(pavarde);

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

        try
        {
            int input = std::stoi(paz_tikrinimas);

            if (input < 0 || input > 10)
            {
                cout << "Neteisinga ivestis. Iveskite skaicius nuo 0 iki 10." << endl;
                continue;
            }
            laikinas.setPazs(input);
        }
        catch (const std::invalid_argument &)
        {
            cout << "Neteisinga ivestis. Iveskite naturalu skaiciu tarp 1 ir 10: " << endl;
        }
        catch (const std::out_of_range &)
        {
            cout << "Ivestas skaicius per didelis. Iveskite mazesni skaiciu." << endl;
        }
    }

    // Ivedamas egzamino rezultatas
    while (true)
    {
        cout << "Iveskite egzamino rezultata: ";
        string egzrez_laikinas;
        cin >> egzrez_laikinas;

        try
        {
            int input = std::stoi(egzrez_laikinas);

            if (input < 1 || input > 10)
            {
                cout << "Egzamino rezultatas turi buti tarp 1 ir 10: " << endl;
            }
            else
            {
                laikinas.setEgz(input);
                break;
            }
        }
        catch (const std::invalid_argument &)
        {
            // Jei ivestis yra ne skaicius, prasoma ivesti is naujo
            cout << "Neteisinga ivestis. Iveskite naturalu skaiciu tarp 1 ir 10: " << endl;
        }
        catch (const std::out_of_range &)
        {
            cout << "Ivestas skaicius per didelis. Iveskite mazesni skaiciu." << endl;
        }
    }

    // Spausdinami ivesti pazymiai
    cout << "Ivedei pazymius: ";
    for (auto &a : laikinas.getPaz())
        cout << a << " ";
    cout << endl;

    cout << "Ivedei egzamina: " << laikinas.getEgz() << endl;
    cin.ignore();

    return laikinas;
}

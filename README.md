# objektinio_programavimo_uzduotis

## Aprašymas
Ši programa sukuria ir apdoroja studentų sąrašus, suskirstydama juos į dvi kategorijas pagal galutinius įvertinimus. Pagrindinės užduotys yra atsitiktinių mokinių duomenų failų generavimas, mokinių rūšiavimas pagal kategoriją, mokinių rūšiavimas į dvi grupes pagal galutinį rezultatą ir jų išvedimas į naujus failus. Šių užduočių atlikimas bus matuojamas ir analizuojamas naudojant skirtingo dydžio failus ir konteinerius.

## Kaip naudotis

### Jei norite pasirinkti kiek ir ką testuoti paleiskite main.cpp:
- Per terminalą `g++ main.cpp vector.cpp list.cpp funkcijos.cpp ivestis.cpp funkcijos_list.cpp ivestis_list.cpp -o main` ir `./main`

### Jei norite paleisti greičio matavimo failą laiko_matavimas.cpp:
- Per terminalą `g++ laiko_matavimas.cpp funkcijos.cpp ivestis.cpp funkcijos_list.cpp ivestis_list.cpp -o laiko_matavimas` ir `./laiko_matavimas`

## Greičio testai

### Sistemos, naudotos testavimui pateiktui žemiau, specifikacijos
- CPU: AMD Ryzen 7 5800H, 3201 Mhz, 8 Core(s), 16 Logical Processor(s)
- Installed Physical Memory (RAM):	16.0 GB
- SDD: 512 GB SSD PCIe

### Testavimo rezultatai iš laiko_matavimas.cpp


## Struktūra
- main.cpp --> pagrindinis file.
- vector.cpp --> iki v.03 buvęs main.cpp file. Dabar jis skirtas vector konteinerio naudojimui.
- list.cpp --> Skirtas list konteinerio naudojimui.
- funkcijos.cpp --> vector konteinerio funkcijų file.
- funkcijos_list.cpp --> list konteinerio funkcijų file.
- ivestis.cpp --> vector konteinerio įvesties formų funkcijų file.
- ivestis_list.cpp --> list konteinerio įvesties formų funkcijų file.
- my_lib.h --> library antraštinis file.
- deklaravimai.h --> deklaravimų antraštinis file.
- laiko_matavimas.cpp --> apskaičiuoja, kiek kiekvienam iš penkių atsitiktinai sugeneruotų skirtingo dydžio failų užtrunka laiko atlikti visas užduotis.

## Programos savybės

### Duomenų konteinerio pasirinkimas:
- Yra galimybė pasirinkti tarp vector ir list konteinerio.

### Greičio matavimas:
- Yra galimybė paleisti greičio matavimą, kuris apskaičiuoja ir išveda vector ir list konteinerių veikimo greitį su skirtingo dydžio duomenų failais.

### Pasirinkto dydžio duomenų failo sugeneravimas:
- Yra galimybė sugeneruoti pasirinkto dydžio duomenų failą.

### Duomenų apdorojimas:
Yra galimybė surūšiuoti mokinius į dvi kategorijas:
- Mokiniai, kurių galutinis įvertinimas < 5,0, vadinami "nuskriaustukais".
- Mokiniai, kurių galutinis įvertinimas >= 5,0, vadinami "galvočiais".

### Laiko matavimas:
- Išmatuojamas kiekvienos svarbios funkcijos veikimo laikas.

### Duomenų Įvedimas iš failo:
- Yra galimybė įvesti duomenis iš failo.

### Atsitiktinio Balų Generavimas:
- Vartotojai turi galimybę generuoti atsitiktinius namų darbų ir egzamino rezultatus studentams.

### Duomenų Įvedimas Ranka:
- Vartotojai gali patogiai įvesti studentų duomenis naudodami struktūruotą formatą, įskaitant studento vardą, pavardę, tarpinius namų darbų rezultatus ir egzamino rezultatą.

### Rezultato pateikimas:
- Įvedus duomenis, programa apskaičiuoja galutinį baląc ir lentelės formoje rezultatą pateikia ekrane. 
- Programa studentus gali surūšiuoti pagal vardą, pavardę, rezultatą.

### Skaičiavimo Galimybės:
- Programa palaiko tiek vidurkio, tiek medianos skaičiavimo metodus galutiniam balui apskaičiuoti.

### Dinaminis Namų Darbų Skaičius:
- Programa prisitaiko prie situacijų, kai namų darbų užduočių skaičius iš anksto nežinomas.
- Vartotojai gali nuspręsti, kada baigė įvesti visus namų darbų rezultatus, tiesiog paspaudę Enter arba "baigti", kaip tai yra prašoma.

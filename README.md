# objektinio_programavimo_uzduotis

## Aprašymas
Ši programa sukuria ir apdoroja studentų sąrašus, suskirstydama juos į dvi kategorijas pagal galutinius įvertinimus. Pagrindinės užduotys yra atsitiktinių mokinių duomenų failų generavimas, mokinių rūšiavimas pagal kategoriją, mokinių rūšiavimas į dvi grupes pagal galutinį rezultatą 4 metodais/strategijom ir jų išvedimas į naujus failus. Šių užduočių atlikimas bus matuojamas ir analizuojamas naudojant skirtingo dydžio failus ir konteinerius. Pridėtas CMakeLists.txt --> CMake funkcionalumas.

## Kaip naudotis

### Jei norite pasirinkti kiek ir ką testuoti paleiskite main.cpp:
- Per terminalą `g++ main.cpp vector.cpp list.cpp funkcijos.cpp ivestis.cpp funkcijos_list.cpp ivestis_list.cpp -o main` ir `./main`

### Jei norite paleisti greičio matavimo failą laiko_matavimas.cpp:
- Per terminalą `g++ laiko_matavimas.cpp funkcijos.cpp ivestis.cpp funkcijos_list.cpp ivestis_list.cpp -o laiko_matavimas` ir `./laiko_matavimas`

## Strategijos

### 1 Strategija
Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų" paprastu būdu - be jokių efektyvesnių funkcijų/algoritmų.

### 2 Strategija
Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį "vargšiukai" paprastu būdu - be jokių efektyvesnių funkcijų/algoritmų.

### 3 Strategija
Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį "vargšiukai" su efektyviom funkcijom/algoritmais.

### 4 Strategija
Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų" su efektyviom funkcijom/algoritmais.

## Strategijų greičių skirtumai skirtingų konteinerių atveju
### Vector
|                    failo dydis                    |      1000      |      10000      |    100000     |     1000000     |     10000000     |
| --------------------------------------|:-------------------|:-------------------:|:-----------------------:|:-----------------------:|:----------------------------:|
| Vidutinis duomenu padalijimas i dvi grupes laikas (1 strategija) | 1 ms (0.001 sec) | 3 ms (0.003 sec) | 21.4 ms (0.0214 sec) | 284.667 ms (0.284667 sec) | 2820 ms (2.82 sec) |
| Vidutinis duomenu padalijimas i dvi grupes laikas (2 strategija) | 0.4 ms (0.0004 sec) | 11.8 ms (0.0118 sec) | 194.4 ms (0.1944 sec) | 2721.67 ms (2.72167 sec) | 28414 ms (28.414 sec) |
| Vidutinis duomenu padalijimas i dvi grupes laikas (3 strategija) | 0 ms (0 sec) | 3 ms (0.003 sec) | 12 ms (0.012 sec) | 138.333 ms (0.138333 sec) | 1133 ms (1.133 sec) |
| Vidutinis duomenu padalijimas i dvi grupes laikas (4 strategija) | 0 ms (0 sec) | 1.6 ms (0.0016 sec) | 24.6 ms (0.0246 sec) | 272.333 ms (0.272333 sec) | 3472 ms (3.472 sec) |

### List
|                    failo dydis                    |      1000      |      10000      |    100000     |     1000000     |     10000000     |
| --------------------------------------|:-------------------|:-------------------:|:-----------------------:|:-----------------------:|:----------------------------:|
| Vidutinis duomenu padalijimas i dvi grupes laikas (1 strategija) | 1.4 ms (0.0014 sec) | 17.4 ms (0.0174 sec) | 180.8 ms (0.1808 sec) | 2095.67 ms (2.09567 sec) | 47733 ms (47.733 sec) |
| Vidutinis duomenu padalijimas i dvi grupes laikas (2 strategija) | 1.8 ms (0.0018 sec) | 20.6 ms (0.0206 sec) | 282.4 ms (0.2824 sec) | 3482 ms (3.482 sec) | 54557 ms (54.557 sec) |
| Vidutinis duomenu padalijimas i dvi grupes laikas (3 strategija) | 0.2 ms (0.0002 sec) | 13.8 ms (0.0138 sec) | 170.4 ms (0.1704 sec) | 1982.67 ms (1.98267 sec) | 100171 ms (100.171 sec) |
| Vidutinis duomenu padalijimas i dvi grupes laikas (4 strategija) | 0 ms (0 sec) | 0.4 ms (0.0004 sec) | 15.2 ms (0.0152 sec) | 164.667 ms (0.164667 sec) | 12722 ms (12.722 sec) |

## Greičio testai

Vector konteinerio greičiai:
|                    failo dydis                    |      1000      |      10000      |    100000     |     1000000     |     10000000     |
| --------------------------------------------------------|:---------------|:---------------:|:-------------:|:---------------:|:----------------:|
|  Vidutinis failo nuskaitymo laikas                      | 5.4 ms (0.0054 sec)|46.2 ms (0.0462 sec)|462 ms (0.462 sec)|4592.6 ms (4.5926 sec) | 48135.2 ms (48.1352 sec)|
|  Vidutinis duomenu rusiavimo laikas                     |0.4 ms (0.0004 sec)|4.6 ms (0.0046 sec)|127.6 ms (0.1276 sec)|1652.6 ms (1.6526 sec)|21689 ms (21.689 sec) |
|  Vidutinis duomenu padalijimas i dvi grupes laikas      |0 ms (0 sec)| 9.4 ms (0.0094 sec) |21.6 ms (0.0216 sec)|241.4 ms (0.2414 sec) | 4298 ms (4.298 sec)|
|  Vidutinis galvociu irasymo i faila laikas              |5 ms (0.005 sec)|24.4 ms (0.0244 sec) |280.6 ms (0.2806 sec)|2543.6 ms (2.5436 sec)|19631.2 ms (19.6312 sec) |
|  Vidutinis nuskriaustuku irasymo i faila laikas         |0.6 ms (0.0006 sec)|18.2 ms (0.0182 sec)| 176.6 ms (0.1766 sec)|1740.2 ms (1.7402 sec)|16068 ms (16.068 sec) |
|  *Vidutinis bendras laikas*                             |*11.4 ms (0.0114 sec)*|*93.4 ms (0.0934 sec)*|*1046.8 ms (1.0468 sec)* | *10529 ms (10.529 sec)*  | *105523 ms (105.523 sec)*|

List konteinerio greičiai:
|             failo dydis            | 1000               | 10000               | 100000                | 1000000                  | 10000000                    |
| --------------------------------------|:-------------------|:-------------------:|:-----------------------:|:-----------------------:|:----------------------------:|
| Vidutinis failo nuskaitymo laikas| 21.8 ms (0.0218 sec) | 102.8 ms (0.1028 sec) | 980.6 ms (0.9806 sec)  | 9855.6 ms (9.8556 sec) | 106289 ms (106.289 sec) |
| Vidutinis duomenu rusiavimo laikas     | 0 ms (0 sec)           | 3 ms (0.003 sec)   | 30.8 ms (0.038 sec) | 655.6 ms (0.6556 sec) | 10563.4 ms (10.5634 sec)     |
| Vidutinis duomenu padalijimas i dvi grupes laikas | 1.4 ms (0.0014 sec) | 16.4 ms (0.0164 sec) | 247.8 ms (0.2478 sec) | 2501.8 ms (2.5018 sec) | 33137.8 ms (33.1378 sec) |
| Vidutinis galvociu irasymo i faila laikas | 0.8 ms (0.0008 sec) | 29.2 ms (0.0292 sec) | 278.2 ms (0.2782 sec) | 2704.8 ms (2.7048 sec) | 19492.4 ms (19.4924 sec) |
| Vidutinis nuskriaustuku irasymo i faila laikas | 0.2 ms (0.0002 sec) | 15.8 ms (0.0158 sec) | 179.8 ms (0.1798 sec) | 1613.6 ms (1.6136 sec) | 13990.2 ms (13.9902 sec) |
| *Vidutinis bendras laikas*             | *22.8 ms (0.0228 sec)*  | *150.8 ms (0.1508 sec)* | *1469.4 ms (1.4694 sec)* | *14829.6 ms (14.8296 sec)* | *150335 ms (150.335 sec)*  |


### Sistemos, naudotos testavimui pateiktui žemiau, specifikacijos
- CPU: AMD Ryzen 7 5800H, 3201 Mhz, 8 Core(s), 16 Logical Processor(s)
- Installed Physical Memory (RAM):	16.0 GB
- SDD: 512 GB SSD PCIe


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

### 4 Skirtingos rūšiavimo į dvi grupes strategijos:
- Vartotojas gali pasirinkti viena iš 4 strategijų.
- Laiko skaičiuoklėjė yra apskaičiuojamas visų strategijų laikas.

### Pakeista programos struktūra
- header failai buvo perkelti į atskirą `headers` folderį
- pridėta CMakeLists.txt

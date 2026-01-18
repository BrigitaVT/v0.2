# v0.1
# Studentų pažymių skaičiavimo sistema

## Projekto versijos

### v0.1
Realizuota C++ programa, kuri:
- nuskaito studentų vardus, pavardes, namų darbų ir egzamino rezultatus;
- galutinį pažymį skaičiuoja pagal formulę:
  - Galutinis = 0.4 * ND_vidurkis + 0.6 * Egzaminas;
- palaiko skaičiavimą pagal vidurkį ir medianą;
- duomenis gali nuskaityti iš failo;
- rezultatus išveda formatuota lentele.

### v0.2
Programa papildyta šiomis galimybėmis:
- studentų duomenų failų generavimas (1 000 – 10 000 000 įrašų);
- studentų dalijimas į dvi kategorijas:
  - **vargšiukai** (galutinis < 5.0);
  - **kietiakai** (galutinis ≥ 5.0);
- surūšiuoti studentai išvedami į atskirus failus;
- atlikta programos veikimo spartos analizė:
  - duomenų nuskaitymas;
  - studentų dalijimas;
  - rezultatų išvedimas į failus.
## Dideli duomenų failai

Didelio dydžio studentų duomenų failai (nuo 1 000 000 įrašų)
į GitHub repozitoriją neįkeliami.

Šie failai generuojami lokaliai naudojant programos funkciją
`generuotiFaila()`.

Tai daroma laikantis gerosios Git praktikos, kadangi Git nėra
skirtas didelių duomenų failų saugojimui.
## Spartos analizė (Release)

| Failas | Įrašų sk. | Nuskaitymas (s) | Dalijimas (s) | Rašymas (s) |
|---|---:|---:|---:|---:|

| stud_10000.txt | 10 000 |  0.119678 s |  0.0044401 s |  0.0216463 s|
| stud_100000.txt | 100 000 | 1.60825 s | 0.0740552 s | 0.209486 s |

## Išvados

- Didžiausią laiko dalį programoje užima duomenų nuskaitymas iš failo.
- Studentų dalijimas į dvi kategorijas yra labai greitas, palyginti su I/O operacijomis.
- Didėjant įrašų skaičiui, programos veikimo laikas didėja apytiksliai proporcingai.

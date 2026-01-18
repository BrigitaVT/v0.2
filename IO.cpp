#include "IO.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <random>

static int nustatytiNDKiekiIsHeader(const std::string& headerLine) {
    std::istringstream hs(headerLine);
    std::string tok;
    int ndCount = 0;

    while (hs >> tok) {
        if (tok.rfind("ND", 0) == 0) ndCount++;
        if (tok == "Egz." || tok == "Egz" || tok == "Egzaminas") break;
    }
    if (ndCount == 0) throw std::runtime_error("Header'e nerasta ND stulpeliu.");
    return ndCount;
}

std::vector<Studentas> nuskaitytiIsFailo(const std::string& f) {
    std::ifstream in(f);
    if (!in) throw std::runtime_error("Nepavyko atidaryti failo: " + f);

    std::string header;
    if (!std::getline(in, header)) throw std::runtime_error("Tuscias failas: " + f);

    int ndCount = nustatytiNDKiekiIsHeader(header);

    std::vector<Studentas> v;
    v.reserve(10000);

    std::string vardas, pavarde;
    long long count = 0;

    while (in >> vardas >> pavarde) {
        Studentas s;
        s.setName(vardas);
        s.setSurname(pavarde);

        for (int i = 0; i < ndCount; i++) {
            int nd;
            if (!(in >> nd)) throw std::runtime_error("Truksta ND duomenu faile: " + f);
            s.addNDVector(nd);
        }

        int egz;
        if (!(in >> egz)) throw std::runtime_error("Truksta Egz duomenu faile: " + f);
        s.setEgz(egz);

        s.syncCFromVector();
        s.skaiciuotiGalutinius();

        v.push_back(s);

        count++;
        if (count % 100000 == 0) {
            std::cout << "Nuskaityta: " << count << "\n";
        }
    }

    return v;
}

void isvestiIFaila(const std::string& fname, const std::vector<Studentas>& v) {
    std::ofstream out(fname);
    if (!out) throw std::runtime_error("Nepavyko sukurti failo: " + fname);

    out << "Pavarde Vardas Galutinis(Vid.)\n";
    for (const auto& s : v) {
        out << s.getSurname() << " " << s.getName() << " " << s.getGalVid() << "\n";
    }
}

void generuotiFaila(const std::string& fname, long long n, int ndCount) {
    if (n <= 0) throw std::runtime_error("n turi buti > 0.");
    if (ndCount <= 0) throw std::runtime_error("ndCount turi buti > 0.");

    std::ofstream out(fname);
    if (!out) throw std::runtime_error("Nepavyko sukurti failo: " + fname);

    out << "Vardas Pavarde ";
    for (int i = 1; i <= ndCount; i++) out << "ND" << i << " ";
    out << "Egz.\n";

    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 10);

    for (long long i = 1; i <= n; i++) {
        out << "Vardas" << i << " " << "Pavarde" << i << " ";
        for (int j = 0; j < ndCount; j++) out << dist(gen) << " ";
        out << dist(gen) << "\n";
    }
}

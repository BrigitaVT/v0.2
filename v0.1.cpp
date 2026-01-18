#include "IO.h"
#include <vector>
#include <chrono>
#include <iostream>

int main() {
    try {
        std::string inputFile = "studentai100000.txt";

        auto t1 = std::chrono::high_resolution_clock::now();
        auto studentai = nuskaitytiIsFailo(inputFile);
        auto t2 = std::chrono::high_resolution_clock::now();

        std::vector<Studentas> vargsiukai;
        std::vector<Studentas> kietiakai;
        vargsiukai.reserve(studentai.size());
        kietiakai.reserve(studentai.size());

        auto t3 = std::chrono::high_resolution_clock::now();
        for (const auto& s : studentai) {
            if (s.getGalVid() < 5.0)
                vargsiukai.push_back(s);
            else
                kietiakai.push_back(s);
        }
        auto t4 = std::chrono::high_resolution_clock::now();

        auto t5 = std::chrono::high_resolution_clock::now();
        isvestiIFaila("vargsiukai.txt", vargsiukai);
        isvestiIFaila("kietiakai.txt", kietiakai);
        auto t6 = std::chrono::high_resolution_clock::now();

        std::cout << "Nuskaitymas: "
            << std::chrono::duration<double>(t2 - t1).count() << " s\n";
        std::cout << "Dalijimas:   "
            << std::chrono::duration<double>(t4 - t3).count() << " s\n";
        std::cout << "Rasymas:     "
            << std::chrono::duration<double>(t6 - t5).count() << " s\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Klaida: " << e.what() << "\n";
        return 1;
    }
    return 0;
}

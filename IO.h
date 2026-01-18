#pragma once
#include <vector>
#include <string>
#include "Studentas.h"

std::vector<Studentas> nuskaitytiIsFailo(const std::string& f);
void isvestiIFaila(const std::string& fname, const std::vector<Studentas>& v);
void generuotiFaila(const std::string& fname, long long n, int ndCount);

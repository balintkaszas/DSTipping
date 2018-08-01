#pragma once
#include "./ensemble.h"

class Bifurcation {
    public:
        Bifurcation(double _c) : C(_c) {};
        double C;
        std::vector <state_type> attractors;
        std::vector <int> BasinIndex;
        void operator()(int, int);
        void Basin(const Ensemble&,
            const double);
        void PrintBasin(const std::string&, const Ensemble&, double, int);
        std::vector<int> countbasin();
        Ensemble PrintBasin2(const std::string&, const Ensemble&, double);
        
};

void TestLinearRamp(std::string,  double, double, double, Bifurcation &, int, int);
void TestLinearRamp(std::string,Ensemble, Ensemble,  double, double, double, Bifurcation &, int, int);
void TestLinearRamp(std::string,  double, double, double, Bifurcation &, int);

void TestLinearRamp3(std::string, std::string, double, double, double, Bifurcation &, int);

void TestLinearRamp2(std::string, double, double, double, Bifurcation &, int);

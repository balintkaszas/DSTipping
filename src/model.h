#pragma once
#include "./ensemble.h"

double Decay(double, double);
double LinearRamp(double , double , double);
double LinearRamp(double , double);

struct inga{
    inga(double alpha, double C): m_Alpha(alpha), m_C(C) {}
    // m_C, m_Alpha: a strukt. változói.
    // alpha, C pedig amivel meghívom.
    void operator() (state_type const&, state_type&, double) const;
    double m_Alpha, m_C;
};

struct inga2{
    inga2(double tRamp, double C): m_tRamp(tRamp), m_Cmax(C) {}
    // m_C, m_Alpha: a strukt. változói.
    // alpha, C pedig amivel meghívom.
    void operator() (state_type const&, state_type&, double) const;
    double m_tRamp, m_Cmax;
};

struct egysz{
    egysz(double C): m_C(C) {}
    void operator() (state_type const&, state_type&, double) const;
    double m_C;
};

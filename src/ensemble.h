#pragma once
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <numeric>  // for std::iota, std::accumulate
#include <future>   // for std::future, std::async
#include <iomanip>  // for std::setprecision
#include <string>
#include <boost/numeric/odeint.hpp>

using namespace boost::numeric::odeint;

typedef std::vector<double> state_type;
typedef std::vector<state_type> ensembleType;
typedef controlled_runge_kutta< runge_kutta_cash_karp54< state_type > > ControlledStepperType;
typedef runge_kutta_fehlberg78< state_type > RegularStepperType;
extern const double Pi;
double Contract(double);
void writevector(const std::vector<state_type>&, const std::string &);
double Distance(state_type const&, state_type const&);
double LinearRamp(double, double, double);
double LinearRamp(double, double);

double closestElementInSet(state_type, std::vector<state_type> );
bool isNearToElement(state_type, std::vector<state_type>, const double);

state_type operator+(state_type const&, state_type const&);
state_type operator-(state_type const&, state_type const&);
void operator+=(state_type, state_type const&);
state_type operator*(state_type const&, state_type const&);
std::ostream & operator<<(std::ostream &, state_type const&);


class Ensemble{
    // Ensemble(double alpha, double C): e_Alpha(alpha), e_C(C) {} ;
    public:
        std::vector <state_type> Points;
        // double Alpha=0.025, C0=2;
        double starttime=0.;
        void operator() (size_t,  const double& time = 0., const state_type& = {-Pi, -3.2}, const state_type& = {Pi, 3.2});
        void read(const std::string &);
        void evolve(const double, const double, const double);
        void evolve2(const double, const double, const double);
        void evolve3(const double, const double, const double, const std::string&);

        std::vector<double> getCoordinateVector(size_t) const;
        std::vector<double> average() const;
        state_type standardDeviation() const;
        void write(const std::string &) const;
        // double e_Alpha, e_C;
};

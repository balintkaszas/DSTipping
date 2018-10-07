#include "./model.h"

extern const double Pi = 3.14159265358979;
const double Q = 0.1;

const double gammasq = 1./9.;
const double beta = 0.05;
const double Omega = 1.;

extern const double period = 2.*Pi;
extern const double dt = 0.01*period;


double Decay(double t, double A, double C0) {
    auto C = C0;
    if (t >= 0.) {
        C = C0*exp(-A*t);
    }
    return C;
}

double LinearRamp(double t, double tRamp, double Cmax) {
    auto C = 0.1;
    if(tRamp == 0){ return Cmax;} //Kvazistac.hatareset    
    assert(tRamp >= 0);
    auto m = (Cmax-0.1)/(tRamp*period);
    if (t >= 0. and t <= (tRamp)*period) {
        C = 0.1+m*t;
    }
    if (t > (tRamp)*period) {
        C = 0.1+m*tRamp*period;
    }
    return C;
}

double LinearRamp(double t, double tRamp) {
    auto C = 0.1;
    assert(tRamp >= 0);
    auto m = (0.967)/(10.*period);
    if (t >= 0. and t <= tRamp*period) {
        C = 0.1+m*t;
    }
    if (t > tRamp*period) {
        C = 0.1+m*tRamp*period;
    }
    return C;
}

void inga::operator()(state_type const& x, state_type& dxdt, double t) const {
        dxdt[0] = 1.;
        dxdt[1] = x[2];
        dxdt[2] = -0.1*x[2] -
          (1./9.)*sin(x[1]) +
          Decay(x[0], m_Alpha, m_C)*cos(x[1])*cos(x[0]);
    }

void inga2::operator()(state_type const& x, state_type& dxdt, double t) const {
        dxdt[0] = 1.;
        dxdt[1] = x[2];
        dxdt[2] = -0.1*x[2] -
          (1./9.)*sin(x[1]) +
          LinearRamp(x[0], m_tRamp, m_Cmax)*cos(x[1])*cos(x[0]);
    }

void egysz::operator()(state_type const& x, state_type& dxdt, double t) const {
            dxdt[0] = 0.;
            dxdt[1] = x[2];
            dxdt[2] = -0.1*x[2]+(1./9.)*sin(x[1])+m_C*cos(t);
}


#include "./ensemble.h"
#include "./model.h"
extern const double Pi, Q, gammasq, beta, Omega, period, dt;

auto nMaxThreads = std::thread::hardware_concurrency();

double contract(double X) {
    if (X > Pi) {
        while (X > Pi) {
            X = X-2.0*Pi;
        }
    }
    if (X < (-1.0*Pi)) {
        while (X < (-1.0*Pi)) {
            X = X+2.0*Pi;
        }
    }
    if (X >= (-1.0*Pi) && X <= Pi) {
        return X;
    }
    else;
    return X;
}


void writevector(const std::vector <state_type>& A, const std::string& file) {
    std::ofstream output;
    output.open(file);
    for (int i = 0; i < A.size(); i++) {
            output << contract(A[i][1]) << ' ' << A[i][2];
            output << std::endl;
    }
}


state_type operator+ (state_type const& A, state_type const& B) {
    assert(A.size() == B.size());
    state_type result;
    result.reserve(A.size());
    std::transform(std::begin(A),
        std::end(A),
        std::begin(B),
        std::back_inserter(result),
        [](auto a, auto b ){ return a+b; });
    return result;
}

state_type operator- (state_type const& A, state_type const& B) {
    assert(A.size() == B.size());
    state_type result;
    result.reserve(A.size());
    // state_type result {A[0]+B[0], A[1]+B[1]};
    std::transform(std::begin(A),
        std::end(A),
        std::begin(B),
        std::back_inserter(result),
        [](auto a, auto b ){ return a-b; });
    return result;
}

void operator+= (state_type A, state_type const& B) {  // nem működik rendesen
    assert(A.size() == B.size());
    std::transform(std::begin(A),
        std::end(A),
        std::begin(B),
        std::begin(A),
        [](auto a, auto b ){ return a+b; });
}

state_type operator* (state_type const& A, state_type const& B) {
    // This is ELEMENTWISE multiply!
    assert(A.size() == B.size());
    state_type result;
    std::transform(std::begin(A),
        std::end(A),
        std::begin(B),
        std::back_inserter(result),
        [](auto a, auto b){ return a*b; });
    return result;
}


double Distance(state_type const& A, state_type const& B) {
    assert(A.size() == B.size());
    state_type C = B-A;
    return sqrt(std::inner_product(std::next(std::begin(C)),
          std::end(C),
          std::next(std::begin(C)),
          0.));
}

double closestElementInSet(state_type  A, std::vector<state_type> Set) {
    //assert(A.size() == Set[0].size());
    /*std::vector<state_type> Set;
    Set.reserve(Set.size());
    for(const state_type& element : Set){
        state_type temp {element[1], element[2]};
        Set.push_back(temp);
    }*/
    std::vector<double> DistanceToEach;
    DistanceToEach.reserve(A.size()); 
    for( state_type element : Set) {
        DistanceToEach.push_back(Distance(A, element ) );
        //std::cout << Distance(A, element ) << std::endl;
    }
    auto result=std::min_element(DistanceToEach.begin(), DistanceToEach.end());
    auto index=std::distance(std::begin(DistanceToEach), result);
    return index;
}

bool isNearToElement(state_type A, std::vector<state_type> Set,const double tolerance) {
    int closestElement = closestElementInSet(A, Set);
    return (Distance(A, Set[closestElement]) > tolerance) ? false : true;
}

std::ostream& operator<<(std::ostream& s, state_type const& v) {
    s <<  std::setprecision(16) << v[1] << " " << v[2] << "\n";
    return s;
}


void Ensemble::operator() (size_t Size, const double& starttime, const state_type& BotLeft,
    const state_type& TopRight  ) {
    // itt jobb lenne egy lambda ami definiálja a tartományt,
    Points.reserve(Size);
    // és egy eloszlás
    auto widthPhi=TopRight[0]-BotLeft[0];
    auto widthOm=TopRight[1]-BotLeft[1];
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            state_type temp {
                starttime,
                BotLeft[0]+i*(widthPhi/Size),
                BotLeft[1]+j*(widthOm/Size)
            };
            Points.push_back(temp);
        }
    }
}

void Ensemble::read(const std::string& filename) {
    //assert(Points.size() == 0);
    //writes to end of ensemble.
    std::ifstream myfile(filename);
    double phi, omega;
    while (myfile >> phi >> omega) {
        state_type read {Ensemble::starttime, phi, omega};
        Ensemble::Points.push_back(read);
    }
    Ensemble::starttime = 0.;
    std::cout << "Read " << Ensemble::Points.size() << " entries \n";
}



void Ensemble::evolve(const double EvolveTo,
    const double tRamp,
    const double Cmax) {
        std::vector<std::future<void> > handles(nMaxThreads);
        auto dTime = (EvolveTo*period-Points[0][0]);  // Ez lehet negatív is!
        auto Sgn = (dTime > 0) ? 1 : ((dTime < 0) ? -1 : 0);
        auto dt = Sgn*0.1*period;
        auto dN = Points.size()/nMaxThreads;
        auto numSteps = dTime/dt;
        //std::cout << dTime << "\n";        //
        for (int j = 0; j < nMaxThreads; j++) {
           handles.push_back(std::async(std::launch::async,
                [&](int idx) {
                    for (int i = 0; i < dN; i++) {
                        auto index =  idx*dN + i;
                        // std::cout << i << std::endl;
                        RegularStepperType RK;
                        for(int k = 0; k<numSteps; k++){
                            RK.do_step(inga(tRamp, Cmax), Points[index], Points[index][0], dt);
                             Points[index][1] = contract(Points[index][1]);
                        }}
               },
               j));
        }
    }
void Ensemble::evolve2(const double EvolveTo,
    const double tRamp,
    const double Cmax) {
        std::vector<std::future<void> > handles(nMaxThreads);
        auto dTime = (EvolveTo*period-Points[0][0]);  // Ez lehet negatív is!
        auto Sgn = (dTime > 0) ? 1 : ((dTime < 0) ? -1 : 0);
        auto dt = Sgn*0.1*period;
        auto dN = Points.size()/nMaxThreads;
        auto numSteps = dTime/dt;
        
        for (int j = 0; j < nMaxThreads; j++) {
           handles.push_back(std::async(std::launch::async,
                [&](int idx) {
                    for (int i = 0; i < dN; i++) {
                        auto index =  idx*dN + i;
                        // std::cout << i << std::endl;
                        integrate_adaptive(ControlledStepperType(),
                            inga2(tRamp, Cmax),
                            Points[index],
                            Points[index][0],
                            EvolveTo*period,
                            dt);
                        Points[index][1] = contract(Points[index][1]);
                        /*integrate_const(RegularStepperType(),
                            inga2(tRamp, Cmax),
                            Points[index],
                            Points[index][0],
                            EvolveTo*period,
                            dt);
                        Points[index][1] = contract(Points[index][1]);*/
                    }
                },
                j));
        }
    }

    void Ensemble::evolve3(const double EvolveTo,
    const double tRamp,
    const double Cmax,
    const std::string& path) {
        std::vector<std::future<void> > handles(nMaxThreads);
        auto dTime = (EvolveTo*period-Points[0][0]);  // Ez lehet negatív is!
        auto Sgn = (dTime > 0) ? 1 : ((dTime < 0) ? -1 : 0);
        auto stepsPeriod = 0.1;
        auto dt = Sgn*stepsPeriod*period;
        auto dN = Points.size();///nMaxThreads;
        auto numSteps = dTime/dt;
        auto numPeriods = EvolveTo-Points[0][0]/period;
        //for (int j = 0; j < nMaxThreads; j++) {
        //   handles.push_back(std::async(std::launch::async,
        //        [&](int idx) {
                    RegularStepperType RK;
                    for (int i = 0; i < numSteps; i++) {
                        if(i % 10 == 0){
                            auto num = i/10;
                            //std::cout << Points[0][0]/period << "\n"; 
                            std::ofstream out(path+"_" + std::to_string(num)+"_.txt");
                            for(int k = 0; k<dN; k++){
                                out << std::setprecision(16) <<  Points[k][1] << " " << std::setprecision(16) << Points[k][2] << "\n";

                                RK.do_step(inga2(tRamp, Cmax), Points[k], Points[k][0], dt);
                                Points[k][1] = contract(Points[k][1]);
                            }
                        }else{
                            for(int k = 0; k<dN; k++){
                                RK.do_step(inga2(tRamp, Cmax), Points[k], Points[k][0], dt);
                                Points[k][1] = contract(Points[k][1]);
                            }
                        }

                        /*integrate_const(RegularStepperType(),
                            inga2(tRamp, Cmax),
                            Points[index],
                            Points[index][0],
                            EvolveTo*period,
                            dt);
                        Points[index][1] = contract(Points[index][1]);*/
        //            }
        //        },
        //        j));
        }
    }

void Ensemble::write(const std::string & filename) const {
    std::ofstream output(filename);
    for (int i=0; i < Points.size(); ++i) {
        output << std::setprecision(16)<< Points[i];
    }
}

std::vector<double> Ensemble::getCoordinateVector(size_t i) const {
    // possibly slow(?)
    assert(i <= Points[0].size());
    std::vector<double> coordinateVector;
    coordinateVector.reserve(Points.size());
    for (const state_type& element : Points) {
        coordinateVector.push_back(element[i]);
    }
    return coordinateVector;
}

std::vector<double> Ensemble::average() const {
    std::vector<double> averageVector;
    auto size=Points[0].size();
    averageVector.reserve(size);
    for (int i=0; i<size ; i++) {
        auto coordinatevector=getCoordinateVector(i);
        auto sum = std::accumulate(std::begin(coordinatevector), std::end(coordinatevector), 0.0);
        averageVector.push_back(sum / coordinatevector.size());
    }
    return averageVector;
}

state_type Ensemble::standardDeviation() const {
    /* Computes standard deviation [ Sigma^2=<X>^2-<X^2> ]
     * of every coordinate over the ensemble this formula is
     * possibly more stable than standard dev. definition.
     *
     */

    state_type SumVector(Points[0].size(), 0.);
    // state_type sum = std::accumulate(std::begin(Points),
    //     std::end(Points),
    //     NullVector);

    auto N = Points.size();
    std::for_each(std::begin(Points), std::end(Points),
    [&](const std::vector<double>& row){
        // We take each element of the row and add it to the corresponding
        // element of colsums vector:
        std::transform(std::begin(row),
            std::end(row),
            std::begin(SumVector),
            std::begin(SumVector),
            [](double a, double b) { return a + b; });
    });
    std::transform(std::begin(SumVector),
        std::end(SumVector),
        std::begin(SumVector),
        [N](auto d) { return d * d/(N*N); });  // N*<X>^2

    state_type SqrSumVector(Points[0].size(), 0.);

    std::for_each(std::begin(Points), std::end(Points),
    [&](const std::vector<double>& row) {
        // We take each element of the row and add it to the corresponding
        // element of colsums vector:
        std::transform(std::begin(row),
            std::end(row),
            std::begin(SqrSumVector),
            std::begin(SqrSumVector),
            [](double a, double b) { return a*a + b; });
    });


    state_type SigmaVector(Points[0].size(), 0.);
    std::transform(std::begin(SqrSumVector),
        std::end(SqrSumVector),
        std::begin(SqrSumVector),
        [N](auto d) { return d /(N); });  // N*<X>^2

    std::transform(std::begin(SqrSumVector),
        std::end(SqrSumVector),
        std::begin(SumVector),
        std::begin(SigmaVector),
        [] (auto a, auto b) { return sqrt(a-b); });

    return SigmaVector;
}


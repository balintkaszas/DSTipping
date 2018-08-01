#include "./bifurcation.h"
#include "./ensemble.h"
#include "./model.h"
extern const double period;
void Bifurcation::operator()(int Size, int IntegrateTo) {
    Ensemble Initial;
    state_type A {-1., -1.5};
    state_type B {Pi, 1.5};
    Initial(Size, 0.);
        
    Initial.evolve2(IntegrateTo, 0., C);
    //Initial.write("output/1004/TEST.txt");
    std::sort(std::begin(Initial.Points),
        std::end(Initial.Points),
        [](const state_type & First, const state_type & Second){
          return First[2] < Second[2];
        });
    //Initial.write("output/1102/TEST1.txt");
    std::vector<state_type> temp; 
    std::unique_copy(std::begin(Initial.Points),
        std::end(Initial.Points),
        std::back_inserter(attractors),
        [](const state_type & First, const state_type & Second) {
            return (Distance(First, Second)<0.001);
        });

    
    //writevector(attractors, "output/1102/TEST_attr.txt");
}

void Bifurcation::Basin(const Ensemble& PhaseSpace,
    const double tolerance) {
        auto Size = sqrt(PhaseSpace.Points.size());
        Ensemble InitialPoints;
        //state_type A {-3.1, -0.2};
        //state_type B {-2.7, 0.2};
        double a = PhaseSpace.starttime;
        InitialPoints(Size, a);
        BasinIndex.reserve(Size);
        Ensemble asd;
        for (const state_type& Point : PhaseSpace.Points) {
            auto IsClosestTo = closestElementInSet(Point, attractors);
            bool IsNearAttractor=isNearToElement(Point, attractors, tolerance);
            if(IsNearAttractor){
                asd.Points.push_back(Point);
                BasinIndex.push_back(IsClosestTo); //If the point has already converged           
            } else { //If the point hasnt converged, assign -1 to it. it will be handled in the print fn
                BasinIndex.push_back(-1); 
            } 
        }
}

void Bifurcation::PrintBasin(const std::string& path, const Ensemble & init, double tramp ,int evolve) {
    writevector(attractors, path + "attractors.txt");
    std::ofstream outFile(path + "flatgrid.txt");
    // the important part
    for (const auto &e : BasinIndex) outFile << e << "\n";
    //state_type A {-3.1, -0.2};
   //state_type B {-2.7, 0.2};
    ensembleType Basin;
    Basin.reserve(BasinIndex.size());
    int count = 0;
    for(int i=0; i<attractors.size(); i++) {
        Ensemble mov;
        std::ofstream output(path+"basin"+std::to_string(i)+".txt");        
        for(int j=0; j<BasinIndex.size(); j++) {
            //std::cout << j << " " << count << "\n"; 
            if(BasinIndex[j]==i) {
                //std::cout << "most " << i  << " " << j  << " " << BasinIndex.size()<<"\n";
                output << init.Points[j];
                mov.Points.push_back(init.Points[j]);
                /*auto IsClosestTo = closestElementInSet(moving.Points[j], attractors);
                if(IsClosestTo != i){
                    count = count+ 1;
                    std::cout << "nemjo. " << " " << count << "\n"; 
                }*/
           }
        }
        if(evolve==1 and mov.Points.size()>0){
            mov.evolve3(tramp+100, tramp, C, path + "ensemble_"+std::to_string(i));

        }
        //std::cout<<  std::setprecision(16)<< mov.Points[0][0]/period << "\n\n";
        
     //   mov.evolve2(0., 100., 10, C);
        //mov.evolve2(30, 100, 10, C);
        //mov.evolve2(30, 100, 10, C);
     //   mov.write(path+"evbas_"+std::to_string(i)+".txt");
    //}

    //BasinIndex.clear();
    }
}

std::vector<int> Bifurcation::countbasin() {
    std::vector<int> histogram;
    histogram.reserve(attractors.size());
    for(int i = 0; i< attractors.size(); i++) {
        histogram.push_back(count(BasinIndex.begin(), BasinIndex.end(), i));
    }
    return histogram;
}

Ensemble Bifurcation::PrintBasin2(const std::string& path, const Ensemble & init, double tramp) {
    writevector(attractors, path + "attractors.txt");
    //state_type A {-3.1, -0.2};
   //state_type B {-2.7, 0.2};
    ensembleType Basin;
    Basin.reserve(BasinIndex.size());
    int count = 0;
        Ensemble mov;

    for(int i=0; i<attractors.size(); i++) {
        std::ofstream output(path+"basin"+std::to_string(i)+".txt");        
        for(int j=0; j<BasinIndex.size(); j++) {
            //std::cout << j << " " << count << "\n"; 
            if(BasinIndex[j]==0) {
                //std::cout << "most " << i  << " " << j  << " " << BasinIndex.size()<<"\n";
                //output << init.Points[j];
                mov.Points.push_back(init.Points[j]);
                /*auto IsClosestTo = closestElementInSet(moving.Points[j], attractors);
                if(IsClosestTo != i){
                    count = count+ 1;
                    std::cout << "nemjo. " << " " << count << "\n"; 
                }*/
            }
        }

     //   mov.write(path+"evbas_"+std::to_string(i)+".txt");
    }
    return mov;
    //BasinIndex.clear();
}

void TestLinearRamp(std::string path,
    double StartTime,
    double EndTime,
    double RampTime,
    Bifurcation& Cvalue,
    int Size, int evolve){
        Ensemble Moving;
        state_type A {-0.110549 - 0.0005, 0.0123838-0.0005};
        state_type B {-0.110549 + 0.0005, 0.0123838+0.0005};
        /*state_type A {-0.110549 - 0.5, 0.0123838-0.5};
        state_type B {-0.110549 + 0.5, 0.0123838+0.5};*/   
        Moving(Size, StartTime);
        Ensemble init;
        init(Size, StartTime);
        //Moving.evolve2( StartTime + 0.5*period, RampTime, Cvalue.C);
        
        Moving.evolve2( EndTime, RampTime, Cvalue.C);
        std::cout << "C=" << LinearRamp(EndTime*period, RampTime, Cvalue.C) << "\n";
        /*for(int i=0; i<EndTime; i++){
            Moving.write("output/1004/TEST/"+std::to_string(i)+".txt");
            std::cout << "C=" << LinearRamp(i*period, RampTime) << "\n";          
        }*/
        std::cout << "basin starts" << std::endl;
        Moving.write(path + "end.txt");
        Cvalue.Basin(Moving, 0.1);
        Cvalue.PrintBasin(path, init, RampTime, evolve);
        std::cout << "basin ends" << std::endl;
    }



void TestLinearRamp3(std::string path, std::string path2,
    double StartTime,
    double EndTime,
    double RampTime,
    Bifurcation& Cvalue,
    int Size){
        Ensemble Moving;
        state_type A {-0.110549 - 0.5, 0.0123838-0.5};
        state_type B {-0.110549 + 0.5, 0.0123838+0.5};
        Moving(Size, StartTime);
        Ensemble init;
        init(Size, StartTime);
        Moving.evolve2( EndTime, 0, Cvalue.C);
        std::cout << "C=" << LinearRamp(EndTime*period, 0, Cvalue.C) << "\n";
        std::cout << "frozen basin starts" << std::endl;
        Moving.write(path + "end.txt");
        Cvalue.Basin(Moving, 0.05);
        Ensemble Frozen = Cvalue.PrintBasin2(path, init, RampTime);
        std::cout << "frozen basin ends" << std::endl;
        Ensemble Moving2;
        for(std::vector<double> element : Frozen.Points){
            Moving2.Points.push_back(element);
        }
        Moving2.evolve2( EndTime, RampTime, Cvalue.C);
        std::cout << "C=" << LinearRamp(EndTime*period, RampTime, Cvalue.C) << "\n";
        std::cout << "frozen basin starts" << std::endl;
        Moving.write(path + "end.txt");
        Cvalue.Basin(Moving, 0.05);
        Cvalue.PrintBasin(path, init, RampTime, 0);
        std::cout << "frozen basin ends" << std::endl;
    }



void TestLinearRamp(std::string path,
    Ensemble Moving,
    Ensemble init,
    double StartTime,
    double EndTime,
    double RampTime,
    Bifurcation& Cvalue,
    int Size, int evolve){
        
        Moving.evolve2( EndTime, RampTime, Cvalue.C);
        std::cout << "C=" << LinearRamp(EndTime*period, RampTime, Cvalue.C) << "\n";
        std::cout << "basin starts" << std::endl;
        Moving.write(path + "end.txt");
        Cvalue.Basin(Moving, 0.05);
        Cvalue.PrintBasin(path, init, RampTime, evolve);
        std::cout << "basin ends" << std::endl;
    }


void TestLinearRamp(std::string path,
    double StartTime,
    double EndTime,
    double RampTime,
    Bifurcation& Cvalue,
    int Size){
        Ensemble Moving;
        Moving(Size, StartTime);
        Ensemble init;
        init(Size, StartTime);
        Moving.evolve2( EndTime, RampTime, Cvalue.C);
        std::cout << "C=" << LinearRamp(EndTime*period, RampTime, Cvalue.C) << "\n";
        std::cout << "basin starts" << std::endl;
        Cvalue.Basin(Moving, 0.05);
        std::vector <int> histogram = Cvalue.countbasin();
        std::ofstream output(path , std::ios_base::app);
        output << RampTime << " " ;
        for (const auto &e : histogram) output << e << " ";
        output << "\n";
        std::cout << "basin ends" << std::endl;
    }

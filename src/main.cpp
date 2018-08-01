#include "./ensemble.h"
#include "./bifurcation.h"
#include "./transients.h"
#include "./model.h"
extern const double Pi;
int main(int, char**) {
    auto period = 2.*Pi;
 std::cout << "tr"+std::to_string(196)+"/";
/*{
     Bifurcation Cvalue(1.8);

    Cvalue(100, 3000);
  /*  TestLinearRamp("build/output/0611/final_data/fig7/t5_zoom1/", 0., 100., 5., Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();
    TestLinearRamp("build/output/0611/final_data/fig7/t10_zoom1/", 0., 100., 10., Cvalue, 1000, 0);}
*/
    //TestLinearRamp("build/output/0611/final_data/fig15/t2/", 2.*period, 120, 10., Cvalue, 1000, 0);
    
    //Cvalue.BasinIndex.clear() ; 
    //TestLinearRamp("build/output/0611/final_data/fig13/t0/", 0., 120, 0., Cvalue, 1000, 0);
    //Cvalue.BasinIndex.clear();
    //TestLinearRamp("build/output/0611/final_data/fig13/t5/", 0., 120, 5., Cvalue, 1000, 0);
    /*TestLinearRamp("build/output/0611/final_data/fig8/tr27/", 0., 100, 27., Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();
    TestLinearRamp("build/output/0611/final_data/fig13/t5/", 0., 100, 7., Cvalue, 1000, 0);
    }*/

Bifurcation Cvalue(0.33);
Cvalue(20, 300);
for(int i = 0 ; i < 40; i ++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0611/escaperate033.txt", 0, i, 0., Cvalue, 1000);
        Cvalue.BasinIndex.clear(); 
}


for(int i = 5 ; i < 40; i ++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0611/escape_ramp033.txt", 0, i, 5., Cvalue, 1000);
        Cvalue.BasinIndex.clear(); 
}

/*TestLinearRamp("build/output/0611/final_data/fig3/t9_/", 0., 9, 5., Cvalue, 1000, 0);
Cvalue.BasinIndex.clear();
TestLinearRamp("build/output/0611/final_data/fig3/t12_/", 0., 12, 5., Cvalue, 1000, 0);
Cvalue.BasinIndex.clear();
TestLinearRamp("build/output/0611/final_data/fig3/t15_/", 0., 15, 5., Cvalue, 1000, 0);
Cvalue.BasinIndex.clear();
TestLinearRamp("build/output/0611/final_data/fig3/t20_/", 0., 20, 5., Cvalue, 1000, 0);
Cvalue.BasinIndex.clear();
*/

/*
    {Ensemble test;
    test(1000, -4.0*period);
    test.evolve3(104, 10., 0.5835, "build/output/0611/final_data/fig15/snap/snap_");}
  
 /*
    TestLinearRamp("build/output/0611/05835/t100/", 0., 500., 100., Cvalue, 500, 0);
    Cvalue.BasinIndex.clear();
    TestLinearRamp("build/output/0611/05835/t_6/", -50.*period, 300., 6., Cvalue, 500, 0);}
    /*      {
    Bifurcation Cvalue(0.33);
    Cvalue(50, 200);
    TestLinearRamp("build/output/0611/final_data/fig2/t0/", 0. , 100, 0, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();      
    TestLinearRamp("build/output/0611/final_data/fig2/t3/", 0. , 100, 3, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();
        TestLinearRamp("build/output/0611/final_data/fig2/t5/", 0. , 100, 5, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();      
    }*/
    /*for(int i = 0 ; i < 40; i ++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0611/dominant/tminn50.txt", -50.*period, i+200, i, Cvalue, 500);
        Cvalue.BasinIndex.clear();      
    }*/
    //DOMINANT:



    //plots for SCIREP

    //FIG 3:
    /*    std::cout << "FIG3: \n";

    {
        Bifurcation Cvalue(1.8);
    Cvalue(50, 3000);
    TestLinearRamp("build/output/0611/final_data/fig8/t27/", 0. , 100., 27., Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();  
    }

    {
        Bifurcation Cvalue(0.5835);
    Cvalue(50, 3000);
    TestLinearRamp("build/output/0611/final_data/fig11/t8/", 0. , 100., 8., Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();  
    }*/

   /* {Bifurcation Cvalue(0.33);
    Cvalue(50, 1000);
    TestLinearRamp("build/output/0611/final_data/fig3/t9/", 0. , 9., 5., Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();      

    TestLinearRamp("build/output/0611/final_data/fig3/t12/", 0.,12., 5., Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();     

    TestLinearRamp("build/output/0611/final_data/fig3/t15/", 0.,15., 5., Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();     

    TestLinearRamp("build/output/0611/final_data/fig8/033/", 0. , 100., 0, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();      */
 /*
    }
    //FIG 6:
    std::cout << "new plot: \n";

    for(int i = 0 ; i < 40; i ++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0611/dominant/tmin50.txt", -50.*period, i+100, i, Cvalue, 300);
        Cvalue.BasinIndex.clear();      
    }*/
    /*std::cout << "FIG6-10: \n";
    Cvalue(50, 3000);

        for(int i = 100 ; i > 50; i = i- 1){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0611/05835/testADAPTIVE.txt", 0., 100+i, i, Cvalue, 300);
        Cvalue.BasinIndex.clear();      
        }
    }*/       
    /*{
        Bifurcation Cvalue(0.5835);

    Cvalue(50, 3000);
    TestLinearRamp("build/output/0611/final_data/fig6/t5/", -5*period , 100, 5, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();      

    TestLinearRamp("build/output/0611/final_data/fig6/t20/", -20*period, 100, 5, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();     

    TestLinearRamp("build/output/0611/final_data/fig6/t35/", -35.*period,100, 5, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear(); 

    TestLinearRamp("build/output/0611/final_data/fig6/t40/", -40.*period,100, 5, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();   
    TestLinearRamp("build/output/0611/final_data/fig10/t0/", 0.,100, 0, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();   
    TestLinearRamp("build/output/0611/final_data/fig10/t5/", 0.,100, 5, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();

    TestLinearRamp("build/output/0611/final_data/fig10/t10/", 0.,100, 10, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();    
    TestLinearRamp("build/output/0611/final_data/fig10/t15/", 0.,100, 15, Cvalue, 1000, 0);

    Cvalue.BasinIndex.clear() ; 
    TestLinearRamp("build/output/0611/final_data/fig15/t2/", 2.*period, 120, 10., Cvalue, 1000, 0);
    
    Cvalue.BasinIndex.clear() ; 
    TestLinearRamp("build/output/0611/final_data/fig15/t_2/", -2.*period, 120, 10., Cvalue, 1000, 0);
    
    }
    //FIG8: 
        std::cout << "FIG8: \n";
   
    {
    Bifurcation Cvalue(1.8);
    Cvalue(50, 3000);
    std::cout << "done " ;
        TestLinearRamp("build/output/0611/final_data/fig8/t7/", 0. , 400, 20, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();      
    }

 {Ensemble test;
    test(1000, -2.0*period);
    test.evolve3(20, 10., 0.5835, "build/output/0611/final_data/fig15/snap/snap_");}
  
    {Ensemble test;
    test(1000, 0.);
    test.evolve3(20., 5., 0.33, "build/output/0611/final_data/fig3/snap/snap_");}
  
      {
    Bifurcation Cvalue(0.33);
    Cvalue(50, 200);
    TestLinearRamp("build/output/0611/final_data/fig2/t0/", 0. , 100, 0, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();      
    TestLinearRamp("build/output/0611/final_data/fig2/t3/", 0. , 100, 3, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();
        TestLinearRamp("build/output/0611/final_data/fig2/t5/", 0. , 100, 5, Cvalue, 1000, 0);
    Cvalue.BasinIndex.clear();      
    }
Bifurcation Cvalue(0.5835);

    Cvalue(50, 3000);
    for(int i = 0 ; i < 40; i ++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0611/dominant/tminn50.txt", -50.*period, i+200, i, Cvalue, 500);
        Cvalue.BasinIndex.clear();      
    }
    {Ensemble test;
    test(500, -4.0*period);
    test.evolve3(140.0, 32., 1.6472, "build/output/0611/snapshot_compare/alt/snap164_alt/snapshot_");}
    /*for(int i = 0 ; i < 50; i = i+5){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0611/05835/testADAPTIVE.txt", 0., 100, i, Cvalue, 300);
        Cvalue.BasinIndex.clear();      
    }
    /*for(int i = 0 ; i < 300; i = i+10){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0611/05835/testADAPTIVE.txt", 0., i+100, i, Cvalue, 200);
        Cvalue.BasinIndex.clear();      
    }
        Cvalue.BasinIndex.clear();      

/*    TestLinearRamp("build/output/0611/05835/tr200/", 0., 300, 200., Cvalue, 500, 1);
        Cvalue.BasinIndex.clear();      
    TestLinearRamp("build/output/0611/05835/tr100/", 0., 300, 100., Cvalue, 500, 1);
        Cvalue.BasinIndex.clear();      
    TestLinearRamp("build/output/0611/05835/tr250/", 0., 300, 250., Cvalue, 500, 1);
        Cvalue.BasinIndex.clear();      
    TestLinearRamp("build/output/0611/05835/tr198/", 0., 300, 198., Cvalue, 500, 1);

        Bifurcation Cvalue2(0.50);
        Cvalue2(50, 3000);

    for(int i = 0 ; i < 300; i= i + 10){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0611/050/test.txt", 0., i+100, i, Cvalue, 300);
        Cvalue.BasinIndex.clear();      
    }
        Cvalue.BasinIndex.clear();      

    TestLinearRamp("build/output/0611/050/tr200/", 0., 300, 200., Cvalue, 300, 1);
        Cvalue.BasinIndex.clear();      
    TestLinearRamp("build/output/0611/050/tr100/", 0., 300, 100., Cvalue, 300, 1);
        Cvalue.BasinIndex.clear();      
    TestLinearRamp("build/output/0611/050/tr250/", 0., 300, 250., Cvalue, 300, 1);
        Cvalue.BasinIndex.clear();      
    TestLinearRamp("build/output/0611/050/tr198/", 0., 300, 198., Cvalue, 300, 1);

        
 //       TestLinearRamp("build/output/0611/05835/TRY/", -5*period, 100, 5., Cvalue, 500, 0);
/* {  
        std::cout << "asd" << "\n";
        TestLinearRamp("build/output/0611/05835/tr210/", 0, 400, 210., Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
        TestLinearRamp("build/output/0611/05835/tr190/", 0, 400, 190., Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
        TestLinearRamp("build/output/0611/05835/tr100/", 0, 400, 100., Cvalue, 500, 0);*/
        /*Bifurcation Cvalue(0.5835);
        Cvalue(50, 3000);
        TestLinearRamp("build/output/0611/05835/tr200/", 0, 300, 200., Cvalue, 200, 1);
*/
   /*for(int i = 189 ; i < 205; i++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0611/05835/tr"+std::to_string(i)+"/", 0., i+100, i, Cvalue, 300, 0);
        Cvalue.BasinIndex.clear();      
    }
  /*}

  {
      Bifurcation Cvalue(0.37);
        Cvalue(50, 3000);
        TestLinearRamp("build/output/0611/basins/037/", 0, 200, 0., Cvalue, 500, 0);

  }

  {
      Bifurcation Cvalue(0.42);
        Cvalue(50, 3000);
        TestLinearRamp("build/output/0611/basins/042/", 0, 200, 0., Cvalue, 500, 0);

  }
    

  {
      Bifurcation Cvalue(0.45);
        Cvalue(50, 3000);
        TestLinearRamp("build/output/0611/basins/045/", 0, 200, 0., Cvalue, 500, 0);

  }

  {
      Bifurcation Cvalue(0.5);
        Cvalue(50, 3000);
  
        TestLinearRamp("build/output/0611/basins/05/", 0, 200, 0., Cvalue, 500, 0);
  }

  {
      Bifurcation Cvalue(0.55);
        Cvalue(50, 3000);
        TestLinearRamp("build/output/0611/basins/055/", 0, 200, 0., Cvalue, 500, 0);

  }
    /*    Bifurcation Cvalue(0.5835);
        Cvalue(50, 3000);
    for(int i = 100 ; i< 400; i=i+50){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0611/05835/test.txt", 0., i+100, i, Cvalue, 500);
        Cvalue.BasinIndex.clear();      
    }
/*
    {
        Bifurcation Cvalue(0.5835);
        Cvalue(50, 3000);
        TestLinearRamp("build/output/0611/snapshot_compare/c_01/tobs100/", -10*period, 120, 20., Cvalue, 1000, 0);
        Cvalue.BasinIndex.clear();      
        TestLinearRamp("build/output/0611/snapshot_compare/c_01/tobs20/", -10.*period, 20., 20., Cvalue, 1000, 0);
        Cvalue.BasinIndex.clear();      
        TestLinearRamp("build/output/0611/snapshot_compare/c_01/tobs4/", -10.*period, 4., 20., Cvalue, 1000,0);
        Cvalue.BasinIndex.clear();      
        TestLinearRamp("build/output/0611/snapshot_compare/t_/c_01/tobs100/", 0., 120, 20., Cvalue, 1000, 0);
        Cvalue.BasinIndex.clear();      
        TestLinearRamp("build/output/0611/snapshot_compare/t_/c_01/tobs20/", 0., 20., 20., Cvalue, 1000, 0);
        Cvalue.BasinIndex.clear();      
        TestLinearRamp("build/output/0611/snapshot_compare/t_/c_01/tobs4/", 0., 4., 20., Cvalue, 1000,0);

    }
*/

    /*{
        std::cout << "asd\n";

        Bifurcation Cvalue(1.2051);
        Cvalue(50, 3000);
   
        TestLinearRamp("build/output/0611/snapshot_compare/final/c_01_cp110/", -7.*period, 116., 16., Cvalue, 500, 0);
        std::cout << "asd\n";
    }

    {
        std::cout << "asd\n";

        Bifurcation Cvalue(1.2051);
        Cvalue(50, 3000);
   
        TestLinearRamp("build/output/0611/snapshot_compare/final/c_01_cp110/snap", -7.*period, 7., 16., Cvalue, 500, 0);
        std::cout << "asd\n";
    }


    {
        Bifurcation Cvalue(1.2051);
        Cvalue(50, 3000);
   
        TestLinearRamp("build/output/0611/snapshot_compare/final/c_01_cp110_/", -7.*period, 16., 16., Cvalue, 500, 0);

    }

    {
        Bifurcation Cvalue(1.2051);
        Cvalue(50, 3000);
   
        TestLinearRamp("build/output/0611/snapshot_compare/final/c_01_cp110_/35", -7.*period, 35., 16., Cvalue, 500, 0);

    }

    {
        Bifurcation Cvalue(1.6886);
        Cvalue(20, 100);
        TestLinearRamp("build/output/0611/snapshot_compare/final/c_01_cp165/", -7*period, 35., 23., Cvalue, 500, 0);

    }

        

    {
    Ensemble mov, init;
    Bifurcation Cvalue(1.2051);
    Cvalue(50, 3000);
    mov.read("build/output/0611/basin05835/basin0.txt");
    mov.read("build/output/0611/basin05835/basin1.txt");

    init.read("build/output/0611/basin05835/basin0.txt");
    init.read("build/output/0611/basin05835/basin1.txt");

    TestLinearRamp("build/output/0611/t_/1/", mov,init, 7.*period, 107., 16., Cvalue, 500, 0);
    Cvalue.BasinIndex.clear();            
    
    }
    
        {
    Ensemble mov, init;
    Bifurcation Cvalue(1.2051);
    Cvalue(50, 3000);
    mov.read("build/output/0611/basin05835/basin2.txt");
    mov.read("build/output/0611/basin05835/basin3.txt");

    init.read("build/output/0611/basin05835/basin2.txt");
    init.read("build/output/0611/basin05835/basin3.txt");

    TestLinearRamp("build/output/0611/t_/2/", mov,init, 7.*period, 107., 16., Cvalue, 500, 0);
    Cvalue.BasinIndex.clear();            
    
    }
    
        {
    Ensemble mov, init;
    Bifurcation Cvalue(1.2051);
    Cvalue(50, 3000);
    mov.read("build/output/0611/basin05835/basin4.txt");
    mov.read("build/output/0611/basin05835/basin5.txt");

    init.read("build/output/0611/basin05835/basin4.txt");
    init.read("build/output/0611/basin05835/basin5.txt");

    TestLinearRamp("build/output/0611/t_/3/", mov,init, 7.*period, 107., 16., Cvalue, 500, 0);
    Cvalue.BasinIndex.clear();            
    
    }*/

    //ALT
/*
    {
        std::cout << "asd\n";

        Bifurcation Cvalue(0.5835);
        Cvalue(50, 3000);
   
        TestLinearRamp("build/output/0611/snapshot_compare/alt/c_01_cp05835/", -2.*period, 120., 20., Cvalue, 500, 0);
        std::cout << "asd\n";
    }

    {
        std::cout << "asd\n";

        Bifurcation Cvalue(0.5835);
        Cvalue(50, 3000);
   
        TestLinearRamp("build/output/0611/snapshot_compare/alt/c_01_cp05835/snap", -2.*period, 4., 20., Cvalue, 500, 0);
        std::cout << "asd\n";
    }

*//*
    {
        Bifurcation Cvalue(0.5835);
        Cvalue(50, 3000);
   
        TestLinearRamp("build/output/0611/snapshot_compare/alt/c_01_cp05835/", -4.*period, 120., 10., Cvalue, 500, 0);

    }

    {
        Bifurcation Cvalue(0.5835);
        Cvalue(50, 3000);
   
        TestLinearRamp("build/output/0611/snapshot_compare/alt/c_02_cp05835/", 2.*period, 120., 10., Cvalue, 500, 0);

    }
*//*
    {Ensemble test;
    test(500, -2.0*period);
    test.evolve3(140.0, 10., 0.5835, "build/output/0611/snapshot_compare/alt/snap05835_alt/snapshot_2");}*/
  /*  
    {Ensemble test;
    test(500, -4.0*period);
    test.evolve3(140.0, 32., 1.6472, "build/output/0611/snapshot_compare/alt/snap164_alt/snapshot_");}
*/

/*
    {
        Bifurcation Cvalue(0.5835);
        Cvalue(50, 3000);
   
        TestLinearRamp("build/output/0611/snapshot_compare/alt/c_01_cp05835_/70", -2.*period, 70., 20., Cvalue, 500, 0);

    }

    {
        Bifurcation Cvalue(1.6472);
        Cvalue(20, 100);
        TestLinearRamp("build/output/0611/snapshot_compare/alt/c_01_cp164/", -2*period, 70., 64., Cvalue, 500, 0);

    }

    {
        Bifurcation Cvalue(0.5835);
        Cvalue(50, 3000);
        TestLinearRamp("build/output/0611/snapshot_compare/alt/c_02_cp05835/", 4.*period, 120., 20., Cvalue, 500, 0);

    }
        

    /*

    /*
    std::ofstream output("build/output/0515/bifurcation_02_033.txt", std::ios_base::app);
    for(int i = 0; i < numsteps; i++){
        Cval.C = cmin + i*dc;
        Cval.attractors.clear();
        Cval(50, 300);
        std::cout << Cval.C << " " << Cval.attractors.size() << "\n";
        for(const auto attr : Cval.attractors){
            //std::cout << Cval.C << " " << attr[1] << " " << attr[2] << "\n";
            output << Cval.C << " " << attr[1] << " " << attr[2] << "\n";

        }
    }
    /*{
    Ensemble mov, init;
    Bifurcation Cvalue(1.8);
    Cvalue(50, 3000);
    mov.read("build/output/0416/033_18/033attr/basin1.txt");
    init.read("build/output/0416/033_18/033attr/basin1.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0416/033_18/blue/tr"+std::to_string(i)+"/", mov,init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    }*/
    /*Bifurcation Cvalue(1.50);
    Cvalue(50, 3000);
    std::cout << Cvalue.attractors.size() << "\n";
    for(int i = 0 ; i< 1; i++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0416/15_18/15basin/",
                        0., 100, 0, Cvalue, 500, 0);
        Cvalue.BasinIndex.clear();      
    }
    Ensemble test;
    test(1000);
    test.evolve3(100., 20., 1.64, "build/output/0416/snapshot/snap_");
    /*{
    Bifurcation Cvalue(1.80);
    Cvalue(50, 3000);
    for(int i = 0 ; i< 41; i++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0416/16_18/tr"+std::to_string(i)+"/",
                        0., 100, i*1.0, Cvalue, 500, 0);
        Cvalue.BasinIndex.clear();      
    }
    }*/
    //Ensemble test;
    //test(500, -10.0*period);
    //test.evolve3(100.0, 10., 0.5835, "build/output/0323/058/snapshot_attr/snapshot_");
    /*{
    Ensemble mov, init;
    Bifurcation Cvalue(1.95);
    Cvalue(50, 3000);
    mov.read("build/output/0416/165_185/165basin/basin1.txt");
    init.read("build/output/0416/165_185/165basin/basin1.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0416/165_185/red/tr"+std::to_string(i)+"/", mov,init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }/*
    {
    Bifurcation Cvalue(0.33);
    Cvalue(50, 3000);
    for(int i = 0 ; i< 1; i++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0416/033basin/",
                        0., 100, 0, Cvalue, 2000, 0);
        Cvalue.BasinIndex.clear();      
    }
    
}*/
    /*Ensemble test;
    test.read("test2/basin2.txt");
    test.evolve3(100.0, 35., 0.5835, "test2/snapshot_");*/
    /*Bifurcation Cvalue(1.80);
    Cvalue(50, 3000);
    std::cout << Cvalue.attractors.size() << "\n";
    for(int i = 0 ; i< 1; i++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0416/165_185/165basin/",
                        0., 100, 0, Cvalue, 500, 0);
        Cvalue.BasinIndex.clear();      
    }*/

    /*std::vector<int> Tr;
    Tr.push_back(85);
    Tr.push_back(90);
    Tr.push_back(95);
    Tr.push_back(100);
    Tr.push_back(105);
    
{
    Ensemble mov, init;
    Bifurcation Cvalue(1.26);
    Cvalue(50, 3000);
        mov.read("build/output/0323/106_126/106_basin/basin1.txt");
        init.read("build/output/0323/106_126/106_basin/basin1.txt");
        for(const int i : Tr){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0323/106_126/piros/tr"+std::to_string(i)+"/", mov,init,
                        0., 150, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }*/
/*{
    Ensemble mov, init;
    Bifurcation Cvalue(0.5835);
    Cvalue(50, 3000);
    mov.read("build/output/0416/033basin/basin2.txt");
    init.read("build/output/0416/033basin/basin2.txt");
        for(int i=30; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0416/red/tr"+std::to_string(i)+"/", mov,init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }
{
    Bifurcation Cvalue(1.045);
    Cvalue(50, 3000);
    for(int i = 0 ; i< 1; i++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0323/082_1045/green_chaotic_basin/",
                        0., 100, 0, Cvalue, 500, 0);
        Cvalue.BasinIndex.clear();      
    }
}
    /*std::vector<int> Tr(40);
    std::iota(std::begin(Tr), std::end(Tr),0);
    Tr.push_back(50);
    Tr.push_back(55);
    Tr.push_back(60);
    Tr.push_back(65);
    Tr.push_back(70);
    Tr.push_back(75);
    Tr.push_back(80);
{
    Ensemble mov, init;
    Bifurcation Cvalue(1.26);
    Cvalue(50, 3000);
        mov.read("build/output/0323/106_126/106_basin/basin0.txt");
        init.read("build/output/0323/106_126/106_basin/basin0.txt");
        for(const int i : Tr){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0323/106_126/zold/tr"+std::to_string(i)+"/", mov,init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }
    {
    Ensemble mov, init;
    Bifurcation Cvalue(1.26);
    Cvalue(50, 3000);
        mov.read("build/output/0323/106_126/106_basin/basin1.txt");
        init.read("build/output/0323/106_126/106_basin/basin1.txt");
        for(const int i : Tr){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0323/106_126/piros/tr"+std::to_string(i)+"/", mov,init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }

/*
    for(int i = 0 ; i< 20; i++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0323/05835_s/tr"+std::to_string(i)+"/",
                        0., 100, i, Cvalue, 500, 0);
        Cvalue.BasinIndex.clear();      
    }
    /*{
    Ensemble mov, init;
    Bifurcation Cvalue(0.72);
    Cvalue(50, 3000);
        mov.read("build/output/0323/062_basin/basin0.txt");
        mov.read("build/output/0323/062_basin/basin1.txt");
        init.read("build/output/0323/062_basin/basin0.txt");
        init.read("build/output/0323/062_basin/basin1.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0323/062_072/piros/tr"+std::to_string(i)+"/", mov,init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }
    {
    Ensemble mov, init;
    Bifurcation Cvalue(0.72);
    Cvalue(50, 3000);
        mov.read("build/output/0323/062_basin/basin2.txt");
        mov.read("build/output/0323/062_basin/basin3.txt");
        init.read("build/output/0323/062_basin/basin2.txt");
        init.read("build/output/0323/062_basin/basin3.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0323/062_072/zold/tr"+std::to_string(i)+"/", mov,init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }

    {
    Ensemble mov, init;
    Bifurcation Cvalue(0.82);
    Cvalue(50, 3000);
        mov.read("build/output/0323/062_basin/basin0.txt");
        mov.read("build/output/0323/062_basin/basin1.txt");
        init.read("build/output/0323/062_basin/basin0.txt");
        init.read("build/output/0323/062_basin/basin1.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0323/062_082/piros/tr"+std::to_string(i)+"/", mov,init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }
    {
    Ensemble mov, init;
    Bifurcation Cvalue(0.82);
    Cvalue(50, 3000);
        mov.read("build/output/0323/062_basin/basin2.txt");
        mov.read("build/output/0323/062_basin/basin3.txt");
        init.read("build/output/0323/062_basin/basin2.txt");
        init.read("build/output/0323/062_basin/basin3.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0323/062_082/zold/tr"+std::to_string(i)+"/", mov,init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }

    std::vector<int> Ts(50);
    std::iota(std::begin(Ts), std::end(Ts),0);
        Bifurcation Cvalue(0.5835);
    Cvalue(50, 3000);
    {

    for(const int i : Ts){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0323/switch_ts/tr10/ts"+std::to_string(i)+"/",
                        -i*period, 100, 10, Cvalue, 500, 0);
        Cvalue.BasinIndex.clear();      
    }
    }/*
    {
    Bifurcation Cvalue(0.82);

    for(int i = 0; i < 41; i++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0323/062_082/tr"+std::to_string(i)+"/",
                        0, 100, i, Cvalue, 500, 0);
        Cvalue.BasinIndex.clear();      
        }
    }
    //Zold
    /*{
    Bifurcation Cvalue(0.5835);
    Cvalue(50, 3000);
    for(int i = 0; i<41; i++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0218/opposite_phase/05835/ts_5/ts"+std::to_string(i)+"/",
                        -1.*i*period, 100, 5.0, Cvalue, 500, 0);
        Cvalue.BasinIndex.clear();      
        }
    }
    {
    Bifurcation Cvalue(0.5835);
    Cvalue(50, 3000);
    for(int i = 0; i<41; i++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0218/opposite_phase/05835/ts_10/ts"+std::to_string(i)+"/",
                        -1.*i*period, 100, 10.0, Cvalue, 500, 0);
        Cvalue.BasinIndex.clear();      
        }
    }
    {
    Bifurcation Cvalue(0.5835);
    Cvalue(50, 3000);
    for(int i = 0; i<41; i++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0218/opposite_phase/05835/tr"+std::to_string(i)+"/",
                        0., 100, i*1.0, Cvalue, 500, 0);
        Cvalue.BasinIndex.clear();      
        }
    }

    {
    Ensemble mov, init;
    Bifurcation Cvalue(0.5835);
    Cvalue(50, 3000);
        mov.read("build/output/0131/full/033/tr0/basin2.txt");
        init.read("build/output/0131/full/033/tr0/basin2.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0218/TIP05835/piros/tr"+std::to_string(i)+"/", mov,init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }

    {
    Ensemble mov, init;
    Bifurcation Cvalue(0.5835);
    Cvalue(50, 3000);
        mov.read("build/output/0131/full/033/tr0/basin1.txt");
        init.read("build/output/0131/full/033/tr0/basin1.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0218/TIP05835/kek/tr"+std::to_string(i)+"/", mov,init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }

    {
    Ensemble mov, init;
    Bifurcation Cvalue(0.5835);
    Cvalue(50, 3000);
        mov.read("build/output/0131/full/033/tr0/basin0.txt");
        init.read("build/output/0131/full/033/tr0/basin0.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0218/TIP05835/zold/tr"+std::to_string(i)+"/", mov,init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }
    //std::vector<int> Tr {45, 50, 55, 60, 65, 80};
    {
            Bifurcation Cvalue(0.5835);
    Cvalue(50, 3000);
    for(int i = 0; i<41; i++){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0131/full/05835_s/ts/ts"+std::to_string(i)+"/",
                        -1.*i*period, 100, 5.0, Cvalue, 500, 0);
        Cvalue.BasinIndex.clear();      
        }
    }


    {
        Ensemble mov, init;
    Bifurcation Cvalue(0.5835);
    Cvalue(50, 3000);
        mov.read("build/output/0131/full/05835/tr0/basin0.txt");
        init.read("build/output/0131/full/05835/tr0/basin0.txt");
        mov.read("build/output/0131/full/05835/tr0/basin1.txt");
        init.read("build/output/0131/full/05835/tr0/basin1.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0218/TOP05835/zold/tr"+std::to_string(i)+"/", mov,init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        

    }
    //Kek
    {
    Ensemble mov, init;
    Bifurcation Cvalue(0.5835);
    Cvalue(50, 3000);
        mov.read("build/output/0131/full/05835/tr0/basin2.txt");
        init.read("build/output/0131/full/05835/tr0/basin2.txt");
        mov.read("build/output/0131/full/05835/tr0/basin3.txt");
        init.read("build/output/0131/full/05835/tr0/basin3.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0218/TOP05835/kek/tr"+std::to_string(i)+"/", mov, init, 
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    }
    {
    Ensemble mov, init;
        Bifurcation Cvalue(0.5835);
    Cvalue(50, 3000);
        mov.read("build/output/0131/full/05835/tr0/basin4.txt");
        init.read("build/output/0131/full/05835/tr0/basin4.txt");
        mov.read("build/output/0131/full/05835/tr0/basin5.txt");
        init.read("build/output/0131/full/05835/tr0/basin5.txt");
        for(int i=0; i < 17; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0218/TOP05835/piros/tr"+std::to_string(i)+"/", mov, init,
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }*/
    //Piros
/*
    std::vector<int> Tr {45, 50, 55, 60, 65, 80};
    {
        for(const auto i : Tr){
        std::cout << i << "\n";
        TestLinearRamp("build/output/0131/full/05835_s/tr"+std::to_string(i)+"/", 
                        0., 100, i*1.0, Cvalue, 500, 0);
        Cvalue.BasinIndex.clear();      
        }
    }


    {
        Ensemble mov, init;

        mov.read("build/output/0131/full/033/tr0/basin0.txt");
        init.read("build/output/0131/full/033/tr0/basin0.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0218/TIP05835/zold/tr"+std::to_string(i)+"/", 
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        

    }
    //Kek
    {
    Ensemble mov, init;

        mov.read("build/output/0131/full/033/tr0/basin1.txt");
        init.read("build/output/0131/full/033/tr0/basin1.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0218/TIP05835/kek/tr"+std::to_string(i)+"/", 
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    }
    //Piros
    {
    Ensemble mov, init;

        mov.read("build/output/0131/full/033/tr0/basin2.txt");
        init.read("build/output/0131/full/033/tr0/basin2.txt");
        for(int i=0; i < 41; i++){
            std::cout << i << "\n";
            TestLinearRamp("build/output/0218/TIP05835/piros/tr"+std::to_string(i)+"/", 
                        0., 100, i*1.0, Cvalue, 500, 0);
            Cvalue.BasinIndex.clear();      
            }        
    
    }*/
    return 0;
}

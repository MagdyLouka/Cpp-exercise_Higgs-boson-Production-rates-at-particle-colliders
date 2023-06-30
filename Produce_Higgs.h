#include <iostream>
#include <map>
#include <string>

//creating the calculator class                       
class Higgs{
private: // Hidden class members: data (attributes) and methods that are accessble only from inside the class 
  double xsection1;
  double xsection2;
  std::string cme;
  std::string decay;
  double br;
  
  // Data members (Maps) that hold the collision data
  std::map<std::string, double> BR_map{ {"bb",0.577},{"tt",0.0632},{"mm", 0.00022},{"cc",0.0291},{"gg", 0.0857},{"phph",0.00228},{"zph",0.00154},{"ww",0.215},{"zz",0.0264} };
  std::map<double, double> Xsection_pp{ {8,19.31},{13,48.61},{14,50.35},{33,178.3},{40,231.9},{60,394.4},{80,565.1},{100,740.3} };
  std::map<double, double> Xsection_ee{ {200.0,0.004},{220.,0.092},{240.,0.200},{250.,0.219},{260.,0.214},{280.,0.203},{300.,0.190},{320.,0.176},{340.,0.165},{360.,0.155} };
  
  // A class method to caculate the coss secion using two arguments
  double calculateXsection(std::string collider, int cme) {
    if(collider=="pp") xsection1 = Xsection_pp[cme];
    if(collider=="ee") xsection1 = Xsection_ee[cme];
    return xsection1;
  }
  // A class method to caculate the coss secion times the BR using three arguments
  double calculateXsection_BR(std:: string collider, double cme, std::string decay) {
    xsection2 = calculateXsection(collider,cme);    
    br = BR_map[decay];
    return xsection2 * br;
  }
  
public: // public class members to be accessed by the users
  double Xsection;
  double Xsection_BR;
  // class constructor which seeks the arguments from the user 
  Higgs (std::string Collider, int CME, std::string DecayChannel){
    Xsection = calculateXsection(Collider,CME);
    Xsection_BR = calculateXsection_BR(Collider,CME,DecayChannel);
  }
  
}; // end of class defnition

//----------------------------------------------------------------------------------
//Two functions for the graphics
std::string userbeam, decay, b1,b2,d1,d2;
// Maps that hold the letters of the beam paticles and the fragments
std::map<std::string,std::string> frag1{ {"bb","b"},{"tt","t"},{"mm","mu-"},{"cc","c"},{"gg","g"},{"phph","ph"},{"zph","z"},{"ww","w-"},{"zz","z"} };
std::map<std::string,std::string> frag2{ {"bb","b~"},{"tt","t~"},{"mm","mu+"},{"cc","c~"},{"gg","g"},{"phph","ph"},{"zph","ph"},{"ww","w+"},{"zz","z"} };
std::map<std::string,std::string> beam1{ {"pp","p"},{"ee","e-"} };
std::map<std::string,std::string> beam2{ {"pp","p"},{"ee","e+"} };

// sketch of the collision process 
void Collision(std::string userbeam, int energy){
  b1 = beam1[userbeam];
  b2 = beam2[userbeam];
  std::cout<<"_____________________________________________________________\n";
  std::cout<<"\n";
  std::cout<<" Lets Collide "<<userbeam<<" with a c.m.e of "<<energy<<"\n";
  std::cout<<"  "<<b1<<"  ---------->    <----------  "<<b2<<"  "<<"\n";
  //std::cout<<"_____________________________________________________________\n";
}

// Feynman diagram of the process
void Feynman_diagram(std::string userbeam, std::string decay ){
  b1 = beam1[userbeam];
  b2 = beam2[userbeam];
  d1 = frag1[decay];
  d2 = frag2[decay];
  //std::cout<<"______________________________________________________________\n";
  std::cout<<" "<<b1<<"                                     "<<d1<<"      \n";
  std::cout<<"      *                           *                         \n";
  std::cout<<"        *                      *                            \n";
  std::cout<<"          *                 *                               \n";
  std::cout<<"           ******( H )*****                                 \n";
  std::cout<<"          *                 *                               \n";
  std::cout<<"        *                      *                            \n";
  std::cout<<"      *                           *                         \n";
  std::cout<<" "<<b2<<"                                     "<<d2<<"      \n";
  std::cout<<"_____________________________________________________________\n";
}

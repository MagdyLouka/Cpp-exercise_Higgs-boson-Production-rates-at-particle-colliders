//---------------------------------------
// Creating two classes "PH" and "draw"
//---------------------------------------
#include<iostream>
using namespace std;

//creating the calculator class                       
class PH {
  double BR; // Higgs decay branching fraction
  double CME; // center of mass enery
  double Xsection; // total cross section
  
public:
  void set_values(double x, double y, double z){ // a member function that set the parameters
    CME = x;
    BR = y;
    Xsection = z;
  }
  // a member function which returns the fudicial cross section based on the c.m.e
  double calculateXsection() {
    return Xsection;
  }
  // a member function which returns the cross section times the branching fraction                                                                                                         
  double calculateXsection_BR() {
    return Xsection * BR;
  }
};
//-----------------------------------------
  //creating the graphics class
  class draw {
  public:
    string beam2, string1, string2, string3;
    int energy;
    // a member function that prints a schematic diagram of the collision type
    void Collision(string beam2, int energy){
      if (beam2=="pp") {string1 = "Protons"; string2 = "p"; string3 = "p";}
      if (beam2=="ee") {string1 = "Electrons"; string2 = "e-"; string3 = "e+";}
      cout<<"_____________________________________________________________\n";
      cout<<"\n";
      cout<<" Lets Collide "<<string1<<" with a c.m.e of "<<energy<<" TeV\n";
      cout<<"  "<<string2<<"  ---------->    <----------  "<<string3<<"  "<<"\n";
      cout<<"_____________________________________________________________\n";
    }
    
    string beam1, d1,d2;
    // a member function that prints the leading order Feynman diagram
    void Feynman_diagram(string beam1, string d1, string d2){
      if (beam1=="pp") {string1 = "Protons"; string2 = "p"; string3 = "p";}
      if (beam1=="ee") {string1 = "Electrons"; string2 = "e-"; string3 = "e+";}
      cout<<"______________________________________________________________\n";
      cout<<" "<<string2<<"                                   "<<d1<<"   \n";
      cout<<"      *                           *                         \n";
      cout<<"        *                      *                            \n";
      cout<<"          *                 *                               \n";
      cout<<"           ******( H )*****                                 \n";
      cout<<"          *                 *                               \n";
      cout<<"        *                      *                            \n";
      cout<<"      *                           *                         \n";
      cout<<" "<<string3<<"                                   "<<d2<<"   \n";
      cout<<"_____________________________________________________________\n";
      
    }
   
  };

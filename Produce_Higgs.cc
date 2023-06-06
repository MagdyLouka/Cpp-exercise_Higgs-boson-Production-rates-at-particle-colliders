//=============================================================================
//     Macro to Browse the Higgs production rate at particle colliders
//                     Magdy Louka - May 2023
//=============================================================================

#include "Produce_Higgs.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
  string collider;
  double cme;
  string decayC;
  double Xsection;
  double BR_value;
  cout<<"______________________________________________________________________________ \n";
  cout<<"\n";
  cout<<" Hello :) \n";
  cout<<" You are going to produce the Higgs boson\n";
  cout<<"______________________________________________________________________________\n";
  cout<<"\n";
  cout<<" Choose from the available collideres:- \n";
  cout<<"                                     'pp' for proton-proton collider  \n";
  cout<<"                                     'ee' for electron-positron collider \n";
  cout<<"______________________________________________________________________________\n";
  cout<<" The collider is: "; cin>>collider; // reading the collider type from the user
  cout<<"\n";
  
  if (collider=="pp"){
    cout<<" Please choose the c.m collision energy\n";
    cout<<" The c.m energies available are: \n";
    cout<<"                                   8 / 13 / 14 / 33 / 40 / 60 / 80 / 100 [TeV]\n";
    cout<<" The energy is: ";cin>>cme; // reading the center of mass energy from the user
    cout<<"\n";

  if (cme!=8 && cme!=13 && cme!=14 && cme!=33 && cme!=40 && cme!=60 && cme!=80 && cme!=100) {cout<<" Sorry ... this collision energy is not available ... Please choose from the list \n"; exit(0);}
  }
  
  if (collider=="ee"){
    cout<<" Please choose the c.m collision energy\n";
    cout<<" The c.m energies available are: \n";
    cout<<"                                   200 / 220 / 240 / 250 / 260 / 280 / 300 / 320 / 340 / 360 [GeV]\n";
    cout<<" The energy is: ";cin>>cme; // reading the center of mass energy from the user 
    cout<<"\n";
    
  if (cme!=200 && cme!=220 && cme!=240 && cme!=250 && cme!=260 && cme!=280 && cme!=300 && cme!=320 && cme!=340 && cme!=360) {cout<<" Sorry ... this collision energy is not available ... Please choose from the list \n"; exit(0);}
  }
  else if (collider!="pp" && collider!="ee") {cout<<" Please enter a valid collider option \n"; exit(0);}
 
  draw graph; // creating an object of the class "draw"  
  graph.Collision(collider,cme); // calling a class member (method)
  cout<<"________________________________________________________________________________\n";
  cout<<" Now let's decay the Higgs boson \n";
  cout<<" Please choose from the available final states:- \n";
  cout<<"                                     'bb'   for b anti-b quarks   (H → bb)   \n";                                                   
  cout<<"                                     'tt'   for t anti-t quarks   (H → ττ)   \n";
  cout<<"                                     'mm'   for muon anti-muon    (H → μμ)   \n";
  cout<<"                                     'cc'   for c anti-c quarks   (H → cc)   \n";
  cout<<"                                     'gg'   for di-gluons         (H → gg)   \n";
  cout<<"                                     'phph' for di-photons        (H → γγ)   \n";
  cout<<"                                     'zph'  for Z boson+photon    (H → Zγ)   \n";
  cout<<"                                     'ww'   for WW bosons         (H → WW)   \n";
  cout<<"                                     'ZZ'   for ZZ bosons         (H → ZZ)   \n";
  cout<<"________________________________________________________________________________\n";
  cout<<" Please enter the channel: "; cin>>decayC;
  if (collider=="pp"){ // declaration of the cross sections values  
    if (cme==8) Xsection = 19.31;
    if (cme==13) Xsection = 48.61;
    if (cme==14) Xsection = 50.35;
    if (cme==33) Xsection = 178.3;
    if (cme==40) Xsection = 231.9;
    if (cme==60) Xsection = 394.4;
    if (cme==80) Xsection = 565.1;
    if (cme==100) Xsection = 740.3;
  }
  
  if (collider=="ee"){ // declaration of the cross sections values
    if (cme==200) Xsection = 0.004;
    if (cme==220) Xsection = 0.092;
    if (cme==240) Xsection = 0.200;
    if (cme==250) Xsection = 0.219;
    if (cme==260) Xsection = 0.214;
    if (cme==280) Xsection = 0.203;
    if (cme==300) Xsection = 0.190;
    if (cme==320) Xsection = 0.176;
    if (cme==240) Xsection = 0.165;
    if (cme==360) Xsection = 0.155;
  }
  
  string frag1, frag2; // initiating the two decay products
  // declaration of the branching fraction values
  if (decayC=="bb") {BR_value= 0.577; frag1="b" ; frag2="b~";}                        
  if (decayC=="tt") {BR_value= 0.0632; frag1="t" ; frag2="t~";}                     
  if (decayC=="mm") {BR_value= 0.00022; frag1="mu-" ; frag2="mu+";}
  if (decayC=="cc") {BR_value= 0.0291; frag1="c" ; frag2="c~";}                                                                                                                                                  
  if (decayC=="gg") {BR_value= 0.0857; frag1="g" ; frag2="g";}                                                                                                                                                   
  if (decayC=="phph") {BR_value= 0.00228; frag1="ph" ; frag2="ph";}                                                                                                  
  if (decayC=="zph") {BR_value= 0.00154; frag1="Z" ; frag2="ph";}                                                                                                                    
  if (decayC=="ww") {BR_value= 0.215; frag1="W" ; frag2="W";}                           
  if (decayC=="zz") {BR_value= 0.0264; frag1="Z" ; frag2="Z";}        

  graph.Feynman_diagram(collider,frag1,frag2);   // calling a class member (method)                                                                                                                                                                               
  PH Higgs_p; // creating an object of the class "PH"
  Higgs_p.set_values(cme,BR_value,Xsection); // applying a method of the class which set the parameters
  cout<<"\n";
  cout<<" The total cross section is: "<<Higgs_p.calculateXsection()<<" [Pb]\n"; // applying a method and print the result
  cout<<" The cross section . "<<decayC<<" braching fraction is: "<<Higgs_p.calculateXsection_BR()<<" [Pb]\n"; // applying another method and print the result
  cout<<" Done \n";
  
  return 0;
} // end main

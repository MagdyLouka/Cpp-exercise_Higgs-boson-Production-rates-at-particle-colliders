//=============================================================================
//     Macro to Browse the Higgs production rate at particle colliders
//                     Magdy Louka - May 2023
//=============================================================================

#include "Produce_Higgs.h" //source code where the class is defined
#include <iostream>
#include <string>
#include <unordered_set>

int main(){ //main
  std::string collider;
  int CME;
  std::string decayC;
  std::unordered_set<int> cme_pp{8,13,14,33,40,60,80,100};
  std::unordered_set<int> cme_ee{200,220,240,250,260,280,300,320,340,360};
  std::unordered_set<std::string> decays{"bb","tt","mm","cc","gg","phph","zph","ww","zz"};
  
  std::cout<<"______________________________________________________________________________ \n";
  std::cout<<"\n";
  std::cout<<" Hello :) \n";
  std::cout<<" You are going to produce the Higgs boson\n";
  std::cout<<"______________________________________________________________________________\n";
  std::cout<<"\n";
  std::cout<<" Choose from the available collideres:- \n";
  std::cout<<"                                     'pp' for proton-proton collider  \n";
  std::cout<<"                                     'ee' for electron-positron collider \n";
  std::cout<<"______________________________________________________________________________\n";
  std::cout<<" The collider is: "; std::cin>>collider;
  std::cout<<"\n";
  if (collider!="pp" && collider!="ee") {std::cout<<" Please enter a valid collider option \n"; exit(0);}
  std::cout<<" Please choose from the available c.m collision energies \n";
  if (collider=="pp"){
    for(auto &value: cme_pp) {std::cout << value << " / ";}
    std::cout<<" The energy is[TeV]: "; std::cin>>CME;
    if(cme_pp.find(CME)==cme_pp.end()) {std::cout << "Collision Energy is not available \n";exit(0);}
  }
  if (collider=="ee"){
    for(auto &value: cme_ee) {std::cout << value << " / ";}
    std::cout<<" Energy is[GeV]: "; std::cin>>CME;
    if(cme_ee.find(CME)==cme_ee.end()) {std::cout << "Collision Energy is not available \n";exit(0);}
  }
  Collision(collider,CME); // plotting the collision sketch
  std::cout<<"________________________________________________________________________________\n";
  std::cout<<" Now let's decay the Higgs boson \n";
  std::cout<<" Please choose from the available final states:- \n";
  std::cout<<"                                     'bb'   for b anti-b quarks   (H --> bb)   \n";                                                   
  std::cout<<"                                     'tt'   for t anti-t quarks   (H --> ττ)   \n";
  std::cout<<"                                     'mm'   for muon anti-muon    (H --> μμ)   \n";
  std::cout<<"                                     'cc'   for c anti-c quarks   (H --> cc)   \n";
  std::cout<<"                                     'gg'   for di-gluons         (H --> gg)   \n";
  std::cout<<"                                     'phph' for di-photons        (H --> γγ)   \n";
  std::cout<<"                                     'zph'  for Z boson+photon    (H --> Zγ)   \n";
  std::cout<<"                                     'ww'   for WW bosons         (H --> WW)   \n";
  std::cout<<"                                     'ZZ'   for ZZ bosons         (H --> ZZ)   \n";
  std::cout<<"________________________________________________________________________________\n";
  std::cout<<" Please enter the channel: "; std::cin>>decayC;
  if(decays.find(decayC)==decays.end()) {std::cout << " Please choose a valid channel \n";exit(0);}
  
  Feynman_diagram(collider, decayC);   // Plotting the Feynman diagram
  
  Higgs* myHiggs = new Higgs(collider, CME, decayC);   // initiating the Higgs class object
  double result1 = myHiggs->Xsection; // accessing the class member through the pointer
  double result2 = myHiggs->Xsection_BR; // accessing  class member through the pointer
  
  std::cout<<" Results:- \n";
  std::cout<<" The total cross-sction is: "<<result1<<" Pb\n";
  std::cout<<" The cross-section * "<<decayC<<" branching ratio is: "<<result2<<" Pb\n";
  std::cout<<" Done. \n";
  return 0;
}//end main

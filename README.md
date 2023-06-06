# Cpp-exercise_Higgs-boson-Production-rates-at-particle-colliders


This exercise can be used to browse the Higgs boson production rates at particle colliders, the collider type, the center of mass collision energy and the final state decay channel are used interactievly by
the user. The cross section and the branching fractions values are taken from references [1,2] consedering certain set of assumptions, for example only the process of gluon-gluon fusion at hadronic collisions is considered which is the dominant leading process, and also consedering a certain set of Parton Distribution functions (PDF). Meanwhile the main goal of the exercise is to apply the basic priciples of OOP using c++ language, creaing two classes in the .h source file and use them in the main macro to be compiled.

Pre-requires:
> gcc compiler

To compile the source (in a Unix shell):
> g++ Produce_Higgs.cc -o Produce_Higgs
 
 or
> gcc Produce_Higgs.cc -o Produce_Higgs

To run the program:
> ./Produce_Higgs

[1] https://twiki.cern.ch/twiki/bin/view/LHCPhysics/HiggsEuropeanStrategy

[2] Higgs Measurement at e + e - Circular Colliders Manqi RUAN CERN, 40-b1-06, Geneva, Switzerland, Institute of High Energy Physics, 19 B Yuquan Road, Beijing, China

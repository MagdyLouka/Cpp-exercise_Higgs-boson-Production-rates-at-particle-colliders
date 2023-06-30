# Cpp-exercise_Higgs-boson-Production-rates-at-particle-colliders
This is an exercise on applying the basic pricniples of the OOP using c++ language, creating a class which encapsulate the data and methods used in calculations and allow the user to use the class through the class constructor which is the public member of the class, which is also used to pass the kinematics arguments. The class and plus two functions for simple graphics are defined in Produce_Higgs.h and the browser macro is Produce_Higgs.cc

The exercise can be used to browse the Higgs boson production rates at particle colliders, the collider type, the center of mass collision energy and the final state decay channel are used interactievly by
the user. The cross section and the branching fractions values are taken from references [1,2] consedering certain set of assumptions, for example only the process of gluon-gluon fusion at hadronic collisions is considered which is the dominant leading process, and also consedering a certain set of Parton Distribution functions (PDF).

Pre-requires:
> gcc compiler

To compile the source (in a Unix shell / Linux):
> g++ Produce_Higgs.cc -o Produce_Higgs

 This command will produce an excutable to be run, to run the program:
> ./Produce_Higgs


[1] https://twiki.cern.ch/twiki/bin/view/LHCPhysics/HiggsEuropeanStrategy

[2] Higgs Measurement at e + e - Circular Colliders Manqi RUAN CERN, 40-b1-06, Geneva, Switzerland, Institute of High Energy Physics, 19 B Yuquan Road, Beijing, China

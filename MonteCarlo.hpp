#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <math.h>

class MonteCarlo{

public:
   MonteCarlo(int badBatch, int numBatch, int numItems, int numSampled, int percentBadBatches, int percentBadItems);
   double probOfMissing();
   void findBadBatch();
   void printSim();

private:
   int badBatch; 
   int numBatch;
   int numItems;
   int numSampled;
   int percentBadBatches;
   int percentBadItems;
   int foundBad;
   float base;
   float P;
   double percentage;
   std::ifstream dataFile;

};

#endif
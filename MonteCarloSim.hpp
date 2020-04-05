#ifndef MONTECARLOSIM_HPP
#define MONTECARLOSIM_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

class MonteCarloSim{

public:
   MonteCarloSim();
   float GetUpper(float sim);
   void GetInterval(float anticipated);
   void determineNext();
   void printResult();
   void simulateNext();

private:
   int numDays;
   int numIntervals;
   float anticipatedMeasurement;
   float simulatedMeasurement;
   std::vector<int> lowerBounds;
   std::vector<int> upperBounds;
   std::vector<int> numMeasurements;
   std::vector<int> simProbability;
   std::vector<int> simDemand;
   std::vector<float> cumulativeProbability;
   std::vector<float> probability;
   std::string unit;
   std::ifstream inputFile;

};

#endif
#include "MonteCarloSim.hpp"

MonteCarloSim::MonteCarloSim()
{
   inputFile.open("readings.txt", std::ios::in);
   inputFile >> numDays;
   inputFile >> numIntervals;
   
   std::string temp;
   
   for(int i = 0; i < numIntervals; i++)
   {
      std::getline(inputFile, temp, '-');
      lowerBounds.push_back(std::stoi(temp));
      std::getline(inputFile, temp, ':');
      upperBounds.push_back(std::stoi(temp));
      std::getline(inputFile, temp);
      numMeasurements.push_back(std::stoi(temp));
   }
   inputFile >> unit;
   
   printResult();
}

float MonteCarloSim::GetUpper(float sim)
{
   for(int i = 0; i < numIntervals; i++)
   {
      if(sim < cumulativeProbability[i])
      {
         return (upperBounds[i] + lowerBounds[i]) / 2.0;
      }
   }
   return -1;
}

void MonteCarloSim::GetInterval(float anticipated)
{
   std::string interval;
   for(int i = 0; i < numIntervals; i++)
   {
      if(anticipated < upperBounds[i])
      {
         interval = std::to_string(lowerBounds[i]) + "-" + std::to_string(upperBounds[i]) + " " + unit;
         break;
      }
   }
   std::cout << interval;
}

void MonteCarloSim::determineNext()
{   
   anticipatedMeasurement = 0.0;
   
   while(probability.size())
   {
      this -> probability.pop_back();
   }
   for(int i = 0; i < numIntervals; i++)
   {
      this -> probability.push_back((numMeasurements[i] / float(numDays)));
   }
      
   for(int i = 0; i < numIntervals; i++)
   {
      anticipatedMeasurement += (probability[i] * (upperBounds[i] + lowerBounds[i]) / 2.0);
   }
   //std::cout << probability[0];
}
   
void MonteCarloSim::printResult()
{
   std::cout << "Simulated Days: " << numDays << std::endl;
   std::cout << "Number of categories: " << numIntervals << std::endl;

   determineNext();
   
   std::cout << "Analytical model: " << anticipatedMeasurement << " Expected value is in the ";
   GetInterval(anticipatedMeasurement);
   std::cout << " range.\n";
   
   simulateNext();
   
   std::cout << "Simulation: " << simulatedMeasurement << " Expected value is in the ";
   GetInterval(simulatedMeasurement);
   std::cout << " range.\n";
}

void MonteCarloSim::simulateNext()
{
   srand(time(NULL));
   float simNumber = 1000.0;
   
   while(cumulativeProbability.size())
   {
      cumulativeProbability.pop_back();
   }   
   //std::cout << "97\n";
   for(int i = 0; i < numIntervals; i++)
   {
      //std::cout << simProbability.size() << std::endl;
      if(i == 0)
      {
         cumulativeProbability.push_back(probability[i]);
      }
      else
      {
         cumulativeProbability.push_back(cumulativeProbability[i - 1] + probability[i]);
      }
   }   
   //std::cout << "108\n";

   simulatedMeasurement = 0.0;
   
   for(int i = 0; i < simNumber; i++)
   {
      int temp = rand() % 100;
      simulatedMeasurement += GetUpper(temp / 100.0);
   }
   simulatedMeasurement /= simNumber;   
}
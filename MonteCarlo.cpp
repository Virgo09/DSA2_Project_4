#include "MonteCarlo.hpp"

MonteCarlo::MonteCarlo(int badBatch, int numBatch, int numItems, int numSampled, 
           int percentBadBatches, int percentBadItems)
{
   this -> badBatch = badBatch; 
   this -> numBatch = numBatch;
   this -> numItems = numItems;
   this -> numSampled = numSampled;
   this -> percentBadBatches = percentBadBatches;
   this -> percentBadItems = percentBadItems;
   findBadBatch();
}

double MonteCarlo::probOfMissing()
{
   this -> base = 1.0 - percentBadItems / 100.0;
   return pow(base, numSampled);
}

void MonteCarlo::findBadBatch()
{
   foundBad = 0;
   std::string status;
   std::cout << "Analyzing Data Sets: \n";
   for(int i = 0; i < numBatch; i++)
   {
      std::string dataFileName = "DataFiles/D" + std::to_string(i) + ".txt";
      dataFile.open(dataFileName, std::ios::in);
      if(!dataFile.is_open())
      {
         std::cout << dataFileName << " did not open in the Monte Carlo algorithm!\n";
      }
      for(int j = 0; j < numSampled; j++)
      {
         std::getline(dataFile, status);
         if(status == "b")
         {
            std::cout << "Batch #" << i << " is bad\n";
            foundBad++;
            break;
         } 
      }
      dataFile.close();
   }
   printSim();
}

void MonteCarlo::printSim()
{
   this -> P = probOfMissing();
   this -> percentage = foundBad/double(percentBadBatches) * 100.0;
   
   std::cout << "Base = " << this -> base << " exponent = " << numSampled << std::endl;
   std::cout << "P = " << this -> P << std::endl;
   std::cout << "Percentage of bad batches detected = " << this -> percentage << "%\n\n";
}

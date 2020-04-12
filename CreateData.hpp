#ifndef CREATEDATA_HPP
#define CREATEDATA_HPP


#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "MonteCarlo.hpp"

class CreateData
{
public:
   CreateData(std::string testFileName);
   void appendBatch();
   void readFile(std::string fileName);
   int GetBadBatch();
   

private:
   std::ofstream dataFile;
   std::ifstream testFile;
   int badBatch = 0;
   int numBatch;
   int numItems;
   int numSampled;
   int percentBadBatches;
   int percentBadItems;
   std::string testFileName;
   

};

#endif

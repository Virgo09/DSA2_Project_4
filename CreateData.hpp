#ifndef CREATEDATA_HPP
#define CREATEDATA_HPP


#include <fstream>
#include <iostream>
#include <string>
#include <io.h>
#include <direct.h>
#include <stdlib.h>
#include <time.h>
#include "MonteCarlo.cpp"

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
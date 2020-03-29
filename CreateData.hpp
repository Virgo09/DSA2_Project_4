#ifndef CREATEDATA_HPP
#define CREATEDATA_HPP


#include <fstream>
#include <iostream>
#include <string>
#include <io.h>
#include <direct.h>

class CreateData
{
public:
   CreateData();
   void appendBatch(char testResult, std::string dataFileName);
   void readFile(std::string fileName, int test);

private:
   std::ofstream dataFile;
   std::ifstream testFile;
   int numBatch;
   int numItems;
   int numSampled;
   int percentBadBatches;
   int percentBadItems;

};

#endif
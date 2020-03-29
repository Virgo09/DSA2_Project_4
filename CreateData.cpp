   #include "CreateData.hpp"
   
CreateData::CreateData()
{
   std::cout << "5\n";
   readFile("t1.txt", 1);
   readFile("t2.txt", 2);
   readFile("t3.txt", 3);
   readFile("t4.txt", 4);
   std::cout << "10\n";
}
   
void CreateData::appendBatch(char testResult, std::string dataFileName)
{
   dataFile.open(dataFileName, std::ios::out | std::ios::app);
   dataFile << testResult + "\n";
}
         
void CreateData::readFile(std::string testFileName, int test)
{
   std::string dataFileName;
   std::string dataFolder = "\\d" + std::to_string(test);
   
   if(_mkdir((dataFolder).c_str()) == -1){
      std::cout << "Error\n";
   }
   std::cout << dataFolder.c_str();
   testFile.open(testFileName);
   testFile >> numBatch;
   testFile >> numItems;
   testFile >> percentBadBatches;
   testFile >> percentBadItems;
   testFile >> numSampled;
   
   for(int i = 0; i < numBatch; i++)
   {
      dataFileName = "\\d" + std::to_string(test) + "\\d" + std::to_string(i) + ".txt";
      
      if(i % numBatch >= numBatch * percentBadBatches / 100)
      {
         for(int j = 0; j < numItems; j++)
         {
            appendBatch('b', dataFileName);
         }
         continue;
      }
      
      for(int j = 0; j < numItems; j++)
      {
         if(j % numItems >= numItems * percentBadItems / 100)
         {
            appendBatch('g', dataFileName);
         }
         else
         {
            appendBatch('b', dataFileName);
         }
      }
   }
}
   #include "CreateData.hpp"
   
CreateData::CreateData(std::string testFileName)
{
   this -> testFileName = testFileName;
   //system("cd DataFiles");
   system("rm -r DataFiles/*");
   //system("cd ..");
   readFile(testFileName);
   MonteCarlo(badBatch, numBatch, numItems, numSampled, percentBadBatches, percentBadItems);
}
   
void CreateData::appendBatch()
{
   int batch, item, bad;
   srand(time(NULL));
   
   for(int i = 0; i < numBatch; i++)
   {  
      bad = 0;
      std::string dataFileName = "DataFiles/D" + std::to_string(i) + ".txt";
      dataFile.open(dataFileName, std::ios::out | std::ios::app);
      batch = numBatch / percentBadBatches; 
      if(!dataFile.is_open())
      {
         std::cout << dataFileName << " failed to open!\n";
      }
      
      if(!(i % batch) && badBatch < percentBadBatches)
      {
         for(int j = 0; j < numItems; j++)
         {
            item = rand() % numItems;
            if(item < (percentBadItems / 100.0) * numItems)
            {
               dataFile << "b\n";
               bad++;
            }
            else
            {
               dataFile << "g\n";
            }
         }
         std::cout << "Create bad batch #" << i << ", bad: " << bad << std::endl;
         badBatch++;
         dataFile.close();
         continue;
      }
      for(int j = 0; j < numItems; j++)
      {
         dataFile << "g\n";
      }
      dataFile.close();
   }      
   std::cout << "Total bad Sets: " << badBatch << std::endl << std::endl;
}
         
void CreateData::readFile(std::string testFileName)
{
   
   testFile.open(testFileName);
   std::cout << testFileName << std::endl;
   if(!testFile.is_open())
   {
      std::cout << testFileName << " file failed to open!\n";
      return;
   }
   testFile >> this -> numBatch;
   testFile >> this -> numItems;
   testFile >> this -> percentBadBatches;
   testFile >> this -> percentBadItems;
   testFile >> this -> numSampled;
   
   
   appendBatch();
   testFile.close();
}

   #include "CreateData.hpp"
   
CreateData::CreateData()
{
   readFile("TestFiles\\t1.txt");
   //readFile("TestFiles\\t2.txt");
   //readFile("TestFiles\\t3.txt");
   readFile("TestFiles\\t4.txt");
   std::cout << "10\n";
}
   
void CreateData::appendBatch()
{
   
   for(int i = 0; i < numBatch; i++)
   {  
      std::string dataFileName = "DataFiles\\D" + std::to_string(i) + ".txt";
      dataFile.open(dataFileName, std::ios::out | std::ios::app);
      if(dataFile.is_open())
      {
         std::cout << i << " ";
      }
      if(i % numBatch >= numBatch * percentBadBatches / 100)
      {
         for(int j = 0; j < numItems; j++)
         {
            dataFile << "b\n";
         }
         dataFile.close();
         continue;
      }
      for(int j = 0; j < numItems; j++)
      {
         if(j % numItems >= numItems * percentBadItems / 100)
         {
            dataFile << "g\n";
         }
         else
         {
            dataFile << "b\n";
         }
      }
      dataFile.close();
   }      
}
         
void CreateData::readFile(std::string testFileName)
{
   
   testFile.open(testFileName);
   if(testFile.is_open())
   {
      std::cout << "The File Opened!\n";
   }
   testFile >> this -> numBatch;
   testFile >> this -> numItems;
   testFile >> this -> percentBadBatches;
   testFile >> this -> percentBadItems;
   testFile >> this -> numSampled;
   
   
   appendBatch();
   testFile.close();
}
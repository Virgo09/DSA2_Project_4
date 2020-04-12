#include "CreateData.hpp"
#include "MonteCarloSim.hpp"

int main()
{
   CreateData("TestFiles/t1.txt");
   CreateData("TestFiles/t2.txt");
   CreateData("TestFiles/t3.txt");
   CreateData("TestFiles/t4.txt");
   
   MonteCarloSim();
}

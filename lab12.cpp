
#include <iostream>
#include "BinaryHeap.cpp"

using namespace std;

int main()
{
  BinaryHeap<int> printQueue;
  int njobs,ijob;
  do{
    cout<<"The priority of print job? ";
    cin>>ijob;
    if(ijob!=-1)
      printQueue.insert(ijob);
  }while(ijob!=-1);
  cout<<"\nThe priority of print jobs: ";
  printQueue.printJobs();
  cout<<"\n\nThe number of jobs the printer will run? ";
  cin>>njobs;
  for(int i=0;i<njobs;i++)
  {
    printQueue.deleteMin();
  }
  cout<<"\nThe priority of remainging print jobs: ";
  printQueue.printJobs();
  return 0;
}
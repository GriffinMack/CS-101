#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;


template<typename myType>
int countFileNumbers(string file) {
  myType test;
  int count = 0;
  ifstream inFile;
  inFile.open(file);

  if(!inFile) {
    cout<<"Cant open input file "<< file<<endl;
    return -1;
  }
  inFile >> test;
  while(!inFile.eof()){
    inFile >> test;
    count++;
  }
  count++;
  inFile.close();
  return count;
}

template<typename myType>
void createVector(string file1,int fileCount,vector<myType> &fileOneVector){
  myType test;
  ifstream inFile;
  inFile.open(file1);
  inFile>>test;
  for(int i=0;i<fileCount;i++) {
    fileOneVector.at(i) = test;
    inFile >> test;
  }
  inFile.close();
}   //creates file vector

template<typename myType>
void findSimularities(vector<myType> fileOneVector,vector<myType> fileTwoVector,vector<myType> &alreadyPrinted){
  unsigned int small = 0;
  unsigned int big = 0;
  int count = 0;
  alreadyPrinted.resize(fileOneVector.size());

  while(small<fileOneVector.size()){
  if(fileOneVector.at(small)>fileTwoVector.at(big)){
    big++;
  }
  if(fileOneVector.at(small)<fileTwoVector.at(big)){
    small++;
  }
  if(fileOneVector.at(small)==fileTwoVector.at(big)){
    alreadyPrinted.at(count)=fileOneVector.at(small);
    count++;
    small++;
  }
  }
}

template<typename myType>
void printVector(vector<myType> fileOneVector,vector<myType> fileTwoVector){
  vector<myType> alreadyPrinted;
  alreadyPrinted.resize(fileOneVector.size());

  if(fileOneVector.size()<=fileTwoVector.size()){
    findSimularities<myType>(fileOneVector,fileTwoVector,alreadyPrinted);
  }
  else{
    findSimularities<myType>(fileTwoVector,fileOneVector,alreadyPrinted);
  }

  for(unsigned int i=0;i<alreadyPrinted.size();i++){
    if(i!=alreadyPrinted.size()){
      if(alreadyPrinted.at(i)!=alreadyPrinted.at(i+1)){
        cout<<alreadyPrinted.at(i)<<endl;
      }
    }
    else cout<<alreadyPrinted.at(i);
  }
}


template<typename myType>
void merge(vector<myType> &array, vector<myType> &L, vector<myType> &R) {
      typename vector<myType>::iterator a = array.begin();
      typename vector<myType>::iterator l = L.begin();
      typename vector<myType>::iterator r = R.begin();

      while(l != L.end() && r != R.end()) {
        if (*l <= *r) {
        *a = *l;
        l++;
        }
        else {
            *a = *r;
            r++;
        }
        a++;
      }
     while (l != L.end()) {
       *a = *l;
       a++;
       l++;
     }
     while (r != R.end()) {
       *a = *r;
       a++;
       r++;
     }
   return;
}

template<typename myType>
void mergeSort(vector<myType> &array) {
    if(array.size() == 1) return;

      unsigned int len = array.size();
      int lo = len/2;

      vector<myType> L(&array[0], &array[lo]);
      vector<myType> R(&array[lo], &array[len]);

      mergeSort<myType>(L);
      mergeSort<myType>(R);
      merge<myType>(array, L, R);
    }














int main(int argc, char** argv) {
  string file1 = argv[2];
  string file2 = argv[3];
  string mode = argv[1];
  int fileOneCount = 0;
  int fileTwoCount = 0;
  vector<int> fileOneVector;
  vector<int> fileTwoVector;
  vector<string> fileOneVectors;
  vector<string> fileTwoVectors;

  if(mode == "i"){
    fileOneCount = countFileNumbers<int>(file1);
      fileOneVector.resize(fileOneCount);
    fileTwoCount = countFileNumbers<int>(file2);
      fileTwoVector.resize(fileTwoCount);

    createVector<int>(file1,fileOneCount,fileOneVector);
    createVector<int>(file2,fileTwoCount,fileTwoVector);

    mergeSort<int>(fileOneVector);
    mergeSort<int>(fileTwoVector);

    printVector<int>(fileOneVector,fileTwoVector);
  }
  else if(mode == "s"){
    fileOneCount = countFileNumbers<string>(file1);
      fileOneVectors.resize(fileOneCount);
    fileTwoCount = countFileNumbers<string>(file2);
      fileTwoVectors.resize(fileTwoCount);

    createVector<string>(file1,fileOneCount,fileOneVectors);
    createVector<string>(file2,fileTwoCount,fileTwoVectors);

    mergeSort<string>(fileOneVectors);
    mergeSort<string>(fileTwoVectors);

    printVector<string>(fileOneVectors,fileTwoVectors);
  }
  else{
    cout<<"invalid command"<<endl;
    return -1;
  }

  return 0;
}

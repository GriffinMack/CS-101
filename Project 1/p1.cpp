#include <iostream>
#include <fstream>
#include <string>
//.cpp files and a makefile. dont send .exe files or test files

using namespace std;





void file1Assign(string& temp, string firstLine, string secondLine){
  string alphabet = temp;
  int flag=0;

for(unsigned int i=0;i<alphabet.length();i++){
  for(unsigned int j=0;j<firstLine.length()&&flag!=1;j++){
    if(alphabet.at(i)==firstLine.at(j)){
      temp.at(i)=secondLine.at(j);
      flag=1;
    }
    else{
      temp.at(i)='-';
    }
  }
flag=0;
}
}


void decodeText(string& output,string temp,string alphabet, int flag) {
  string tempWord;
  for(unsigned int i=0;i<output.length();i++) { //begins to look through given sipher
    if(output.at(i)==' ') { //checks for space in sipher
      output.at(i)=output.at(i);
    }
    else if(temp.find(output.at(i))==string::npos){ //checks if letter is known to temp
      output.at(i)='-';
    }
    else {
      flag=0;
      for(unsigned int j=0;j<temp.length() && flag==0;j++){
        if(output.at(i)==temp.at(j)){     //locates letter in temp
          output.at(i)=alphabet.at(j);    //decodes letter
          flag=1;                         //exits for loop if flagged
        }
      }
    }
  }
}







int main(int argc, char** argv) { //command line file names read in
  ifstream inFS;
  string file1 = argv[1];
  string firstLine;
  string secondLine;
  string file2 = argv[2];
  string givenWord= argv[3];
  string temp;
  string tempWord;
  string output;
  string input;
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  unsigned int flag=0;
  int y=0;
  int x=0;
inFS.open(file1); //opens file 1 from command line
inFS >> firstLine;
inFS >> secondLine;
temp=alphabet; //creats appropriate size for temp
file1Assign(temp, firstLine, secondLine);

inFS.close(); //closes file1


inFS.open(file2); //opens file 2 from command line
getline(inFS, output);

input=output; //makes copies of file2 contents
string copy=input;

decodeText(output, temp, alphabet, flag);



tempWord=givenWord;
for(unsigned int j=0;j<output.length();j++){
  for(unsigned int i=0;output.at(j)!=' ';i++){ //makes tempWord
      tempWord.at(i)=output.at(j);
      j++;
      if(i==givenWord.length()-1)
        break;
      //FIX: IF TEMPWORD SMALLER THEN GIVEN WORD THEN PROBLEMS OCCUR
    }
    unsigned int newFlag=0;
    flag=2;


  for(unsigned int i=0;i<givenWord.length();i++){
    if(tempWord.length()==givenWord.length()){
      if(tempWord.at(i)=='-'){ //checks if new word is all blanks
        newFlag++;

      }
      else if(tempWord.at(i)==givenWord.at(i)){ //checks if a letter matches
        flag=0;
      }
      else { // goes to next word if no letter and not all blanks
        flag=1;
        break;
      }
    }
  }



  if(flag==0 || newFlag==givenWord.length()) {//here if a letter matches
    break;
  }
}





  flag=0;
for(unsigned int i=0;i<givenWord.length();i++){ //fills in blanks found in givenWord
  x=alphabet.find(givenWord.at(i)); //find D in alpha
  y=output.find(tempWord);
  y+=flag; //find
  temp.at(x)=input.at(y);
  flag++;
}

for(unsigned int i=0;i<temp.length();i++){ //fills in final letter of temp if necessary
  if(temp.at(i)=='-'){
    for(unsigned int j=0;j<temp.length();j++){
      if(temp.find(alphabet.at(j))==string::npos){
        temp.at(i)=alphabet.at(j);
      }
    }
  }
}




inFS.close();

decodeText(copy, temp, alphabet, flag);

cout<<copy<<endl<<endl;




return 0;


}

#include <iostream>
#include "ArgumentManager.h"
#include <fstream>
#include <string>
#include <vector>
//#include <filesystem>

using namespace std;

void startperm(string str, int i, int j, vector<int>& placeholder){
  if(j == i) {
    //cout << stoi(str) << endl;
    placeholder.push_back(stoi(str));
  }
  else {
    for(int k = i; k <= j; k++) {
      swap(str[i], str[k]);
      startperm(str, i + 1, j, placeholder);
      swap(str[i], str[k]);
    }
  }
}

int greatestperm(vector<int> placeholder){
  int max = placeholder[0];
  for(int i = 0; i < placeholder.size(); i++) {
    if(placeholder[i] > max) {
      max = placeholder[i];
    }
  }
  return max;
}

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  const string input = am.get("input");
  const string output = am.get("output");

  ifstream inputfile(input);
  ofstream outputfile(output);
  //ifstream inputfile("input1.txt");

  if (!inputfile.is_open()){
      cout << "File not found!" << endl;
      return 0;
   }
  
  bool isEmpty = inputfile.peek() == EOF;
  
  if(isEmpty) {
    return 0;
  }

  string line;
  getline(inputfile, line);

  for(int i = 0; i < line.size(); i++) {
    if (line[i] == ' ') {
      line.erase(line.begin() + i);
      i--;
      //cout << line.length() << endl;
    }
    //cout << line.length() << endl;
  }

  vector<int> placeholder;
  startperm(line, 0, line.size() - 1, placeholder);

  /*for(int i = 0; i < placeholder.size(); i++) {
    cout << placeholder[i] << endl;
  }*/
  
  outputfile << greatestperm(placeholder) << endl;
  //cout << greatestperm(placeholder) << endl;

  inputfile.close();
  outputfile.close();

  return 0;

}
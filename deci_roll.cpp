//
// Created by netpopa on 23/02/26.
//

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;
int rollDice(){
return rand() % 6 + 1;
}

int main(){
 srand(time(0));
 int roll_count=0;
 char user_type;

while(true){
 cout<<"Roll the dice?(y/n): ";
 cin >>user_type;
 user_type=tolower(user_type);

 if(user_type=='y') {
  int num_dice;
  cout<<"How many dice you want to roll: ";
  cin>>num_dice;

  if (num_dice<0) {
   cout<<"You don't have enough dice!"<<endl
   <<"Please try again!"<<endl;
   continue;
  }// if<0
  cout<<"Rolling..."<<endl;
  vector<int> result;

  for(int i=0;i<num_dice;i++) {
   result.push_back(rollDice());
  }
  roll_count++;
  cout<<"You rolled: ";
  int total=0;

  for(int value:result) {
   cout<<value<<" ";
   total+=value;
  }

  cout<<"\nTotal:"<<total<<endl;
  cout<<"Your have rolled the dec:"
  <<roll_count<<" time(s) this session"<<endl;
  cout<<"\nGood luck!,Try again.\n"<<endl;
  cout<<"---------------------"<<endl;
 }//if

 else if (user_type=='n') {
  cout<<" Not rolling.Quit"<<endl;
  cout<<"You rolled the deci"
  <<roll_count<<"time(s) this session:"<<endl;
  break;
 }

 else {
  cout<<"Invalid input"<<endl;

 }

}//while true

 return 0;

}


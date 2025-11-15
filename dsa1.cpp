#include<iostream>
using namespace std;
int main(){

int arr[20]={5,89,69,25,45,14,23,54,87,59,6,4,2,8,7,4,3,6,1,4};
int ocount;
int ecount;
for (int i =0;i<=20;i++)
{
   if (arr[i]%2==0){
    ocount++;
   }
   else{ecount++;}
}
cout<<"odd : "<<ocount<<endl;
cout<<"even : "<<ecount<<endl;

}

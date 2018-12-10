#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

struct Offer{
    string Price;
    string OfferTime;
    string CallTime;
    string SMS;
    string DataSize;
};

Offer* InitArr(const string fileName){
    string line;
    ifstream file;
    Offer* offers;
    int offersCounter=0;
    file.open(fileName);
    while(!file.eof()){
        getline(file, line);
        offersCounter++;
    }
    file.close();
    offers=new Offer[offersCounter];
    file.open(fileName);
    for (int i=0;i<offersCounter;i++) {
        getline(file, line);
        int current, previous = 0;
        current = int(line.find(","));
        offers[i].Price=line.substr(previous,current-previous);
        previous=current+1;
        current = int(line.find(",", previous));
        offers[i].OfferTime=line.substr(previous,current-previous);
        previous=current+1;
        current = int(line.find(",", previous));
        offers[i].CallTime=line.substr(previous,current-previous);
        previous=current+1;
        current = int(line.find(",", previous));
        offers[i].SMS=line.substr(previous,current-previous);
        previous=current+1;
        current = int(line.find("\n", previous));
        offers[i].DataSize=line.substr(previous,current-previous);
    }
    return offers;
}
int main(){
    InitArr("Deals.txt");
}

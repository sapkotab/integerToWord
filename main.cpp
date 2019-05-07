



#include <iostream>
#include <vector>
using namespace std;

vector<string> primeName = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen" };
vector<string> prfx = {"Twen", "Thir", "For", "Fif", "Six", "Seven", "Eigh", "Nine"};

string intToWord(int number ){
    
    assert(number < 999999999);
    string result = "";
    //taking care of 0-12
    if( number < 13 )
        result = primeName[number];
    
    else if( number < 20 )
        //taking care of 13-20
        result = prfx[number-12] + "teen";
    
    else if( number < 100){
        // mtaking care of number finish with "ty"
        if (!(number % 10)){
            result = prfx[(number/10)-2] + "ty";
        }
        else{
            result = prfx[(number/10)-2] + "ty " + intToWord(number%10);
        }
    }
    else if( number < 1000){
        // mtaking care of number finish with "ty"
        if (!(number % 100)){
            result = intToWord(number/100) + " Hundred";
        }
        else{
            result = intToWord(number/100) + " Hundred " + intToWord(number%100);
        }
    }
    else if( number < 1000000){
        // mtaking care of number finish with "ty"
        if (!(number % 1000)){
            result = intToWord(number/1000) + " Thousand";
        }
        else{
            result = intToWord(number/1000) + " Thousand " + intToWord(number%1000);
        }
    }
    else if( number < 1000000000){
        // mtaking care of number finish with "ty"
        if (!(number % 1000000)){
            result = intToWord(number/1000000) + " Million";
        }
        else{
            result = intToWord(number/1000000) + " Million " + intToWord(number % 1000000);
        }
    }
    return result;
}

int main()
{
    int number = 1;
    while (number > 0) {
        cout << "Please enter the Number or negetive number to exit\n";
        cin >> number;
        cout << intToWord(number) << endl;
    }
    return 0;
}

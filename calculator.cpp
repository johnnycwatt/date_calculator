//
//  main.cpp
//  
//
//  Created by Johnny Watt on 20/02/23.
//


#include <iostream>
#include <string>
using namespace std;


//Uses the JDN Method
int JDN(int D,int M,int Y){
    int result =  (1461 * (Y + 4800 + (M - 14) / 12)) / 4 + (367 * (M - 2 - 12 * ((M - 14) / 12))) / 12 - (3 * ((Y + 4900 + (M - 14) / 12) / 100)) / 4 + D - 32075;
    
    return result;
    
}




int getDaysInMonth(int month, int year){
    
    if(month == 2){
        if(year%4 == 0){
            return 29;
        }else{
            return 28;
        }
    }else if(month == 4 || month == 6 || month == 9 || month == 11){
        return 30;
    }else{
        return 31;
    }
    
}


//Check the date the user inputted is valid
bool validDateCheck(int day,int month,int year){
    
    int daysinMonth = getDaysInMonth(month, year);
    
    if(day < daysinMonth && day > 0 && year > 1 && year < 9999 & month < 13 and month > 0){
        return true;
    }else{
        return false;
    }
}


int main() {


    cout << "Please choose a date in the format (day month year): " << endl;
    int dayOne, monthOne, yearOne;
    cin >> dayOne >> monthOne >> yearOne;
    
    bool validDate = validDateCheck(dayOne,monthOne,yearOne);
    
    
    
    if(validDate == false){
        while(validDate == false){
            cout << "You chose an invalid date, please try again: " << endl;
            cin >> dayOne >> monthOne >> yearOne;
            validDate = validDateCheck(dayOne, monthOne, yearOne);
        }
    }
    
    cout << "Please choose a second date in the same format: ";
    int dayTwo, monthTwo, yearTwo;
    cin >> dayTwo >> monthTwo >> yearTwo;
    
    bool validDateTwo = validDateCheck(dayTwo, monthTwo, yearTwo);
    
    if(validDateTwo == false){
        while(validDateTwo == false){
            cout << "You chose an invalid date, please try again: " << endl;
            cin >> dayTwo >> monthTwo >> yearTwo;
            validDateTwo = validDateCheck(dayTwo, monthTwo, yearTwo);
        }
    }
   
    //Arrange the dates from earliest to latest.
    bool firstDateEarlier = true;


    
    if((yearOne > yearTwo) or (yearOne == yearTwo and monthOne > monthTwo) or (yearOne == yearTwo and monthOne == monthTwo and dayOne > dayTwo)){
        firstDateEarlier = false;
    }
    
    
    if(firstDateEarlier == false){
        swap(dayOne, dayTwo);
        swap(monthOne, monthTwo);
        swap(yearOne, yearTwo);
    }
    
    
    int jdn1 = JDN(dayOne, monthOne, yearOne);
    int jdn2 = JDN(dayTwo, monthTwo, yearTwo);
    int differenceInDays = jdn2 - jdn1;
    int differenceInHours = differenceInDays*24;
    int differenceInMinutes = differenceInHours*60;
    int differenceInSeconds = differenceInMinutes*60;
    
    if(differenceInDays == 0){
        cout << "You chose the same days!";
    }else{
        cout << "The difference between the two dates is:\n" << differenceInDays << " days, or\n" << differenceInHours << " hours, or\n" << differenceInMinutes << " minutes, or\n" << differenceInSeconds << " seconds!" << endl;
    }
    return 0;
}


#include <iostream>
#include <string>





void toHumanDate(long int timestamp){
    long int week_day, day, month, year, hour, minute, second, extra_seconds, nbr_days;
    int curr_year, months_list[12] = {31, 28, 31, 30, 31, 30,
                                31, 31, 30, 31, 30, 31};
    std::string date = "";
    nbr_days = timestamp / (24 * 60 * 60);
    extra_seconds = timestamp % (24 * 60 * 60);
    curr_year = 1970;
    bool isLeap;

    week_day = nbr_days % 7;

    while(true){
        if(curr_year % 400 == 0 || (curr_year % 4 == 0 && curr_year % 100 != 0)){
            if(nbr_days < 366){
                isLeap = true;
                break;
            }
            nbr_days -= 366;
        }else{
            if(nbr_days < 365){
                isLeap = false;
                break;
            }
            nbr_days -= 365;
        }
        curr_year++;
    }
    year = curr_year;   
    nbr_days++;
    if(isLeap){
        months_list[1] = 29;
    }
    month = 0;
    while(nbr_days > months_list[month]){
            nbr_days -= months_list[month];
            month++;
    }
    day = nbr_days;
    if(nbr_days)
        month++;
    
    hour = extra_seconds / (60 * 60);
    extra_seconds %= (60 * 60);
    minute = extra_seconds / 60;
    second = extra_seconds % 60;

    switch(week_day){
        case 0: date += "Thursday,"; break;
        case 1: date += "Friday, "; break;
        case 2: date += "Saturday, "; break;
        case 3: date += "Sunday, "; break;
        case 4: date += "Monday, "; break;
        case 5: date += "Tuesday, "; break;
        case 6: date += "Wednesday, "; break;
    }


    switch (month){
        case 1: date += "January "; break;
        case 2: date += "Feruary "; break;
        case 3: date += "March "; break;
        case 4: date += "April "; break;
        case 5: date += "May "; break;
        case 6: date += "June "; break;
        case 7: date += "July "; break;
        case 8: date += "August "; break;
        case 9: date += "September "; break;
        case 10: date += "October "; break;
        case 11: date += "Novermber "; break;
        case 12: date += "December "; break;
    }

    date += std::to_string(day);
    if(day < 10 || day > 20){
        if(day % 10 == 1){
            date += "st, ";
        }else if(day % 10 == 2){
            date += "nd, ";
        }else if(day % 10 == 3){
            date += "rd, ";
        }else{
            date += "th, ";
        }
    }else{
        date += "th, ";
    }

    date += std::to_string(year) + " ";

    if(hour < 10){
        date += '0';
    }
    date += std::to_string(hour) + ":";


    if(minute < 10){
        date += '0';
    } 
    date += std::to_string(minute) + ":";

    
    if(second < 10){
        date += '0';
    }
    date += std::to_string(second);

    std::cout << date;
}


int main(){
    system("cls");
    long int timestamp;
    std::cout << "Enter the Timestamp: ";
    std::cin >> timestamp;
    toHumanDate(timestamp);
}
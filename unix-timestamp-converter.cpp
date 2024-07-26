#include <iostream>


int timestampConverter(long int timestamp){
    long int day, month, year, hours, minutes, seconds, extra_seconds, nbr_days;
    int curr_year;
    int months_list[12] = {31, 28, 31, 30, 31, 30,
                                31, 31, 30, 31, 30, 31};
    nbr_days = timestamp / (24 * 60 * 60);
    extra_seconds = timestamp % (24 * 60 * 60);
    curr_year = 1970;
    bool isLeap;
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
    return curr_year;   
    if(isLeap){
        months_list[1] = 29;
    }
    while(true){
        for(int i = 0; i < 12; i++){
            if(nbr_days <= months_list[i])
                nbr_days -= months_list[i]; 
        }
    }
}


int main(){
    std::cout << timestampConverter(1721776400) << std::endl;
}
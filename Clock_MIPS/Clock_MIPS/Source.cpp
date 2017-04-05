#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

//Kieu luu tru : DD/MM/YYYY


//Truong
int Day(char* TIME) {

}

//Truong
int Month(char* TIME) {

}

//Truong
int Year(char* TIME) {

}

//Truong
//Ten 2 ham khac nhau de mai mot viet MIPS phan biet giua LeapYearC char* voi LeapYearY year
int LeapYearC(char* TIME) {

}

//Truong
int LeapYearY(int year) {

}

void strcpy(char* des, char* res) {
	for (int i = 0; i<= strlen(res); i++)
		des[i] = res[i];
}
//Tai
char* Date(int day, int month, int year, char* TIME) {
	TIME[0] = '0' + day/10;
	TIME[1] = '0' + day%10;
	TIME[2] = '/';
	TIME[3] = '0' + month/10;
	TIME[4] = '0' + month%10;
	TIME[5] = '/';
	TIME[6] = '0' + year/1000;
	TIME[7] = '0' + (year/100)%10;
	TIME[8] = '0' + (year/10)%10;
	TIME[9] = '0' + year%10;
	TIME[10] = '\0';
	return TIME;
}

char* getName(int month) {
	char *res = new char[4];
	switch (month) {
		case 1: 
			res = "Jan";
		case 2: 
			res = "Feb";
		case 3: 
			res = "Mar";
		case 4: 
			res = "Apr";
		case 5: 
			res = "May";
		case 6: 
			res = "Jun";
		case 7: 
			res = "Jul";
		case 8: 
			res = "Aug";
		case 9: 
			res = "Sep";
		case 10: 
			res = "Oct";
		case 11:
			res = "Nov";
		case 12:
			res = "Dec";
		default:
			res = "N/A";			
	}
	return res;
}
//Tai
//type trong file de yeu cau
char* Convert(char* TIME, char type) {
	char* res;
	if (type == 'B' || type == 'C')
		res = new char[strlen(TIME)+2];
	else
		res = new char[strlen(TIME)+1];
	strcpy(res,TIME);
	switch(type) {
	case 'A': {
		char temp1 = res[0];
		char temp2 = res[1];
		res[0] = res[3];
		res[1] = res[4];
		res[3] = temp1;
		res[4] = temp2;
		break;
	}
	case 'B': {
		char* mon = getName(Month(res));
		strcpy(res, Convert(res, 'A'));
		for (int i = 0; i <= strlen(res); i++)
			res[i + 1] = res[i];
		res[0] = mon[0];
		res[1] = mon[1];
		res[2] = mon[2];
		res[3] = ' ';
		res[6] = ',';
		break;
	}
	case 'C': {
		strcpy(res, Convert(res, 'B'));
		char temp1 = res[0];
		char temp2 = res[1];
		res[0] = res[4];
		res[1] = res[5];
		res[4] = res[2];
		res[5] = res[3];
		res[2] = temp1;
		res[3] = temp2;
		break;
	}
	default:
		break;			
	}
	return res;
}

//Truong
int GetTime(char* TIME_1, char* TIME_2) {

}

//Truong
//mau ket qua tra ve xem o file de bai
char* WeekDay(char* TIME) {

}

//Vinh
// Kiem tra nam nhuan xuat ra
int numberOfDaysInMonth(int month, int year) {

}

//Tai
int getStandardDay(char *TIME) {
	int day = Day(TIME);
	int month = Month(TIME);
	int year = Year(TIME);
	int bonus = year / 4 - year / 100 + year / 400;
	int diY = 0;
	for (int i = 1; i < month; i++)
		diY += numberOfDaysInMonth(i, year);
	diY += day;
	return year * 365 + bonus + diY;
}


//ham kiem tra gi do luc nhap Vinh se them sau

//Vinh
void nhap(char *TIME) {

}

//Vinh
void xuat(char *TIME) {

}

int main() {	

	return 0;
}
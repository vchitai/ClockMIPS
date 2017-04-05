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


//Vinh
int numberOfDaysInMonth(int month, int year) {
	switch (month) {
	case 1:
		return 31;
	case 2:
		if (LeapYearY(year))
			return 29;
		else return 28;
	case 3:
		return 31;
	case 4:
		return 30;
	case 5:
		return 31;
	case 6:
		return 30;
	case 7:
		return 31;
	case 8:
		return 31;
	case 9:
		return 30;
	case 10:
		return 31;
	case 11:
		return 30;
	case 12:
		return 31;
	}
	return 0;
}

int ConvertToNumber(char* TIME, int lower_bound, int upper_bound) {
	int m = 0;
	while (TIME[m] != '\0' && TIME[m] == '0') ++m;

	int n = 0;
	while (TIME[n] != '\0') ++n;	
	
	for(int i = m; i < n; ++i)
		if (TIME[i] > '9' || TIME[i] < '0') {
			return -1;
		}

	int number = 0;
	for (int i = m; i < n; ++i)
		number = number * 10 + (TIME[i] - '0');

	if (number < lower_bound)
		return -1;
	if (number > upper_bound)
		return -1;

	return number;
}

//Vinh
int nhap(char *TIME) {
	char* DAY = new char[100];
	char* MONTH = new char[100];
	char* YEAR = new char[100];

	int day = 0;
	int month = 0;
	int year = 0;	

	printf("Nhap ngay DAY: ");
	scanf("%s", DAY);
	printf("Nhap thang MONTH: ");
	scanf("%s", MONTH);
	printf("Nhap nam YEAR: ");
	scanf("%s", YEAR);	

	year = ConvertToNumber(YEAR, 0, 9999);	
	month = ConvertToNumber(MONTH, 1, 12);	

	if (year == -1 || month == -1) {
		return -1;
	}	

	day = ConvertToNumber(DAY, 1, numberOfDaysInMonth(month, year));	

	TIME = Date(day, month, year, TIME);
	return 1;
}

//Vinh
void xuat(char *TIME) {
	printf("%s\n", TIME);
}

int main() {	

	char* TIME = new char[10];
	char* TIME_1 = new char[10];
	char* TIME_2 = new char[10];

	while (true) {
		do {
			int temp = nhap(TIME);
			if (temp == -1) {
				printf("Chuoi khong hop len, moi ban nhap lai.\n");
			}
			else break;
		}
		while (true);

		printf("----------Ban hay chon 1 trong cac thao tac duoi day----------\n");

		printf("1. Xuat chuoi TIME theo dinh dang DD/MM/YYYY.\n");
		printf("2. Chuyen doi chuoi TIME thanh mot trong dinh dang sau:\n");
		printf("     A. MM/DD/YYYY.\n");
		printf("     B. Month DD, YYYY.\n");
		printf("     C. DD Month, YYYY.\n");
		printf("3. Cho biet ngay vua nhap la ngay thu may.\n");
		printf("4. Kiem tra nam trong chuoi TIME co phai la nam nhuan khong.\n");
		printf("5. Cho biet khoang thoi gian giua 2 chuoi TIME_1 va TIME_2.\n");
		printf("6. Cho biet hai nam nhuan gan nhat.\n");
		printf("7. Kiem tra du lieu dau vao.\n");
		printf("8. Nhap vao Ngay Thang Nam moi.\n");
		printf("9. Thoat.\n");
		printf("--------------------------------------------------------------\n");
		
		bool break_while = false;

		while (true) {
			bool break2 = false;
			int id = 0; char ch = ' ';
			int t_year = 0, error1 = 0, error2 = 0;
			printf("Lua chon: "); scanf("%d", id);
			
			switch (id) {
			case 1:
				printf("Ket qua: ");
				xuat(TIME);
				break;

			case 2:
				printf("Nhap kieu dinh dang: ");
				scanf("%c", ch);
				printf("Ket qua: ");
				xuat(Convert(TIME, ch));
				break;

			case 3:
				printf("Ket qua: ");
				printf("%s\n", WeekDay(TIME));
				break;

			case 4:
				t_year = Year(TIME);
				printf("Ket qua: ");
				if (LeapYearY(t_year))
					printf("%d la nam nhuan\n", t_year);
				else
					printf("%d khong la nam nhuan\n", t_year);
				break;

			case 5:
				printf("Nhap chuoi TIME_1\n");
				error1 = nhap(TIME_1);
				printf("Nhap chuoi TIME_2\n");
				error2 = nhap(TIME_2);

				if (error1 == -1 || error2 == -1)
					printf("1 trong 2 chuoi nhap vao sai cu phap\n");
				else {
					printf("Ket qua: ");
					printf("%d", abs(GetTime(TIME_1, TIME_2)));
				}
				break;

			case 6:
				//Ham bo sung
			case 7:				

			case 8:
				break2 = true;
				break;
			case 9:
				break2 = true;
				break_while = true;
				break;
			}
			if (break2) break;
		}

		if (break_while) break;
	}	

	delete TIME;
	delete TIME_1;
	delete TIME_2;

	return 0;
}

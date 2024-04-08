#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define ROWS 4
#define COLS 10
#define MAX_PLANT_NAME_LENGTH 20

//온습도 변수 구조체 선언
struct data
{

    double temperature;
    double humid;
};

int selectPlant(double humid, double temperature);
int errorCheck(double humid, double temperature);
void textcolor(int colorNum); //글자색 지정 함수
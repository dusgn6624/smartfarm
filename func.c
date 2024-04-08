#include "SF.h"


int selectPlant(double humid, double temperature)
{
    char Plant[ROWS][COLS][MAX_PLANT_NAME_LENGTH] = {
            {"다육식물", "다육식물", "다육식물", "대부분의 식물", "대부분의 식물", "대부분의 식물", "대부분의 식물", "대부분의 식물", "대부분의 식물", "대부분의 식물"},
            {"다육식물", "다육식물", "산세베리아", "산세베리아", "테이블 야자", "레몬밤", "레몬밤", "시페루스", "필로텐드론", "칼라테아"},
            {"산세베리아", "산세베리아", "산세베리아", "산세베리아", "산세베리아", "스킨답서스", "스킨답서스", "필로텐드론", "아디안텀", "칼라테아"},
            {"산세베리아", "산세베리아", "산세베리아", "산세베리아", "산세베리아", "테이블 야자", "칼라테아", "칼라테아", "칼라테아", "칼라테아"}
    };

    int row, col;

    // 조건에 따라 행 열 선택
    if (humid >= 0 && humid <= 10) {
        row = 0;
    }
    else if (humid > 10 && humid <= 20) {
        row = 1;
    }
    else if (humid > 20 && humid <= 30) {
        row = 2;
    }
    else if (humid > 30 && humid <= 40) {
        row = 3;
    }
    else if (humid > 40 && humid <= 50) {
        row = 4;
    }
    else if (humid > 50 && humid <= 60) {
        row = 5;
    }
    else if (humid > 60 && humid <= 70) {
        row = 6;
    }
    else if (humid > 70 && humid <= 80) {
        row = 7;
    }
    else if (humid > 80 && humid <= 90) {
        row = 8;
    }
    else if (humid > 90 && humid <= 100) {
        row = 9;
    }
    else {
        printf("잘못된 입력 입니다.");
        return 1;
    }

    if (temperature >= 0 && temperature <= 15) {
        col = 0;
    }
    else if (temperature > 15 && temperature <= 20) {
        col = 1;
    }
    else if (temperature > 20 && temperature <= 25) {
        col = 2;
    }
    else if (temperature > 25 && temperature <= 30) {
        col = 3;
    }
    else {
        printf("잘못된 입력입니다.\n");
        return 1;
    }
    textcolor(10);
    printf("\n입력된 환경에 접학한 식물은\"%s\" 입니다.\n", Plant[col][row]);
    textcolor(15);
    return 0;
}

int errorCheck(double humid, double temperature) {

    int running;
    if (temperature >= 0 && temperature <= 30 && humid >= 0 && humid <= 100) {
        return  1;
    }
    else
    {
        printf("\n온습도 데이터가 잘못되었습니다.\n");
        textcolor(14);
        printf("프로그램을 종료합니다.\n\n");
        textcolor(15);
        printf("------------------------------------<<\n\n");

        return 0;
    }
}

void textcolor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}
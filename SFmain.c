#define _CRT_SECURE_NO_WARNINGS

#include "SF.h"

int main()
{
    struct data Data;

    int start;
    int running = 1; // while문 시작

    enum color
    {
        Black, Blue, Green, SkyBlue, Red, Purple, Yellow, Gray, DarkGray, LightBlue, LightSkyBlue, LightRed, LightPurple, LigheYellow, Whithe
    } color; //글자색 지정 enum선언

    srand((unsigned)time(NULL)); // 난수 

    textcolor(10);
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*                                                                                                           *\n");
    printf("*                                        Smart Farm 식물 추천 프로그램                                      *\n");
    printf("*                                                                                                           *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");

    textcolor(15);

    while (running) {


        printf("현재 온습도에 적합한 추천 식물을 알고 싶으시면 \"1\", 프로그램 종료를 원하시면\"2\", 최근 측정된 온습도를 알고 싶으시면\"3\"을 입력해주세요!\n");
        printf("(단, 유효한 데이터가 아닐 경우 프로그램이 종료 될 수 있으며, 과거 데이터는 \"smartfarmdata.txt\"에 저장됩니다.)\n");
        printf(">> ");
        scanf_s("%d", &start);

        switch (start) {

        case (1):
            Data.temperature = (double)(rand() % 30 + 1);
            Data.humid = (double)(rand() % 100 + 1);
            printf("\n");
            printf("+ 현재 온도: %.2lf\n", Data.temperature);
            printf("+ 현재 습도: %.2lf\n", Data.humid);

            if (!errorCheck(Data.humid, Data.temperature)) {
                break;
            }
            else {
                selectPlant(Data.humid, Data.temperature);
            }
            {
                // 온습도 데이터 txt에 저장
                const char* filename;
                filename = "smartfarmdata.txt";
                FILE* file = fopen(filename, "a");

                if (file == NULL) {
                    printf("파일을 열 수 없습니다.\n");
                    break;
                }

                fprintf(file, "%.2lf %.2lf\n", Data.temperature, Data.humid);
                fclose(file);
                textcolor(8);
                printf(" ->현재 온도와 습도를 txt파일에 저장하였습니다.\n\n\n");
                textcolor(15);
            }

            break;

        case (2):
            textcolor(14);
            printf("\n식물 추천 프로그램을 종료합니다.\n\n");
            textcolor(15);
            printf("===================================<<\n\n");
            return 0;
            break;

        case (3):
        {
            const char* filename;
            filename = "smartfarmdata.txt";
            FILE* file = fopen(filename, "a");

            if (file == NULL) {
                printf("파일을 열 수 없습니다.\n");
                break;
            }

            fclose(file);
            textcolor(13);
            printf("\n......................................................\n");
            printf("\n txt 파일에서 불러온 가장 최근 검색된 온습도 데이터 \n");
            printf("   + 온도: %.2lf\n", Data.temperature);
            printf("   + 습도: %.2lf\n", Data.humid);
            printf(".......................................................\n\n\n");
            textcolor(15);
        }
        break;

        default:
            textcolor(11);
            printf("\n\n잘못된 입력입니다.\n");
            printf("다시 입력해 주세요.\n");
            textcolor(15);
            printf("------------------------------------<<\n\n");
            break;
        }
    }
    return 0;
}

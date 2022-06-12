///////////////////////////////////////////
// 202203667 태유빈 컴퓨터프로그래밍 과제// 
///////////////////////////////////////////



#include <stdio.h>
#pragma warning(disable:4996)
#include <string.h>
#include "region_covid.h" // 1번에서 쓰는 구조체        // 다중 소스 파일 (구조체) 
#include "covid_vaccin.h" // 나라별 백신 접종 현황 함수 // 다중 소스 파일 (배열, 포인터, 포인터 활용) 
#include "selec_region.h" // 1번의 지역 선택 함수       // 다중 소스 파일 (함수) 
#define MAX 100000

//지역별 코로나 확진자 현황, 나라별 코로나 백신 접종 현황, 코로나 백신 예약 확인 프로그램


int main(void) {
    // 현재 각 지역별 코로나 인원 파악 나타나기
    region Seoul = { 1537,3635708,2,4849 };
    region Busan = { 493,1097717,1,2141 };
    region Daegu = { 405,1185727,1,1785 };
    region Incheon = { 392,1076197,1,1396 };
    region Gwangju = { 287,537455,0,558 };
    region Daejeon = { 385,421079,1,452 };
    region Ulsan = { 303,380715,0,341 };
    region Jeju = { 87,236822,1,181 };


    int n; // 사용자 입력 변수
    int m; // 사용자가 선택한 지역을 전달하는변수 
    char name[1000]; // 이름을 입력 받기 위한 배열 
    char buffer[MAX] = { 0, };
    FILE* fp = NULL;           // 파일 입출력 사용 

    fp = fopen("vaccine.txt", "w");
    fprintf(fp, "%s\n", "<백신 명단>");  // 백신 명단 확인 
    //fputs(birth, fp);
    fprintf(fp, "%s\n", "============================");
    fclose(fp);

    while (1) {
        printf("\n=============================================================\n");
        printf("코로나 지역별(대도시)  현황입니다. 무엇을 도와드릴까요?\n");
        printf("1. 각 지역별 현황 파악\n");
        printf("2. 나라별 백신 접종 현황\n");
        printf("3. 백신접종 신청\n");
        printf("4. 백신접종 신청 명단 확인\n");
        printf("5. 종료하기\n");
        printf("=============================================================\n");
        scanf("%d", &n);
        if (n == 1) {
            m = select_region();
            if (m == 1) {
                printf(" 신규확진자는 %d명\n 누적확진자는 %d명\n 당일사망자는 %d명\n 누적사망자는 %d명\n", Seoul.new_covid, Seoul.accumulate_coivd, Seoul.to_dead, Seoul.accumulate_covid_dead);
            }
            else if (m == 2) {
                printf(" 신규확진자는 %d명\n 누적확진자는 %d명\n 당일사망자는 %d명\n 누적사망자는 %d명\n", Busan.new_covid, Busan.accumulate_coivd, Busan.to_dead, Busan.accumulate_covid_dead);
            }
            else if (m == 3) {
                printf(" 신규확진자는 %d명\n 누적확진자는 %d명\n 당일사망자는 %d명\n 누적사망자는 %d명\n", Incheon.new_covid, Incheon.accumulate_coivd, Incheon.to_dead, Incheon.accumulate_covid_dead);
            }
            else if (m == 4) {
                printf(" 신규확진자는 %d명\n 누적확진자는 %d명\n 당일사망자는 %d명\n 누적사망자는 %d명\n", Daegu.new_covid, Daegu.accumulate_coivd, Daegu.to_dead, Daegu.accumulate_covid_dead);
            }
            else if (m == 5) {
                printf(" 신규확진자는 %d명\n 누적확진자는 %d명\n 당일사망자는 %d명\n 누적사망자는 %d명\n", Daejeon.new_covid, Daejeon.accumulate_coivd, Daejeon.to_dead, Daejeon.accumulate_covid_dead);
            }
            else if (m == 6) {
                printf(" 신규확진자는 %d명\n 누적확진자는 %d명\n 당일사망자는 %d명\n 누적사망자는 %d명\n", Ulsan.new_covid, Ulsan.accumulate_coivd, Ulsan.to_dead, Ulsan.accumulate_covid_dead);
            }
            else if (m == 7) {
                printf(" 신규확진자는 %d명\n 누적확진자는 %d명\n 당일사망자는 %d명\n 누적사망자는 %d명\n", Gwangju.new_covid, Gwangju.accumulate_coivd, Gwangju.to_dead, Gwangju.accumulate_covid_dead);
            }
            else if (m == 8) {
                printf(" 신규확진자는 %d명\n 누적확진자는 %d명\n 당일사망자는 %d명\n 누적사망자는 %d명\n", Jeju.new_covid, Jeju.accumulate_coivd, Jeju.to_dead, Jeju.accumulate_covid_dead);
            }
            else{
            	printf("잘못입력하였습니다.");
			}

        }
        else if (n == 2) {
            covid_vaccin();
        }
        else if (n == 3) {  // 백신 접종 신청 입력 받기 
            printf("=====================================\n");
            printf("== 백신 접종 신청입니다.           ==\n");
            printf("== 이름을 입력해주세요.            ==\n");
            printf("=====================================\n");
            scanf("%s", name);
            fp = fopen("vaccine.txt", "a");
            fprintf(fp, "%s\n", name);
            //fputs(birth, fp);
            fprintf(fp, "%s\n", "==============================");
            fclose(fp);

        }
        else if (n == 4) {
            printf("백신 신청자 명단입니다.\n");
            if (fp == NULL) {
                printf("파일에 명단이 존재하지 않습니다.\n");
            }
            else {
                fp = fopen("vaccine.txt", "r");
                fread(buffer, 1, MAX, fp);
                printf("%s", buffer);
            }

        }
        else if (n == 5) {
            break;
        }
        else {
            printf("잘못입력하였습니다. 1~4번 사이의 번호를 입력해주세요 \n");
        }
    }
    //   }
    return 0;
}

///////////////////////////////////////////
// 202203667 ������ ��ǻ�����α׷��� ����// 
///////////////////////////////////////////



#include <stdio.h>
#pragma warning(disable:4996)
#include <string.h>
#include "region_covid.h" // 1������ ���� ����ü        // ���� �ҽ� ���� (����ü) 
#include "covid_vaccin.h" // ���� ��� ���� ��Ȳ �Լ� // ���� �ҽ� ���� (�迭, ������, ������ Ȱ��) 
#include "selec_region.h" // 1���� ���� ���� �Լ�       // ���� �ҽ� ���� (�Լ�) 
#define MAX 100000

//������ �ڷγ� Ȯ���� ��Ȳ, ���� �ڷγ� ��� ���� ��Ȳ, �ڷγ� ��� ���� Ȯ�� ���α׷�


int main(void) {
    // ���� �� ������ �ڷγ� �ο� �ľ� ��Ÿ����
    region Seoul = { 1537,3635708,2,4849 };
    region Busan = { 493,1097717,1,2141 };
    region Daegu = { 405,1185727,1,1785 };
    region Incheon = { 392,1076197,1,1396 };
    region Gwangju = { 287,537455,0,558 };
    region Daejeon = { 385,421079,1,452 };
    region Ulsan = { 303,380715,0,341 };
    region Jeju = { 87,236822,1,181 };


    int n; // ����� �Է� ����
    int m; // ����ڰ� ������ ������ �����ϴº��� 
    char name[1000]; // �̸��� �Է� �ޱ� ���� �迭 
    char buffer[MAX] = { 0, };
    FILE* fp = NULL;           // ���� ����� ��� 

    fp = fopen("vaccine.txt", "w");
    fprintf(fp, "%s\n", "<��� ���>");  // ��� ��� Ȯ�� 
    //fputs(birth, fp);
    fprintf(fp, "%s\n", "============================");
    fclose(fp);

    while (1) {
        printf("\n=============================================================\n");
        printf("�ڷγ� ������(�뵵��)  ��Ȳ�Դϴ�. ������ ���͵帱���?\n");
        printf("1. �� ������ ��Ȳ �ľ�\n");
        printf("2. ���� ��� ���� ��Ȳ\n");
        printf("3. ������� ��û\n");
        printf("4. ������� ��û ��� Ȯ��\n");
        printf("5. �����ϱ�\n");
        printf("=============================================================\n");
        scanf("%d", &n);
        if (n == 1) {
            m = select_region();
            if (m == 1) {
                printf(" �ű�Ȯ���ڴ� %d��\n ����Ȯ���ڴ� %d��\n ���ϻ���ڴ� %d��\n ��������ڴ� %d��\n", Seoul.new_covid, Seoul.accumulate_coivd, Seoul.to_dead, Seoul.accumulate_covid_dead);
            }
            else if (m == 2) {
                printf(" �ű�Ȯ���ڴ� %d��\n ����Ȯ���ڴ� %d��\n ���ϻ���ڴ� %d��\n ��������ڴ� %d��\n", Busan.new_covid, Busan.accumulate_coivd, Busan.to_dead, Busan.accumulate_covid_dead);
            }
            else if (m == 3) {
                printf(" �ű�Ȯ���ڴ� %d��\n ����Ȯ���ڴ� %d��\n ���ϻ���ڴ� %d��\n ��������ڴ� %d��\n", Incheon.new_covid, Incheon.accumulate_coivd, Incheon.to_dead, Incheon.accumulate_covid_dead);
            }
            else if (m == 4) {
                printf(" �ű�Ȯ���ڴ� %d��\n ����Ȯ���ڴ� %d��\n ���ϻ���ڴ� %d��\n ��������ڴ� %d��\n", Daegu.new_covid, Daegu.accumulate_coivd, Daegu.to_dead, Daegu.accumulate_covid_dead);
            }
            else if (m == 5) {
                printf(" �ű�Ȯ���ڴ� %d��\n ����Ȯ���ڴ� %d��\n ���ϻ���ڴ� %d��\n ��������ڴ� %d��\n", Daejeon.new_covid, Daejeon.accumulate_coivd, Daejeon.to_dead, Daejeon.accumulate_covid_dead);
            }
            else if (m == 6) {
                printf(" �ű�Ȯ���ڴ� %d��\n ����Ȯ���ڴ� %d��\n ���ϻ���ڴ� %d��\n ��������ڴ� %d��\n", Ulsan.new_covid, Ulsan.accumulate_coivd, Ulsan.to_dead, Ulsan.accumulate_covid_dead);
            }
            else if (m == 7) {
                printf(" �ű�Ȯ���ڴ� %d��\n ����Ȯ���ڴ� %d��\n ���ϻ���ڴ� %d��\n ��������ڴ� %d��\n", Gwangju.new_covid, Gwangju.accumulate_coivd, Gwangju.to_dead, Gwangju.accumulate_covid_dead);
            }
            else if (m == 8) {
                printf(" �ű�Ȯ���ڴ� %d��\n ����Ȯ���ڴ� %d��\n ���ϻ���ڴ� %d��\n ��������ڴ� %d��\n", Jeju.new_covid, Jeju.accumulate_coivd, Jeju.to_dead, Jeju.accumulate_covid_dead);
            }
            else{
            	printf("�߸��Է��Ͽ����ϴ�.");
			}

        }
        else if (n == 2) {
            covid_vaccin();
        }
        else if (n == 3) {  // ��� ���� ��û �Է� �ޱ� 
            printf("=====================================\n");
            printf("== ��� ���� ��û�Դϴ�.           ==\n");
            printf("== �̸��� �Է����ּ���.            ==\n");
            printf("=====================================\n");
            scanf("%s", name);
            fp = fopen("vaccine.txt", "a");
            fprintf(fp, "%s\n", name);
            //fputs(birth, fp);
            fprintf(fp, "%s\n", "==============================");
            fclose(fp);

        }
        else if (n == 4) {
            printf("��� ��û�� ����Դϴ�.\n");
            if (fp == NULL) {
                printf("���Ͽ� ����� �������� �ʽ��ϴ�.\n");
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
            printf("�߸��Է��Ͽ����ϴ�. 1~4�� ������ ��ȣ�� �Է����ּ��� \n");
        }
    }
    //   }
    return 0;
}

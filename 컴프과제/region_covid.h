#pragma once

// 구조체 

typedef struct region_covid {  // 각 지역별 신규확진자, 누적 확진자, 신규 사망자, 당일  사망자 인원을 저장하는 구조체  
    int new_covid;  //신규 확진자  
    int accumulate_coivd; // 누적 확진자  
    int to_dead;  // 당일 사망자  
    int accumulate_covid_dead; // 누적 사망자  
}region;

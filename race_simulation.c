
#include <stdio.h>

float calculateAccelerationTime(float a, float ts);
float calculateDistanceAccelerating(float a, float t);
float calculateTimeTopSpeed(float ts, float r_distance);
int findWinner(int length, float a_ath1, float ts_ath1, float a_ath2, float ts_ath2);

int main() {
    
    int length, result;
    float a_ath1, ts_ath1, a_ath2, ts_ath2;
   
    printf("Enter the length of the race :\n");
    scanf("%d", &length);
    
    printf("Enter the acceleration of athlete 1 :\n");
    scanf("%f", &a_ath1);
    
    printf("Enter the top speed of athlete 1 :\n");
    scanf("%f", &ts_ath1);
    
    printf("Enter the acceleration of athlete 2 :\n");
    scanf("%f", &a_ath2);
    
    printf("Enter the top speed of athlete 2 :\n");
    scanf("%f", &ts_ath2);
    
    result = findWinner(length, a_ath1,  ts_ath1,  a_ath2,  ts_ath2);
    
    if(result == 1)
        printf("Winner is athlete 1 \n");
    
    else if(result == 2)
        printf("Winner is athlete 2 \n");
    
    else printf("Both athletes finish the race at the same time \n");
    
    
    return 0;
}

float calculateAccelerationTime(float a, float ts){
    
    float time = ts/a;
    
    return time;
    
}

float calculateDistanceAccelerating(float a, float t){
    
    float distance = 1/2 * a * t * t;
    
    return distance;
}

float calculateTimeTopSpeed(float ts, float r_distance){
    
    float r_time = ts/r_distance;
    
    return r_time ;
}

int findWinner(int length, float a_ath1, float ts_ath1, float a_ath2, float ts_ath2){
    
    float a_time1 = calculateAccelerationTime(a_ath1, ts_ath1);
    float distance1 = calculateDistanceAccelerating(a_ath1, a_time1);
    float ts_time1 = calculateTimeTopSpeed(ts_ath1, length - distance1);
    
    float a_time2 = calculateAccelerationTime(a_ath2, ts_ath2);
    float distance2 = calculateDistanceAccelerating(a_ath2, a_time2);
    float ts_time2 = calculateTimeTopSpeed(ts_ath1, length - distance2);
    
    float total_time1 = a_time1 + ts_time1;
    float total_time2 = a_time2 + ts_time2;
    
    if (total_time1 < total_time2) return 1;
    else if (total_time1 > total_time2)  return 2;
    else return 0;
    
}


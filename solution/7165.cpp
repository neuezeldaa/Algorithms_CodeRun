#include <iostream>
#include <cmath>

bool can_stand(long long res, long long n, long long m){
    long long white = (res*res+1)/ 2;
    long long black = res * res / 2;
    return white <= n && black <= m;
}

int solution(int n, int m) {
    long long low = 0;
    long long high = 2e9;
    long long result = 0;

    while(low <= high){
        long long mid = (low + high)/2;
        if(can_stand(mid, n, m) || can_stand(mid, m, n)){
            result = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return result;
}

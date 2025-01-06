#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int num = n < m ? n : m;
    
    int gcd_n = n;
    int gcd_m = m;
    int gcd = 1;
    int flag = 1;
    
    while(flag){
        for(int i = 2 ; i <= num; i++){
            if(gcd_n % i == 0 && gcd_m % i == 0){
                gcd *= i;
                gcd_n /= i;
                gcd_m /= i;
                num /= i;
                break;
            }
            if(i == num)
                flag = 0;
        }
        if(gcd_n == 1 || gcd_m == 1)
            flag = 0;
    }
    
    int lcm = gcd * gcd_n * gcd_m;
    
    answer.push_back(gcd);
    answer.push_back(lcm);    
    
    return answer;
}
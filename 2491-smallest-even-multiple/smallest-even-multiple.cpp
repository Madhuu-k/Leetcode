class Solution {
public:
    int smallestEvenMultiple(int n) {
        int num = 1;
        while(true){
            if((num % 2 == 0) && (num % n == 0)) break;
            num++;
        }
        return num;
    }
};
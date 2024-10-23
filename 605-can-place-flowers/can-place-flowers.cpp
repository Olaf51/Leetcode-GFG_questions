class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
         if(n==0)return true;
        int x = flowerbed.size();
    //     int cnt=0;
    //     for(int i=1;i<x-1;i++){
    //         if(flowerbed[i-1]==0 && flowerbed[i+1] == 0 && flowerbed[i]== 0){
    //             flowerbed[i] = 1;
    //         cnt++;
    //         }
    //     }
       
    //    return (cnt==n)? true: false;
       int i=0;
       while(i<x && n>0){
        if(flowerbed[i] == 1)i+=2;
        else if(i == x-1 || flowerbed[i+1] == 0){
            i+=2;
            n--;
        }
        else{
             i+=3;
        }
       
       }
        return n<=0;
        
    }
};
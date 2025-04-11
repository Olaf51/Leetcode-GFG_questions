class Solution {
public:
    bool isSymmetric(int x, int cnt)
    {
        int num=x, r1= 0, sum1= 0, r2= 0, sum2= 0; 
        while(num)
        {
            r1=num%10;
            sum1+= r1;
            num=num/10;
        }
        cnt= cnt/2;
        while(x && cnt)
        {
            r2=x%10;
            sum2+= r2;
            x=x/10;
            cnt--;
        }
        if(sum1== sum2*2) return true;
        return false;
    }
    int countSymmetricIntegers(int low, int high) {
       int ans=0;
       for(int i= low; i<=high; i++)
       {
        int num= i, cnt=0;
        while(num!=0)
        {
            cnt++;
            num= num/10;
        }
        if(cnt%2) continue;
        else
        {
            if(isSymmetric(i, cnt)) ans++;
        }
       } 
       return ans;
    }
};
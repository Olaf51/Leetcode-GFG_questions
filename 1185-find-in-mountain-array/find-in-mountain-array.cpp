/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
   int peak( MountainArray &arr, int n){
       int s=0, e=n-1;
       int res=-1;
       while(s<e){
           int mid = s + (e-s)/2;
           if(arr.get(mid+1)>arr.get(mid)){
               res = mid+1;
               s = mid+1;
           }
           else
           e = mid;
       }
       return res;
   }
   int bs(int s, int e,  MountainArray &arr, int target,int flag){
       int res = -1;
       while(s<=e){
           int mid = s + (e-s)/2;
           if(arr.get(mid)==target){
                res = mid;
                if(flag)
                s = mid+1;
                else
                e = mid-1;
           }
           else if(arr.get(mid)<target){
               if(flag)
               e = mid-1;
               else
               s = mid+1;
           }
           else{
               if(flag)
               s = mid+1;
               else
               e = mid-1;
           }
       }
       return res;
   }

    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        if(n<3)return -1;
        int p = peak(arr,n);
        int l = bs(0,p,arr,target,0);
        if(l!=-1)
        return l;
        return bs(p,n-1,arr,target,1);
        
    }
};
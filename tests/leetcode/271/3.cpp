/* https://leetcode-cn.com/problems/watering-plants-ii/ */
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int num1=0,num2=0;
        int cap1=capacityA,cap2=capacityB;
        int n = plants.size();
        for(int i=0;i<(n+1)/2;i++)
        {
            int idx1=i;
            int idx2=n-1-i;
            if(idx1==idx2)
            {
                if(max(cap1,cap2)<plants[idx1]) num1++;
            }
            else 
            {
                if(cap1>=plants[idx1]) cap1-=plants[idx1];
                else 
                {
                    cap1=capacityA;
                    num1++;
                    cap1-=plants[idx1];
                }
                if(cap2>=plants[idx2]) cap2-=plants[idx2];
                else 
                {
                    cap2=capacityB;
                    num2++;
                    cap2-=plants[idx2];
                }
            }
        }
        return num1+num2;
    }
};
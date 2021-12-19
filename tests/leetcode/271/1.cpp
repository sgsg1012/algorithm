/* https://leetcode-cn.com/problems/rings-and-rods/ */
class Solution {
public:
    int countPoints(string rings) {
        vector<map<char,int>> vs(10);
        char c=' ';
        for(int i=0;i<rings.size();i++)
        {
            if(i%2==0) c=rings[i];
            else 
            {
                int x=rings[i]-'0';
                vs[x][c]++;
            }
        }
        int num=0;
        for(int i=0;i<10;i++)
        {
            if(vs[i]['R']>0&&vs[i]['B']>0&&vs[i]['G']>0) num++;
        }
        return num;
    }
};

class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return bool布尔型
     */
    bool solve(int x) {
        // write code here
        int t = x%10;
        if(t==2||t==3||t==7||t==8)
        {
            return false;
        }
        else 
        {
            int MAX = 2147483000;
            for(int i=0;i<=MAX;i+=1000)
            {
                int t = (int)sqrt(x+i);
                if(t*t==x+i)
                    return true;
            }
        }
        return false;
    }
};

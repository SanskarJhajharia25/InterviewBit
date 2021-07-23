/*
https://leetcode.com/problems/k-closest-points-to-origin/submissions/



*/



priority_queue<pair<int,pair<int,int>>>maxh;
        
        for(int i=0;i<arr.size();i++)
        {
            int x=arr[i][0]*arr[i][0];
            int y=arr[i][1]*arr[i][1];
            int sum=x+y;
            
            maxh.push({sum,{arr[i][0],arr[i][1]}});
            
            if(maxh.size() > k){
                maxh.pop();
            }
        }
        
       
        vector<vector<int>>ans;
        
        while(!maxh.empty()){
            
            pair<int,int>pq=maxh.top().second;
            vector<int>temp;
            temp.push_back (pq.first);
            temp.push_back(pq.second);
            
            ans.push_back(temp);
            maxh.pop();
        }
        
        return ans;

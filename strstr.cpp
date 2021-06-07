// Implement strStr().
//strstr - locate a substring ( needle ) in a string ( haystack ). 
//Try not to use standard library string functions for this question.
//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
// NOTE: Good clarification questions:
//What should be the return value if the needle is empty?
//What if both haystack and needle are empty?
//For the purpose of this problem, assume that the return value should be -1 in both cases.*/

int Solution::strStr(const string A, const string B) {
    if(B.size()==0 || A.size()==0 ||A.size()<B.size())
        return -1;
    int s=B.size();
 //   cout<<s<<endl;
    for(int i=0;i<A.size()-s+1;i++)
    {
        string s1=A.substr(i,s);
   //         cout<<i<<"  "<<s1<<endl;
        if(s1==B)
        {
        
            return i;
        }
        //    return i;
    }
    return -1;
}

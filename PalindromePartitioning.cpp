/*
Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
 Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,
["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")
*/

bool palindrome(string s)
{
  if(s.length()==1)
     return true;
  int i=0,j=s.length()-1;
  while(i<j)
  {
    if(s[i]!=s[j])
      return false;
    i++;
    j--;
  }
  return true;
}

void solve(vector<vector<string>>& v,string A,vector<string>& op)
{
  if(A.length()==0)
  {
    v.push_back(op);
    return;
  }
  for(int i=0;i<A.length();i++)
  {
    string pref=A.substr(0,i+1);
    string left=A.substr(i+1);
    if(palindrome(pref))
    {
      op.push_back(pref);
      solve(v,left,op);
      op.pop_back();
    }
  }
}
vector<vector<string> > Solution::partition(string A) 
{
    vector<vector<string> >ans;
    vector<string> op;
    solve(ans,A,op);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

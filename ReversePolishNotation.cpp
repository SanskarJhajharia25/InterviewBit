/* 
https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.
*/

class Solution 
{
public:
        bool isOperand(string x)
        {
            if(x=="+"||x=="-"||x=="*"||x=="/")
            {
                return true;
            }
            return false;
        }
    
        int operation(string op, int x, int y)
        {
            if(op=="+")
            {
                return x+y;
            }
            else if(op=="-")
            {
                return x-y;
            }
            else if(op=="*")
            {
                return x*y;
            }
            else if(op=="/")
            {
                return x/y;
            }
            return -1;
        }
    
        int evalRPN(vector<string>& a)
        {
            stack<int> stk;
            int n=a.size();
            int x=0,y=0,result=0;
            for(int i=0;i<n;i++)
            {
                if(!isOperand(a[i]))
                {
                    stk.push(stoi(a[i]));
                }
                else
                {
                    y=stk.top();
                    stk.pop();
                    x=stk.top();
                    stk.pop();
                    result=operation(a[i],x,y);
                    stk.push(result);
                }
            }
            int sol=stk.top();
            stk.pop();
            return sol;
        }
};

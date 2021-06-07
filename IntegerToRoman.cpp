/* Take a Number and gets its Iteger Roman value. The number is less that 4000 for sure*/
string Solution::intToRoman(int A) {
    string s = "";
    int m = A / 1000;
    for(int i = 1;i<=m;i++)
        s += "M";
    A %= 1000;
    if(A >= 900)
    {
        s += "CM";
        A -= 900;
    }
    if(A >= 500)
    {
        s += "D";
        A -= 500;
    }
    if(A >= 400)
    {
        s += "CD";
        A -= 400;
    }
    if(A >= 100)
    {
        m = A/100;
        for(int i=1;i<=m;i++)
            s += "C";
        A %= 100;
    }
    if(A >= 90)
    {
        s += "XC";
        A -= 90;
    }
    if(A >= 50)
    {
        s += "L";
        A -= 50;
    }
    if(A >= 40)
    {
        s += "XL";
        A -= 40;
    }
    if(A >= 10)
    {
        m = A/10;
        for(int i=1;i<=m;i++)
            s += "X";
        A %= 10;
    }
    if(A == 9)
    {
        s += "IX";
        A -= 9;
    }
if(A >= 5)
{    
    s += "V";
    A -= 5;
}
if(A == 4)
s += "IV";
else if(A > 0)
{
    for(int i=1;i<=A;i++)
    s += "I";
}
return s;
}


/*

class Solution {
public:
    string intToRoman(int num) {
        // 1000, 2000, 3000
        string M[] = {"", "M", "MM", "MMM"};
        // 100, 200, 300, .. 900
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        // 10, 20, ... 90
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        // 1, 2, ... 9
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
    
    */

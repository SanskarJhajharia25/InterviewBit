/*
https://leetcode.com/problems/validate-ip-address/submissions/

Given a string IP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.

A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses but "192.168.01.1", while "192.168.1.00" and "192.168@1.1" are invalid IPv4 addresses.

A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

1 <= xi.length <= 4
xi is a hexadecimal string which may contain digits, lower-case English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
Leading zeros are allowed in xi.
*/

class Solution {
public:
    bool checkIp4Octate(string octate)
    {
        if(octate.length() == 0  || octate.length() > 3 ||(octate.length() > 1 && octate[0] == '0'))
            return false;
        
        for(auto ch : octate)
        {
            if(!isdigit(ch))
                return false;            
        }
        
        if(stoi(octate) > 255)
            return false;
        
        return true;
    }
    
    bool checkIp6Octate(string octate)
    {
        if(octate.length() == 0 || octate.length() > 4)
            return false;
        
        for(auto ch : octate)
        {            
            if(!isdigit(ch) && !(ch >= 'a' && ch <= 'f') && !(ch >= 'A' && ch <= 'F') )
                return false;
        }
        
        return true;
    }
    
   
    vector<string> split(string str, char splitChar)
    {
        istringstream iss(str);
        string temp;
        vector<string> res;
        
        while(getline(iss, temp, splitChar))
			res.push_back(temp);
			
        return res;
    }
    
    string validIPAddress(string IP) 
    {
        
        if(IP.find('.') != string::npos) // v4
        {            
            if(count(IP.begin(), IP.end(), '.')  != 3) // count STL API
                return "Neither";
            
            vector<string> parts = split(IP, '.');
            
            if(parts.size() != 4 )
                return "Neither";
            
            for(auto ch : parts)
            {
                if(!checkIp4Octate(ch))
                    return "Neither";                
            }
            
            return "IPv4";
        }
        else if(IP.find(':') != string::npos) // v6
        {            
            if(count(IP.begin(), IP.end(), ':')  != 7) // count STL API
                return "Neither";
            
            vector<string> parts = split(IP, ':');
            
            if(parts.size() != 8 )
                return "Neither";
            
            for(auto ch : parts)
            {
                if(!checkIp6Octate(ch))
                    return "Neither";                
            }
            return "IPv6";
        }
            
        
        return "Neither";
    }
};

#include <iostream>
#include <string>

bool isSubstring(std::string s1, std::string s2)
{
    // or s1.find(s2) != nullptr
    if (s1.find(s2) != std::string::npos) return true;
    else return false;
}

bool isRotation(std::string s1, std::string s2)
{
    if (s1.size() != s2.size() || s1.size() <= 0)
        return false;
    return isSubstring(s1 + s1, s2);
}

int main()
{
    std::string s1 = "apple";
    std::string s2 = "leapp";

    isRotation(s1, s2)? 
    std::cout << s1 << " is a rotation of " << s2 << std::endl :
    std::cout << s1 << " is NOT a rotation of " << s2 << std::endl;


    return 0;
}
#include <iostream>
//#include <string>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        while (num >= 10)
        {
            int sum = 0;
            while (num > 0)
            {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

int main()
{
    Solution s1;
    cout << s1.addDigits(38) << endl;
    system("pause");
    return 0;
}
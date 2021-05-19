#include <iostream>
#include <vector>
using namespace std;
int N = 0;
vector<int> numbers;
vector<char> opers;
int MAXNUM = -1000000001;
int MINNUM = 1000000001;
int DoOper(char oper, int left, int right)
{
    if (oper == '+') return left + right;
    if (oper == '-') return left - right;
    if (oper == '*') return left * right;
    if (oper == '/')
    {
        if (left < 0)
        {
            left = abs(left);
            return -1 * (left / right);
        }        
        return left / right;
    }
}

void Solution(vector<bool> selectedOpers, int selectedIndex, int left, int numberIndex)
{
    selectedOpers[selectedIndex] = true;
    left = DoOper(opers[selectedIndex], left, numbers[numberIndex]);

    if (numberIndex == numbers.size() - 1)
    {
        MAXNUM = max(MAXNUM, left);
        MINNUM = min(MINNUM, left);
        return;
    }

    for (int i = 0; i < selectedOpers.size(); ++i)
    {
        if (selectedOpers[i] == false)
        {
            Solution(selectedOpers, i, left, numberIndex + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int num = 0;
        cin >> num;
        numbers.push_back(num);
    }

    int plus = 0, minus = 0, multiply = 0, divide = 0;
    cin >> plus >> minus >> multiply >> divide;

    for (int i = 0; i < plus; ++i) opers.push_back('+');
    for (int i = 0; i < minus; ++i) opers.push_back('-');
    for (int i = 0; i < multiply; ++i) opers.push_back('*');
    for (int i = 0; i < divide; ++i) opers.push_back('/');

    for (int i = 0; i < opers.size(); ++i)
    {
        vector<bool> selectedOpers(opers.size());        
        Solution(selectedOpers, i, numbers[0], 1);
    }

    cout << MAXNUM << "\n";
    cout << MINNUM;
}
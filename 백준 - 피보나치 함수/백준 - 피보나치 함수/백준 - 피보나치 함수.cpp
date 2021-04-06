#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct ZEROONE
{
    int zero = 0;
    int one = 0;
};
map<int, ZEROONE> cache;
ZEROONE fibonacci(int n) 
{
    ZEROONE zeroone;
    if (n == 0) {
        zeroone.zero++;
        return zeroone;
    }
    else if (n == 1) {
        zeroone.one++;
        return zeroone;
    }
    else {        
        if (cache.find(n) != cache.end())
            return cache[n];

        ZEROONE fibo1 = fibonacci(n - 1);
        ZEROONE fibo2 = fibonacci(n - 2);
        cache[n].one = fibo1.one + fibo2.one;
        cache[n].zero = fibo1.zero + fibo2.zero;
    }   

    return cache[n];
}

void solution(int N)
{
    if (N == 1)
        cache[1].one = 1;
    else if (N == 0)
        cache[0].zero = 1;
    else
        fibonacci(N);
}

int main()
{
    int T = 0;
    vector<int> Ns;
    cin >> T;
    Ns.resize(T);
    for (int i = 0; i < Ns.size(); i++)
    {
        cin >> Ns[i];
        int zero =0, one = 0;
        solution(Ns[i]);
        cout << cache[Ns[i]].zero << " " << cache[Ns[i]].one << endl;
        cache.clear();
    }
}
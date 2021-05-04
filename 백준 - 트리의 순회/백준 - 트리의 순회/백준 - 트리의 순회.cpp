#include <iostream>
#include <vector>
using namespace std;
int N = 0;
vector<int> inorder;
vector<int> postorder;
void preorder(int in_start, int in_end, int post_start, int post_end)
{
    if (post_end - post_start >= 0)
    {
        cout << postorder[post_end] << " ";
        for (int i = in_start; i <= in_end; ++i)
        {
            if (inorder[i] == postorder[post_end])
            {
                preorder(in_start, i - 1, post_start, post_start + (i - 1 - in_start));
                preorder(i + 1, in_end, post_start + (i - in_start), post_end - 1);
                break;
            }
        }
    }    
}
int main()
{
    ios::sync_with_stdio(false);    
    cin >> N;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < N; ++j)
        {
            int node = 0;
            cin >> node;
            if (i == 0) inorder.push_back(node);
            else postorder.push_back(node);
        }
    preorder(0, N - 1, 0, N - 1);
}
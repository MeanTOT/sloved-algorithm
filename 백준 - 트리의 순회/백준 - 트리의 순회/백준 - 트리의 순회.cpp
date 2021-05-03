#include <iostream>
#include <vector>
using namespace std;
int N = 0;
vector<int> inorder;
vector<int> postorder;
//vector<int> slice(const vector<int>& v, int a, int b)
//{
//    return vector<int>(v.begin() + a, v.begin() + b);
//}
//void preorder(const vector<int>& in, const vector<int>& post)
//{
//    if (in.size() == 0) return;
//    cout << post[post.size() - 1] << " ";
//    for (int i = 0; i < in.size(); ++i)
//    {
//        if (in[i] == post[post.size() - 1])
//        {            
//            preorder(slice(in, 0, i), slice(post, 0, i));            
//            preorder(slice(in, i + 1, in.size()), slice(post, i, in.size() - 1));
//            break;
//        }
//    }
//}
void preorder(int in_start, int in_end, int post_start, int post_end)
{
    if (in_start - in_end == 0) return;
    cout << postorder[post_end] << " ";
    for (int i = in_start; i < in_end; ++i)
    {
        if (inorder[i] == postorder[post_end])
        {
            preorder(in_start, in_start + i - 1, post_start, post_start + i - 1);
            preorder(in_start + i + 1, in_start + (in_end - in_start), post_start + i, post_start + (in_end - in_start) - 1);
            break;
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
    //preorder(inorder, postorder);
    preorder(0, N - 1, 0, N - 1);
}
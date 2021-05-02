#include <iostream>
#include <memory.h>
char Tree[26][2];
void Preorder(int index)
{    
    std::cout << char(index + 65);
    if (Tree[index][0] != '.')
        Preorder(Tree[index][0] - 65);
    if (Tree[index][1] != '.')
        Preorder(Tree[index][1] - 65);
}
void Inorder(int index)
{
    if (Tree[index][0] != '.')
        Inorder(Tree[index][0] - 65);
    std::cout << char(index + 65);
    if (Tree[index][1] != '.')
        Inorder(Tree[index][1] - 65);
}
void Postorder(int index)
{
    if (Tree[index][0] != '.')
        Postorder(Tree[index][0] - 65);
    if (Tree[index][1] != '.')
        Postorder(Tree[index][1] - 65);
    std::cout << char(index + 65);
}
int main()
{
    int N = 0;
    std::cin >> N;
    memset(Tree, 0, sizeof(Tree));
    while (N--)
    {
        char node = 0, left = 0, right = 0;
        std::cin >> node >> left >> right;
        Tree[node - 65][0] = left;
        Tree[node - 65][1] = right;
    }
    Preorder(0);
    std::cout << std::endl;
    Inorder(0);
    std::cout << std::endl;
    Postorder(0);
}
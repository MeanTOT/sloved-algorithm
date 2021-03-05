#include <iostream>
#include <bitset>

bool CheckBit(int num, int i)
{
	return ((num & (1 << i)) != 0);
}

int SetBit(int num, int i)
{
	return (num | (1 << i));
}

int ClearBit(int num, int i)
{
	return num & ~(1 << i);
}

//�ֻ��� ��Ʈ���� i��° ��Ʈ���� ����
int ClearBitsMSBthroughI(int num, int i)
{
	return num & (1 << i) - 1;
}

//i��° ��Ʈ���� 0��° ��Ʈ���� ��� ����
int ClearBitsIthrough0(int num, int i)
{
	return num & (-1 << (i + 1));
}

//��Ʈ�� �ٲٱ�
int UpdateBit(int num, int i, bool bitIs1)
{
	int value = bitIs1 ? 1 : 0;
	num = num & ~(1 << i);
	return num | (value << i);
}

int main()
{
	std::cout << std::bitset<16>(8) << std::endl;
	std::cout << std::bitset<16>(UpdateBit(8, 3, 0));

	return 0;
}
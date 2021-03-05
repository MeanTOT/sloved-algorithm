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

//최상위 비트에서 i번째 비트까지 삭제
int ClearBitsMSBthroughI(int num, int i)
{
	return num & (1 << i) - 1;
}

//i번째 비트에서 0번째 비트까지 모두 삭제
int ClearBitsIthrough0(int num, int i)
{
	return num & (-1 << (i + 1));
}

//비트값 바꾸기
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
#include <iostream>

void OneStep(int remainedStair);
void TwoStep(int remainedStair);
void ThreeStep(int remainedStair);

int WayCount = 0;

int main()
{
	int Stair = 5;
	
	OneStep(5);
	TwoStep(5);
	ThreeStep(5);

	std::cout << WayCount;

	return 0;
}

void OneStep(int remainedStair)
{
	if (remainedStair - 1 == 0)
	{
		WayCount++;
		return;
	}
	else if (remainedStair - 1 < 0)
	{
		return;
	}
	else
	{
		OneStep(remainedStair - 1);
		TwoStep(remainedStair - 1);
		ThreeStep(remainedStair - 1);
	}
}

void TwoStep(int remainedStair)
{
	if (remainedStair - 2 == 0)
	{
		WayCount++;
		return;
	}
	else if (remainedStair - 2 < 0)
	{
		return;
	}
	else
	{
		OneStep(remainedStair - 2);
		TwoStep(remainedStair - 2);
		ThreeStep(remainedStair - 2);
	}
}

void ThreeStep(int remainedStair)
{
	if (remainedStair - 3 == 0)
	{
		WayCount++;
		return;
	}
	else if (remainedStair - 3 < 0)
	{
		return;
	}
	else
	{
		OneStep(remainedStair - 3);
		TwoStep(remainedStair - 3);
		ThreeStep(remainedStair - 3);
	}
}
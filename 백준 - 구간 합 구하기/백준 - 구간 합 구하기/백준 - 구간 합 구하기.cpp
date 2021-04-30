#include <iostream>
#include <vector>
using namespace std;

struct RMQ
{
	int n;
	vector<long long> rangeMin;
	RMQ(const vector<long long>& array)
	{
		n = array.size();
		rangeMin.resize(n * 4); //
		init(array, 0, n - 1, 1);
	}

	long long init(const vector<long long>& array, int left, int right, int node)
	{
		if (left == right)
			return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		long long leftMin = init(array, left, mid, node * 2);
		long long rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = leftMin + rightMin;
	}

	long long query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || nodeRight < left) return 0; // 두 구간이 겹치지 않으면 아주 큰값을 반환한다. : 무시됨
		if (left <= nodeLeft && nodeRight <= right) return rangeMin[node]; // node가 표현하는 범위가 arrat[left ... right]에 완전히 포함되는 경우
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, node * 2 + 1, mid + 1, nodeRight) + query(left, right, node * 2, nodeLeft, mid);
	}

	// 외부에 공개되는 인터페이스
	long long query(int left, int right)
	{
		return query(left, right, 1, 0, n - 1);
	}

	// 특정 인덱스의 값을 변경하고자할때 사용한다.
	long long update(int index, long long newValue, int node, int nodeLeft, int nodeRight)
	{
		if (index < nodeLeft || nodeRight < index) return rangeMin[node];
		if (nodeLeft == nodeRight) return rangeMin[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMin[node] = update(index, newValue, node * 2, nodeLeft, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
	}

	// 외부에 공개되는 인터페이스
	long long update(int index, long long newValue)
	{
		return update(index, newValue, 1, 0, n - 1);
	}
};

int main()
{
    ios::sync_with_stdio(false);
    long long N, M, K = 0;
    cin >> N >> M >> K;
    vector<long long> numbers;
    while (N--)
    {
        long long val = 0;
        cin >> val;
        numbers.push_back(val);
    }

	RMQ sgTree(numbers);
    long long a, b, c = 0;
    for (int i = 0; i < M + K; ++i)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
			sgTree.update(b - 1, c);
        }
        else
        {
			printf("%lld\n",sgTree.query(b - 1, c - 1));
        }
    }
}
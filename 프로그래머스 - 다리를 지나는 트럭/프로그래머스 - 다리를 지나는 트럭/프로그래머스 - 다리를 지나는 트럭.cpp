#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Truck
{
    int weight;
    int onBridgeTime;
};

void CheckCollapsedTimeTrucksOnBridge(queue<Truck>& trucksOnBridge, int currentTime, int bridgeLength, int& weightAmountOnBridge)
{
    if (trucksOnBridge.empty())
        return;

    if (currentTime - trucksOnBridge.front().onBridgeTime == bridgeLength)
    {
        weightAmountOnBridge -= trucksOnBridge.front().weight;
        trucksOnBridge.pop();
    }
}

void TryAddTruckToBridge(vector<int>& truck_weights, queue<Truck>& trucksOnBridge, int& weightAmountTrucksOnBridge, int weight, int currentTime)
{
    if (truck_weights.size() == 0)
        return;

    int nextTruckWeight = truck_weights.front();
    if (weightAmountTrucksOnBridge + nextTruckWeight <= weight)
    {
        Truck truck{ nextTruckWeight, currentTime };
        trucksOnBridge.push(truck);
        weightAmountTrucksOnBridge += nextTruckWeight;
        truck_weights.erase(truck_weights.begin());
    }
}

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;
    queue<Truck> trucksOnBridge;

    int weightAmountTrucksOnBridge = 0;
    while (true)
    {
        if (truck_weights.size() == 0 && trucksOnBridge.size() == 0)
            break;      

        answer++;
        CheckCollapsedTimeTrucksOnBridge(trucksOnBridge, answer, bridge_length, weightAmountTrucksOnBridge);   
        TryAddTruckToBridge(truck_weights, trucksOnBridge, weightAmountTrucksOnBridge, weight, answer);
    }

    return answer;
}

int main()
{
    vector<int> truckWeights = { 7,4,5,6 };
    cout << solution(2, 10, truckWeights);

    return 0;
}
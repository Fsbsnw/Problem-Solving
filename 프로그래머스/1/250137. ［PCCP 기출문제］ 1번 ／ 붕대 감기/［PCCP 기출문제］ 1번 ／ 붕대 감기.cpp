#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int MaxHealth = health;
    int BandageDuration = 0;
    int MaxTime = attacks[attacks.size() - 1][0];
    int MaxAttackIndex = attacks.size() - 1;
    int AttackIndex = 0;
    
    for (int Time = 1; Time <= MaxTime; Time++)
    {
        // attack 시간에 해당하는 경우
        if (attacks[AttackIndex][0] == Time)
        {
            // 체력 감소
            health -= attacks[AttackIndex][1];
            if (health <= 0) break;
            AttackIndex = min(MaxAttackIndex, AttackIndex + 1);
            BandageDuration = 0;
        }
        // attack 시간이 아닌 경우
        else if (attacks[AttackIndex][0] > Time)
        {
            health = min(MaxHealth, health + bandage[1]);
            BandageDuration++;
            
            // 연속 시전 시간을 채운 경우
            if (BandageDuration == bandage[0])
            {
                health = min(MaxHealth, health + bandage[2]);
                BandageDuration = 0;
            }
        }
    }
    
    if (health <= 0) answer = -1;
    else answer = health;
    
    return answer;
}
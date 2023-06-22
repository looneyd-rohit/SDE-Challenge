#include <bits/stdc++.h>
using namespace std;

bool solve(int power, int index, int skips, int recharges, int maxPower, vector<int> &enemy)
{
    // base case
    if (index >= enemy.size())
    {
        return true;
    }

    if (power <= enemy[index])
    {
        // can't fight at one go --> has to skip or fight and recharge
        // skip
        bool skip = false;
        if (skips > 0)
        {
            skip = solve(power, index + 1, skips - 1, recharges, maxPower, enemy);
        }

        // fight and recharge
        bool fightAndRecharge = false;
        int reqRecharges = ceil((enemy[index] - power) * 1.0 / maxPower);
        if (reqRecharges <= recharges)
        {
            fightAndRecharge = solve(power + reqRecharges * maxPower - enemy[index], index + 1, skips, recharges, maxPower, enemy);
        }

        return (skip || fightAndRecharge);
    }
    else
    {
        return solve(power - enemy[index], index + 1, skips, recharges, maxPower, eneymy);
    }
}

int main()
{
    return 0;
}
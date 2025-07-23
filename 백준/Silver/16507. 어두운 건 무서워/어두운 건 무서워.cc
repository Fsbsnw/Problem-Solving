#include <iostream>

using namespace std;

int PixelBrightness[1001][1001];
int BrightnessPrefixSum[1001][1001];

int main()
{
    int R, C, Q;
    cin >> R >> C >> Q;
    
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> PixelBrightness[i][j];
            BrightnessPrefixSum[i][j] = BrightnessPrefixSum[i - 1][j] + BrightnessPrefixSum[i][j - 1] - BrightnessPrefixSum[i - 1][j - 1] + PixelBrightness[i][j];
        }
    }
    
    for (int Case = 0; Case < Q; Case++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        
        int Count = (r2 - r1 + 1) * (c2 - c1 + 1);
        int BrightnessSum = BrightnessPrefixSum[r2][c2] - BrightnessPrefixSum[r1 - 1][c2] - BrightnessPrefixSum[r2][c1 - 1] + BrightnessPrefixSum[r1 - 1][c1 - 1];
        
        printf("%d\n", BrightnessSum / Count);
    }

    return 0;
}
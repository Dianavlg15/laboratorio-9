#include <stdio.h>

int trapRainWater(int* height, int n) {
    if (n <= 2) return 0;

    int leftMax[n], rightMax[n];
    int totalWater = 0;

    // Llenar arreglo de máximos a la izquierda
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = (height[i] > leftMax[i - 1]) ? height[i] : leftMax[i - 1];
    }

    // Llenar arreglo de máximos a la derecha
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = (height[i] > rightMax[i + 1]) ? height[i] : rightMax[i + 1];
    }

    // Calcular agua atrapada
    for (int i = 0; i < n; ++i) {
        int minHeight = (leftMax[i] < rightMax[i]) ? leftMax[i] : rightMax[i];
        if (minHeight > height[i]) {
            totalWater += minHeight - height[i];
        }
    }

    return totalWater;
}

int main() {
    int height1[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n1 = sizeof(height1) / sizeof(height1[0]);
    printf("Water trapped: %d\n", trapRainWater(height1, n1));  // Output: 6

    int height2[] = {4,2,0,3,2,5};
    int n2 = sizeof(height2) / sizeof(height2[0]);
    printf("Water trapped: %d\n", trapRainWater(height2, n2));  // Output: 9

    return 0;
}


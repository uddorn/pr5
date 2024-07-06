#include <stdio.h>
#include <Windows.h>
#define MOD 12345

int main() {
    SetConsoleCP ( 1251 );
    SetConsoleOutputCP ( 1251 );
    int n;
    printf("������ ������� ����������� n: ");
    scanf("%d", &n);

    if (n < 1 || n >= 10000) {
        printf("���������� �������� n. ������ n � ������� (1 < n < 10000).\n");
        return 1;
    }

    int dp[n + 1][3];

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][1];
    }

    int result = (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
    printf("ʳ������ ������� �������������: %d\n", result);

    return 0;
}

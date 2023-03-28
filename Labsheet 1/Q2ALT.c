#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int m, n, p, q;
    scanf("%d%d", &m, &n);
    int A[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    scanf("%d%d", &p, &q);
    int B[p][q];
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            scanf("%d", &B[i][j]);

    bool partial = false;
    for (int i = 0; i <= m - p; i++) {
        for (int j = 0; j <= n - q; j++) {
            int k, l;
            bool match = true;
            for (k = 0; k < p; k++) {
                for (l = 0; l < q; l++) {
                    if (A[i + k][j + l] != B[k][l]) {
                        match = false;
                        break;
                    }
                }
                if (!match)
                    break;
            }
            if (match) {
                printf("YES\n");
                return 0;
            } else {
                for (int x = 0; x < p; x++) {
                    for (int y = 0; y < q; y++) {
                        int u, v;
                        bool found = false;
                        for (u = i; u < m; u++) {
                            for (v = 0; v < n; v++) {
                                if (A[u][v] == B[x][y]) {
                                    found = true;
                                    break;
                                }
                            }
                            if (found)
                                break;
                        }
                        if (!found) {
                            printf("NO\n");
                            return 0;
                        }
                    }
                }
                partial = true;
            }
        }
    }

    if (partial)
        printf("PARTIAL\n");
    else
        printf("NO\n");

    return 0;
}
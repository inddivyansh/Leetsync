class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int m = A.size();

        Matrix C(m, vector<long long>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int k = 0; k < m; k++) {

                if (A[i][k] == 0) continue;

                for (int j = 0; j < m; j++) {
                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, int exp) {
        int m = base.size();

        Matrix result(m, vector<long long>(m, 0));

        for (int i = 0; i < m; i++)
            result[i][i] = 1;

        while (exp) {
            if (exp & 1)
                result = multiply(result, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return result;
    }

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        Matrix U(m, vector<long long>(m, 0));
        Matrix L(m, vector<long long>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++)
                U[i][j] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++)
                L[i][j] = 1;
        }

        n--;

        Matrix UL = multiply(U, L);

        Matrix P = power(UL, n / 2);

        if (n & 1)
            P = multiply(L, P);

        long long ans = 0;

        for (auto& row : P) {
            for (auto x : row) {
                ans = (ans + x) % MOD;
            }
        }

        return (2 * ans) % MOD;
    }
};
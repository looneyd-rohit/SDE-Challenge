// The sparse table data stuctures are used to compute range min/min/gcd in O(1) time
// compared to O(logN) in segment trees

// we basically store the range mins of ranges of length [1], [2], [4], [8], ... and so on
// on a 2D matrix, here the lengths can be thought of as powers of 2 --> [0], [1], [2], ...
// (upto the power of 2 <= actual length of array)

// only applicable for static data --> offline data
// online data cannot be queried --> which means if there are any updates we need to
// recompute every time

const int N = 1e5;
const int logBase2N = log(N);
int matrix[N][logBase2N + 1];

void build()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        matrix[i][0] = arr[i];
    }

    // j --> symbolizes power of 2, so j = 1 means 2^1 = 2 length
    for (int j = 1; j <= logBase2N; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < N; i++)
        {
            // for a range of length N = min(left part length/2, right part length/2)
            matrix[i][j] = min(matrix[i][j - 1], matrix[i + (1 << (j - 1))][j - 1]);
        }
    }
}
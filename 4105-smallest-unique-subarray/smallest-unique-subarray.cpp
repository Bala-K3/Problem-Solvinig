
class Solution {
public:
    using ll = long long;
    using ull = unsigned long long;

    const ll MOD1 = 1000000007;
    const ll MOD2 = 1000000009;

    const ll BASE1 = 911382323;
    const ll BASE2 = 972663749;

    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        vector<ll> h1(n + 1, 0), h2(n + 1, 0);
        vector<ll> p1(n + 1, 1), p2(n + 1, 1);

        // Step 1: Precompute prefix hashes and powers
        for (int i = 0; i < n; i++) {

            h1[i + 1] = (h1[i] * BASE1 + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + nums[i]) % MOD2;

            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
        }

        // Step 2: Check whether a unique subarray exists
        auto isValid = [&](int len) {

            unordered_map<ull, int> freq;

            for (int i = 0; i + len <= n; i++) {

                int j = i + len;

                ll hash1 = (h1[j] -
                    h1[i] * p1[len] % MOD1 + MOD1) % MOD1;

                ll hash2 = (h2[j] -
                    h2[i] * p2[len] % MOD2 + MOD2) % MOD2;

                // Combine both hashes
                ull key = ((ull)hash1 << 30) | (ull)hash2;

                freq[key]++;
            }

            // Check whether any subarray appears exactly once
            for (auto& it : freq) {
                if (it.second == 1) {
                    return true;
                }
            }

            return false;
        };

        // Step 3: Binary Search on Answer
        int low = 1;
        int high = n;
        int ans = n;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isValid(mid)) {

                ans = mid;
                high = mid - 1;

            } else {

                low = mid + 1;
            }
        }

        return ans;
    }
};

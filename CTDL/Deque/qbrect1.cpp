#include <iostream>
#include <deque>
#include <array>

int main() {
    std::ios_base::sync_with_stdio(0); 
	std::cin.tie(0); 
	std::cout.tie(0);

    std::array<std::array<char, 1001>, 1001> Board;
    std::array<long long, 1001> H, L, R;

    int N, M;
    std::cin >> N >> M;

    for(int it0 = 1; it0 <= N; it0++)
        for(int it1 = 1; it1 <= M; it1++) 
			std::cin >> Board[it0][it1];

    long long Ans;

    for(int it0 = 1; it0 <= N; it0++) {
        std::deque<int> Dq0, Dq1;

        for(int it1 = 1; it1 <= M; it1++) {
            H[it1] = (Board[it0][it1] == '1'? H[it1] + 1 : 0);
            
            while(!Dq0.empty() && H[Dq0.back()] >= H[it1])
                Dq0.pop_back();

            L[it1] = (!Dq0.empty()? Dq0.back() + 1 : 1);

            Dq0.push_back(it1);
        }

        for(int it1 = M; it1 > 0; it1--) {
            while(!Dq1.empty() && H[Dq1.back()] >= H[it1]) 
				Dq1.pop_back();

            R[it1] = (!Dq1.empty()? Dq1.back() - 1 : M);

            Dq1.push_back(it1);

            Ans = std::max(Ans, H[it1] * (R[it1] - L[it1] + 1));
        }
    }

    std::cout << Ans;
}

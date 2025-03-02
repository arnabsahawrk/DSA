// https://school.outsbook.com/problems/problemdetails/10106
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void sundorbanPath(vector< vector<char> > mat, vector< pair<int,int> > sd) {
    int n = (int)mat.size();

    int si = sd[0].first;
    int sj = sd[0].second;
    int di = sd[1].first;
    int dj = sd[1].second;

    vector< vector<bool> > vis(n, vector<bool>(n, false));
    vector< vector<int> > level(n, vector<int>(n, 0));

    queue< pair<int,int> > q;
    q.push(std::make_pair(si, sj));
    vis[si][sj] = true;
    level[si][sj] = 0;

    int dRow[4] = {0, 0, 1, -1};
    int dCol[4] = {1, -1, 0, 0};

    while (!q.empty()) {
        int pi = q.front().first;
        int pj = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ci = pi + dRow[i];
            int cj = pj + dCol[i];

            bool valid = (ci >= 0 && ci < n && cj >= 0 && cj < n);
            if (valid && mat[ci][cj] != 'T' && !vis[ci][cj]) {
                q.push(std::make_pair(ci, cj));
                vis[ci][cj] = true;
                level[ci][cj] = level[pi][pj] + 1;
            }
        }
    }

    cout << level[di][dj] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    while (cin >> n)
    {
     vector< vector<char> > adj_mat(n, vector<char>(n));
     vector< pair<int,int> > src_to_des;

     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             cin >> adj_mat[i][j];
             if (adj_mat[i][j] == 'S') {
                 src_to_des.push_back(std::make_pair(i, j));
             }  else if (adj_mat[i][j] == 'E') {
                 src_to_des.push_back(std::make_pair(i, j));
             }
         }
      }

      sundorbanPath(adj_mat, src_to_des);
    }
    return 0;
}


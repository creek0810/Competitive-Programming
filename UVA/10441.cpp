#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 30;
vector<string> g[N];
// g[i] stores the words whose prefix is i+'a' 
vector<string> ans;
// to store the final ans
int t, n, parent[N];
// parent = which letter does the i-th letter point to
// t = the number of test cases
// n = the number of the words in the current case 
bool used[N][1005];
int vis[N];
// if the letter have been used
int cnt, tot, ru[N], chu[N];
// tot = how many letters have been used
// ru = how many in_edges does the letter have
// chu = how many out_edges does the letter have
// how many times do the procces combine the sets
int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}
void init() { 
    memset(ru, 0, sizeof(ru));
    memset(chu, 0, sizeof(chu));
    memset(vis, 0, sizeof(vis));
    memset(used, 0, sizeof(used));
    for (int i = 0; i < 26; i++) {
        g[i].clear();
        parent[i] = i;
    }
    cnt = 1; tot = 0;
    scanf("%d", &n);
    string s;
    while (n--) {
        cin >> s;
        int u = s[0] - 'a', v = s[s.length() - 1] - 'a';
        if (!vis[u]) {vis[u] = 1; tot++;}
        if (!vis[v]) {vis[v] = 1; tot++;}
        ru[v]++; chu[u]++;
        g[u].push_back(s);
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            parent[pu] = pv;
            cnt++;
        }
    }
    for (int i = 0; i < 26; i++)
        sort(g[i].begin(), g[i].end());
}
void dfs(int u) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i][g[u][i].length() - 1] - 'a';
        // if the word have been added into the ans array
        if (used[u][i]) continue;
        used[u][i] = 1;
        cout << g[u][i] << endl;
        dfs(v);
        ans.push_back(g[u][i]);
        for(int i=0;i<ans.size();i++){
            cout << ans[i]  << " "; 
        }
        cout << "\n";
    }
}

bool solve() {
    if (cnt != tot) return false;
    // if all the letters are in the same group
    int Min = 30;
    int odd = 0, st;
    for (int i = 0; i < 26; i++) {
        // if there are words in the testcase whose prefix is i+'a'
        if (g[i].size()) Min = min(Min, i);
        // if letter i is the start point 
        if (ru[i] - chu[i] == -1) {
            odd++;
            st = i;
        }
        // if the letter i is the end point
        else if (chu[i] - ru[i] == -1)
            odd++;
        else if (chu[i] != ru[i]) return false;
        if (odd > 2) return false;
        // if odd == 2 then the map is an euler trail
        // if odd == 0 then the map is an euler circuit
        // if odd !=2 && odd !=0 then the map is't match the question's requirement   
    }
    ans.clear();
    // to find the least euler circuit
    if (!odd) dfs(Min);
    // to find the euler trail
    else dfs(st);
    cout << g[st][0];
    for (int i = ans.size() - 1; i > 0; i--)
        cout << ans[i] << ".";
    cout << ans[0] << endl;
    return true;
}

int main() {
    scanf("%d", &t); 
    while (t--) {
        init();
        if (!solve()) printf("***\n");
    }
    return 0;
}
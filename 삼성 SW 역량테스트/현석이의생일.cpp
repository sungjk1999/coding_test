#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


string makeNum(string N, string x, string y);
void dfs(int idx, bool flag, string res, string N, string x, string y, string &biggest);


int main() {

    int T;
    string N, x, y, res;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> x >> y;
        res = makeNum(N, x, y);
        if (res == "0" || res == "") {
            res = "-1";
        }
        cout << '#' << t + 1 << ' ' << res << endl;
    }

    return 0;
}


string makeNum(string N, string x, string y) {
    string biggest = "";
    dfs(0, false, "", N, x, y, biggest);
    return biggest;
}

void dfs(int idx, bool flag, string res, string N, string x, string y, string &biggest) {

    int k;

    if (res == "0") {
        res = "";
    }

    if (flag) {
        for (k = idx; k < N.length(); k++) {
            res += y;
        }
        if (N.length() > res.length()) {
            if (res.length() > biggest.length()) {
                biggest = res;
            }
            else if (res.length() == biggest.length()) {
                biggest = max(res, biggest);
            }
        }
        else if (N.length() == res.length()) {
            if (res <= N) {
                if (res.length() > biggest.length()) {
                    biggest = res;
                }
                else if (res.length() == biggest.length()) {
                    biggest = max(res, biggest);
                }
            }
        }
        return;
    }

    int val = N[idx] - '0';
    int int_y = stoi(y);
    int int_x = stoi(x);


    if (val > int_y) {
        dfs(idx + 1, true, res + y, N, x, y, biggest);
    }
    else if (val == int_y) {
        dfs(idx + 1, false, res + y, N, x, y, biggest);
        dfs(idx + 1, true, res + x, N, x, y, biggest);
    }
    else if (val > int_x) {
        dfs(idx + 1, true, res + x, N, x, y, biggest);
    }
    else if (val == int_x) {
        dfs(idx + 1, false, res + x, N, x, y, biggest);
        dfs(idx + 1, true, res, N, x, y, biggest);
    }
    else { // val < x
        dfs(idx + 1, true, res, N, x, y, biggest);
    }
}
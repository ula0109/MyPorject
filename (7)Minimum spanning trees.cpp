#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include<queue>

using namespace std;

vector<vector<int>>cycleRecord;
bool checkCycle(vector<int>cycle) {
    bool flag = false;
    for (int i = 0; i < cycleRecord.size(); i++) {
        if (cycle.size() == cycleRecord[i].size()) {
            for (int j = 0; j < cycle.size(); j++) {
                if (cycle[j] != cycleRecord[i][j]) {
                    flag = false;
                    break;
                }
                else flag = true;
            }
        }
    }
    return flag;
}
bool samee() {
    

    vector<int>& firstCycle = cycleRecord[0];
    vector<int>& secondCycle = cycleRecord[1];

    
    for (int i = 0; i < firstCycle.size(); ++i) {
        int u1 = firstCycle[i];
        int v1 = firstCycle[(i + 1) % firstCycle.size()];  // 下一個頂點，考慮循環

        for (int j = 0; j < secondCycle.size(); ++j) {
            int u2 = secondCycle[j];
            int v2 = secondCycle[(j + 1) % secondCycle.size()];  // 下一個頂點，考慮循環

            // 檢查是否有相同的邊 (u1, v1) 和 (u2, v2)
            if ((u1 == u2 && v1 == v2) || (u1 == v2 && v1 == u2)) {
                return true;
            }
        }
    }

    return false;
}


void cyclecheck(stack<int>path, int next_point) {
    int count = 0;
    vector<int>cycle;
    cycle.push_back(next_point);
   
    while (!path.empty()) {

        if (path.top() == next_point) {
            if (count != 1) {
                cycle.push_back(path.top());
                if (!checkCycle(cycle))cycleRecord.push_back(cycle); 

                return;
            }
            else {
                
                return;
            }
        }
        else {
            count++;
            cycle.push_back(path.top());
            path.pop();

        }

    }
    
}

bool dfs(vector<vector<int>> record) {
    stack<int>path;

    record[0][0] = 1;
    
    int point = 1;
    
    path.push(point);
   

    for (int i = 0; i < record[point].size(); i++) {
        int next_point = record[point][i];
        if (record[0][next_point - 1] == 1) {
            
            cyclecheck(path, next_point);
            if (record[point].size() - 1 == i) {

                path.pop();
                if (path.empty())break;
                point = path.top();
                i = -1;
            }
            
            continue;
        }
        point = next_point;
        record[0][next_point - 1] = 1;//標記
        path.push(point);
       
        i = -1;

    }

    
    for (int i = 0; i < record[0].size(); i++) {
        if (record[0][i] == 0) {
            
            return false;
        }

    }

    return true;

}



int main() {
    int n;
    cin >> n;

    vector<vector<int>> record;
  
    for (int i = 0; i <= n; i++) {
        vector<int>row;
        for (int j = 0; i == 0 && j < n; j++) {
            row.push_back(0);
        }
        record.push_back(row);
    }

    int a, b;
    int E = 0;
    while (cin >> a) {
        if (a == -1)break;
        cin >> b;
        record[a].push_back(b);
        record[b].push_back(a);
        E++;
    }


    if (!dfs(record)) {
        cout << "n";
        return 0;
    }



    if (E - n >= 2) {
        cout << "y" << endl;
        cout << "There are at least three cycles." << endl;
        return 0;
    }
    if (E - n == 1) {
        cout << "y" << endl;
        if (samee()) {

            cout << "There are at least three cycles." << endl;
        }

    }
    else {
        cout << "n";
    }




}

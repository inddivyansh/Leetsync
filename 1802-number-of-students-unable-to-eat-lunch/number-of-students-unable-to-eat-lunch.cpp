class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

        for (int x : students) {
            q.push(x);
        }

        int i = 0;          
        int rotate = 0;     

        while (!q.empty() && rotate < q.size()) {
            if (q.front() == sandwiches[i]) {
                q.pop();
                i++;
                rotate = 0;   
            } else {
                q.push(q.front());
                q.pop();
                rotate++;
            }
        }

        return q.size();
    }
};
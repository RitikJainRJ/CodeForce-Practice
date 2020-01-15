/*
Anna and Maria are in charge of the math club for junior students. When the club gathers together,
the students behave badly. They've brought lots of shoe laces to the club and got tied with each other.
Specifically, each string ties together two students. Besides, if two students are tied, then the lace
connects the first student with the second one as well as the second student with the first one.

To restore order, Anna and Maria do the following. First, for each student Anna finds out what other
students he is tied to. If a student is tied to exactly one other student, Anna reprimands him.
Then Maria gathers in a single group all the students who have been just reprimanded. She kicks them
out from the club. This group of students immediately leaves the club. These students takes with them
the laces that used to tie them. Then again for every student Anna finds out how many other students he
is tied to and so on. And they do so until Anna can reprimand at least one student.

Determine how many groups of students will be kicked out of the club.
*/
#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int n;
        list<int> *arr;
        int *indegree;
    public:
        Graph(int n){
            this->n = n;
            arr = new list<int>[n];
            indegree = new int[n];
            for(int i = 0; i < n; i++)
                indegree[i] = 0;
        }

        void addEdge(int u, int v){
            indegree[u]++;
            indegree[v]++;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }

        void printGraph(){
            list<int>::iterator it;
            for(int i = 0; i < n; i++){
                cout << i << " ";
                for(it = arr[i].begin(); it != arr[i].end(); it++)
                    cout << *it << " ";
                cout << endl;
            }
        }

        int findGroup();
};

int Graph::findGroup(){
    int counter = 0;
    bool visited[n];
    queue<int> q;
    list<int>::iterator it;

    memset(visited, false, sizeof(visited));
    while(1){
        for(int i = 0; i < n; i++){
            if(indegree[i] == 1 && visited[i] == false){
                q.push(i);
                visited[i] = true;
            }
        }
        if(q.empty())
            break;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(it = arr[u].begin(); it != arr[u].end(); it++)
                if(visited[*it] == false)
                    indegree[*it]--;
        }
        counter++;
    }
    return counter;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;

    cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g.addEdge(u, v);
    }
    cout << g.findGroup() << endl;
    return 0;
}

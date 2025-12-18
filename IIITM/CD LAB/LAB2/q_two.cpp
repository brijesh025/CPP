#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> epsilonTransition;

set<int> epsilonClosure(int state)
{
    set<int> closure;
    stack<int> st;
    st.push(state);
    closure.insert(state);
    while (!st.empty())
    {
        int s = st.top();
        st.pop();

        for (int next : epsilonTransition[s])
        {
            if (closure.find(next) == closure.end())
            {
                closure.insert(next);
                st.push(next);
            }
        }
    }
    return closure;
}

int main()
{
    int numStates;
    cout << "Enter number of states: ";
    if (!(cin >> numStates)) return 0;

    epsilonTransition.assign(numStates, {});

    int numTransitions;
    cout << "Enter number of epsilon transitions: ";
    cin >> numTransitions;

    cout << "Enter transitions (from_state to_state):\n";
    for (int i = 0; i < numTransitions; i++){
        int from, to;
        cin >> from >> to;
        if (from >= 0 && from < numStates && to >= 0 && to < numStates)
            epsilonTransition[from].push_back(to);
    }

    for (int i = 0; i < numStates; i++)
    {
        set<int> closure = epsilonClosure(i);
        cout << "epsilon closure(" << i << ") = { ";
        for (int s : closure) cout << s << " ";
        cout << "}\n";
    }
    cout<<"2023-IMT025 BRIJESH SINGH";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void printCircuit(vector<vector<ll>> adj, ll l, ll r)
{
    // adj represents the adjacency list of
    // the directed graph
    // edge_count represents the number of edges
    // emerging from a vertex
    unordered_map<ll, ll> edge_count;

    for (ll i = 1; i <= adj.size(); i++)
    {
        //find the count of edges to keep track
        //of unused edges
        edge_count[i] = adj[i].size();
    }

    if (!adj.size())
        return; //empty graph

    // Mallain a stack to keep vertices
    stack<ll> curr_path;

    // vector to store final circuit
    vector<ll> circuit;

    // start from any vertex
    curr_path.push(1);
    ll curr_v = 0; // Current vertex

    while (!curr_path.empty())
    {
        // If there's remaining edge
        if (edge_count[curr_v])
        {
            // Push the vertex
            curr_path.push(curr_v);

            // Find the next vertex using an edge
            ll next_v = adj[curr_v].back();

            // and remove that edge
            edge_count[curr_v]--;
            adj[curr_v].pop_back();

            // Move to next vertex
            curr_v = next_v;
        }

        // back-track to find remaining circuit
        else
        {
            circuit.push_back(curr_v);

            // Back-tracking
            curr_v = curr_path.top();
            curr_path.pop();
        }
    }

    // we've got the circuit, now prll it in reverse
    // for (ll i = circuit.size() - 1; i >= 0; i--)
    // {

    //     cout << circuit[i];
    //     if (i)
    //         cout << " ";
    // }

    for (ll i = circuit.size() - 1; i >= 0; i--)
    {
        if (i >= l && i <= r)
        {
            cout << circuit[i];
            if (i)
                cout << " ";
        }
    }
}

main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, l, r;
        cin >> n >> l >> r;
        vector<vector<ll>> adj(n+2);

        for (ll i = 1; i <= n; i++)
        {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }

        printCircuit(adj, l, r);
        cout << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define loop(var, initial, final) for (int var = initial; var < final; var++)
template <typename T, typename P>
class tri
{
public:
    T val;
    P x;
    P y;
    tri(T val, P x, P y)
    {
        this->val = val;
        this->x = x;
        this->y = y;
    }

    tri() // default constructor
    {
    }
};

int32_t main()
{
    int n;
    cout << "enter number of elements in the set\n";
    cin >> n;
    vector<int> set(n);
    loop(i, 0, n)
    {
        cin >> set[i];
    }
    sort(all(set));
    vector<int> level(n);
    level[0] = 1;
    loop(i, 0, n)
    {
        int lvl = 0;
        loop(j, 0, i)
        {
            if (set[i] % set[j] == 0)
            {

                lvl = max(lvl, level[j] + 1);
            }
        }
        // if no number is divisible by set[i]
        if (lvl == 0)
        {
            level[i] = 1;
        }
        else
        {
            level[i] = lvl;
        }
    }

    cout << endl;
    vector<tri<int, double>> coord(n);
    int max_level = 1;
    loop(i, 0, n)
    {
        max_level = max(max_level, level[i]);
        ;
    }
    double height = 1070, width = 1910; // of window
    double y_diff = height / (max_level + 1);
    double curr_level_y = height;
    loop(i, 1, max_level + 1)
    {
        int c = 0;
        curr_level_y -= y_diff;
        loop(j, 0, n)
        {
            if (level[j] == i)
            {
                c++;
            }
        }
        int x_diff = width / (c + 1);
        int curr_level_x = width;
        loop(j, 0, n)
        {
            if (level[j] == i)
            {
                curr_level_x -= x_diff;
                tri<int, double> temp(set[j], curr_level_x, curr_level_y);
                coord[j] = temp;
            }
        }
    }

    vector<pair<int, int>> edges_f1, edges_f2, edges_f3;
    loop(i, 0, n)
    {
        vector<int> edges;

        for (int j = i; j >= 0; j--)
        {
            if (set[i] % set[j] == 0)
            {
                edges_f1.push_back({set[j], set[i]});
                if (set[i] != set[j])
                {
                    edges_f2.push_back({set[j], set[i]});
                    int flag = 1;
                    for (int k = 0; k < edges.size(); k++)
                    {
                        if (edges[k] % set[j] == 0)
                        {
                            flag = 0;
                        }
                    }
                    if (flag)
                    {
                        edges.push_back(set[j]);
                    }
                }
            }
        }

        loop(j, 0, edges.size())
        {
            edges_f3.push_back({set[i], edges[j]});
        }
    }

    fstream input;
    input.open("input.txt", ios::out);
    input << n << endl;
    loop(i, 0, n)
    {
        input << coord[i].val << " " << coord[i].x << " " << coord[i].y << endl;
    }
    // inputting edges
    cout << "which form you want to see? 1/2/3\n";

    int ch;
    cin >> ch;
    if (ch == 1)
    {

        input << edges_f1.size() << endl;
        ;

        loop(i, 0, edges_f1.size())
        {
            input << edges_f1[i].first << " " << edges_f1[i].second << endl;
        }
    }
    else if (ch == 2)
    {
        input << edges_f2.size() << endl;

        loop(i, 0, edges_f2.size())
        {
            input << edges_f2[i].first << " " << edges_f2[i].second << endl;
        }
    }
    else
    {
        input << edges_f3.size() << endl;

        loop(i, 0, edges_f3.size())
        {
            input << edges_f3[i].first << " " << edges_f3[i].second << endl;
        }
    }
    input << "sd\n";
    string s = "graphic.py <input.txt";
    string command = "python3 ";

    command += s;
    system(command.c_str());
    return 0;
}
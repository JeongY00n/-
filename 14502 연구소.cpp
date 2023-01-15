#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
    int y;
    int x;
};

int row, col;
int map[9][9] = { 0 };
int MAX = 0;

void bfs(Node w1, Node w2, Node w3) {

    queue<Node> q;
    int used[9][9] = { 0 };
    int new_map[9][9] = { 0 };
    //new_map�� map�� ������ �������ֱ�
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            new_map[i][j] = map[i][j];
            //���̷��� ��ġ ���� q�� push ���ش�
            if (map[i][j] == 2)
            {
                q.push({ i,j });
                used[i][j] = 1;
            }
        }
    }

    //main�Լ����� ���� �� ��ġ�� �������ش�
    new_map[w1.y][w1.x] = 1;
    new_map[w2.y][w2.x] = 1;
    new_map[w3.y][w3.x] = 1;


    int fy[] = { -1,1,0,0 };
    int fx[] = { 0,0,-1,1 };


    while (!q.empty())
    {

        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            // ���̷����� �̵�
            int ny = now.y + fy[i];
            int nx = now.x + fx[i];

            if (ny < 0 || nx < 0 || ny >= row || nx >= col)continue;
            if (new_map[ny][nx] != 0)continue;
            if (used[ny][nx] == 1)continue;

            used[ny][nx] = 1;
            new_map[ny][nx] = 2;

            q.push({ ny,nx });
        }

    }

    int cnt = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
        {
            if (new_map[i][j] == 0)
                cnt++;
            //cout << new_map[i][j] << " ";
        }//cout << endl;
    }

    if (MAX < cnt)
        MAX = cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> row >> col;
    vector<Node> v;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0)
            {
                v.push_back({ i,j });
            }
        }
    }

    // �� ����
    Node w1, w2, w3;

    for (int i = 0; i < v.size(); i++) {
        w1 = v[i];
        //cout << w1.y << "," << w1.x << endl;
        for (int j = i + 1; j < v.size(); j++) {
            w2 = v[j];
            for (int t = j + 1; t < v.size(); t++) {
                w3 = v[t];

                bfs(w1, w2, w3);
                //cout << MAX << endl;
            }
        }
    }

    cout << MAX;

    return 0;
}
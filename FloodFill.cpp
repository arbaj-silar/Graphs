#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int i, int j, vector<vector<int>>& image, int newColor, int orgColor) {
    if(i<0 || j<0 || i>=image.size() || j>=image[0].size() ||
             image[i][j] == newColor || image[i][j] != orgColor) return;

    image[i][j] = newColor;

    dfs(i-1, j, image, newColor, orgColor);
    dfs(i, j+1, image, newColor, orgColor);
    dfs(i+1, j, image, newColor, orgColor);
    dfs(i, j-1, image, newColor, orgColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    dfs(sr, sc, image, color, image[sr][sc]);

    return image;
}

int main() {
    vector<vector<int>> image = {{1, 1, 1},
                                {1, 1, 0},
                                {0, 1, 1}};

    vector<vector<int>> ans = floodFill(image, 1, 1, 2);

    for(auto& i: ans) {
        for(int j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
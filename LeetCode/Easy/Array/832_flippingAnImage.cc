// https://leetcode.com/problems/flipping-an-image/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        int rows = image.size();
        int cols = image[0].size();

        vector<vector<int>> ret;

        for (int i = 0; i < image.size(); i++)
        {
            reverse(image[i].begin(), image[i].end());
            ret.push_back(image[i]);
        }

        for (int i = 0; i < image.size(); i++)
            for (int j = 0; j < image[0].size(); j++)
                image[i][j] ^= 1; // (image[i][j] == 0) ? image[i][j] = 1 : image[i][j] = 0;

        return image;
    }
};

void printImage(vector<vector<int>> image)
{
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[0].size(); j++)
            cout << image[i][j] << " ";
        cout << endl;
    }
}
int main()
{

    Solution obj;

    vector<vector<int>> image{
        {1, 1, 0},
        {1, 0, 1},
        {0, 0, 0}};

    printImage(image);
    obj.flipAndInvertImage(image);
    cout << "After Inversion: \n";
    printImage(image);
}
// https://leetcode.com/problems/spiral-matrix/
// Given an m x n matrix, return all elements of the matrix in spiral order.

#include<iostream>
#include<vector> 

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int numberOfElements = matrix.size() * matrix[0].size();
        int direction = 0;
        int max_i = matrix.size() - 1;
        int max_j = matrix[0].size() - 1;
        int min_i = 0;
        int min_j = 0;
        int i = 0, j = 0;
        vector<int> v;
        while (numberOfElements)
            {
            // 0: horizontal positive, 1: vertical down, 2 horizontal negative, 3 vertical up. 

            switch (direction)
                {
                case 0:
                    while (j <= max_j)
                        {
                        v.push_back(matrix[i][j]);
                        numberOfElements--;
                        j++;
                        }
                    j--;
                    i++;
                    max_j--;
                    break;
                case 1:
                    while (i <= max_i)
                        {
                        v.push_back(matrix[i][j]);
                        numberOfElements--;
                        i++;
                        }
                    i--;
                    j--;
                    max_i--;
                    break;

                case 2:
                    while (j >= min_j)
                        {
                        v.push_back(matrix[i][j]);
                        numberOfElements--;
                        j--;
                        }
                    j++;
                    i--;
                    min_j++;
                    break;
                case 3:
                    while (i > min_i)
                        {
                        v.push_back(matrix[i][j]);
                        numberOfElements--;
                        i--;
                        }
                    i++;
                    j++;
                    min_i++;
                    break;

                default:
                    break;
                }
            direction = (direction + 1) % 4;

            }
        return v;
        }
    };

int main()
    {
    Solution o;
    vector<vector<int> > matrix{ {1,2,3, 4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
    vector<int> v = o.spiralOrder(matrix);
    for (auto a : v)
        {
        cout << a << "->";
        }
    }
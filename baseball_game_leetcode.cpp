/**
 * @file baseball_game_leetcode.cpp
 * @brief Solves the baseball game problem on LeetCode.
 * @see https://leetcode.com/problems/baseball-game/
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @class Solution
 * @brief Calculates the total score of a baseball game.
 * 
 * This class processes a list of operations in a baseball game and calculates the total score.
 */
class Solution {
private:
    /**
     * @brief Stores the record of scores.
     */
    vector<int> _record;
    /**
     * @brief Stores the total score.
     */
    int _score;

    /**
     * @brief Adds a new score to the record, which is the sum of the previous two scores.
     */
    void add() {
        int new_record = _record[_record.size() - 1] + _record[_record.size() - 2];
        _record.push_back(new_record);
    }

    /**
     * @brief Doubles the last score and adds it to the record.
     */
    void double_last() {
        int new_record = _record[_record.size() - 1] * 2;
        _record.push_back(new_record);
    }

    /**
     * @brief Removes the last score from the record.
     */
    void remove_last() {
        _record.pop_back();
    }

public:
    /**
     * @brief Calculates the total score based on a list of operations.
     * 
     * @param operations A vector of strings representing the operations to be performed.
     * @return The total score.
     */
    int calPoints(vector<string>& operations) 
    {
        int num;
        for (int i = 0; i < operations.size(); i++) 
        {
            if (operations[i] == "+") 
            {
                if (_record.size() < 2) {
                    continue;
                }
                add();
            } 
            
            else if (operations[i] == "D") 
            {
                if (_record.size() == 0) 
                {
                    continue;
                }
                double_last();
            } 
            
            else if (operations[i] == "C") 
            {
                if (_record.size() == 0) 
                {
                    continue;
                }
                remove_last();
            } 
            
            else 
            {
                num = stoi(operations[i]);
                if (num < -30000 || num > 30000) 
                {
                    continue;
                }
                _record.push_back(num);
            }
        }

        if (_record.size() == 0) 
        {
            _score = 0;
        } 
        
        else 
        {
            for (int i = 0; i < _record.size(); i++) {
                _score = _score + _record[i];
            }
        }
        return _score;
    }
};

/**
 * @brief Main function to test the Solution class.
 * @return 0 on successful execution.
 */
int main() 
{
    Solution s1;
    vector<string> ops = {"5", "2", "C", "D", "+"};
    cout << s1.calPoints(ops);
    cout << endl;
    return 0;
}

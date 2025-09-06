/**
 * @file valid-parentheses_leetcode.cpp
 * @brief Solution for the "Valid Parentheses" problem on LeetCode.
 * @details This file contains a class `Solution` that implements a stack-based
 * approach to determine if a string of parentheses is valid.
 */
#include <iostream>

using namespace std ;

/// @brief Maximum size of the character stack.
#define max_size 10000

/**
 * @class Solution
 * @brief Implements a solution for the "Valid Parentheses" problem.
 *
 * This class uses an internal stack to validate a string containing just the
 * characters '(', ')', '{', '}', '[' and ']'.
 */
class Solution {
    private :
        char _chars_stack [max_size] ; ///< Character array to implement the stack.
        int _top ;                     ///< Index of the top element of the stack.
        
        /**
         * @brief Checks if the stack is empty.
         * @return true if the stack is empty, false otherwise.
         */
        bool is_empty()
        {
            return _top == -1 ;
        }

        /**
         * @brief Checks if the stack is full.
         * @return true if the stack is full, false otherwise.
         */
        bool is_full()
        {
            return _top == max_size - 1 ;
        }

        /**
         * @brief Pushes a character onto the stack.
         * @param c The character to push.
         */
        void push(char c) 
        {   
            if(is_full())
            {
                cerr<<"stack is full\n" ;
                return ;
            }
            else
            {
                _top++ ;
                _chars_stack[_top] = c ;
            }
        }
        /**
         * @brief A specific wrapper to push an opening bracket.
         * @param c The opening bracket character to push.
         */
        void push_open_bracket(char c)
        {
            push(c) ;
        }
        /**
         * @brief Pops the top element from the stack.
         */
        void pop()
        {
            if(is_empty())
            {
                cerr<<"stack is empty\n" ;
                return ;
            }
            else
            {
                _top-- ;
            }
        }

    
    public :
        /**
         * @brief Construct a new Solution object.
         *
         * Initializes the stack to an empty state.
         */
        Solution()
        {
            _top = -1 ;
        }

        /**
         * @brief Determines if the input string has valid parentheses.
         * @param s The input string containing parentheses.
         * @return true if the string is valid, false otherwise.
         */
        bool isValid(string s)
        {
            for (int i = 0 ; i < s.length() ; i++)
            {
                if (s[i] == '(')
                {
                    push_open_bracket(s[i]) ;
                }

                else if(s[i] == '{')
                {
                    push_open_bracket(s[i]) ;
                }              
                
                else if(s[i] == '[')
                {
                    push_open_bracket(s[i]) ;
                }

                else if (s[i] == ')')
                {
                    if(is_empty() )
                    {
                        return false ;  
                    }

                    if (_chars_stack[_top] == '(')
                    {
                        pop() ;
                    }

                    else
                    {
                        return false ;
                    }
                }

                else if (s[i] == '}')
                {
                    if(is_empty())
                    {
                        return false ;  
                    }

                    if (_chars_stack[_top] == '{')
                    {
                        pop();
                    }

                    else
                    {
                        return false ;
                    }
                }

                else if (s[i] == ']')
                {
                    if(is_empty())
                    {
                        return false ;  
                    }

                    if (_chars_stack[_top] == '[' )
                    {
                        pop();
                    }

                    else
                    {
                        return false ;
                    }
                }   
            }
            
            if(is_empty())
            {
                return true ;
            }

            if(_chars_stack[_top] == '(' || _chars_stack[_top] == '[' || _chars_stack[_top] == '{' )
            {
                return false;
            }
            return true ;
        }
};

/**
 * @brief Main function to test the Solution class.
 * @return 0 on successful execution.
 */
int main() 
{
    Solution s1 ;
    s1.isValid("[([]])") ;
    cout<<endl ;
    return 0;
}
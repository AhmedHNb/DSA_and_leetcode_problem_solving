#include <iostream>

using namespace std ;

#define max_size 10000

class Solution {
    private :
        char _chars_stack [max_size] ;
        int _top ;
        int _bracket_Status;
        int _curle_bracket_Status;
        int _square_bracket_Status;
        int _closed ;
        
        int bracket_B_Status ;
        int bracket_C_Status ;
        int bracket_S_Status ;

        int curle_bracket_B_Status ;
        int curle_bracket_C_Status ;
        int curle_bracket_S_Status ;

        int square_bracket_B_Status ;
        int square_bracket_C_Status ;
        int square_bracket_S_Status ;

        bool is_empty()
        {
            return _top == -1 ;
        }

        bool is_full()
        {
            return _top == max_size - 1 ;
        }


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

        void push_open_bracket(char c)
        {   
            _bracket_Status = _bracket_Status + 1 ;
            bracket_B_Status = _bracket_Status ;
            bracket_C_Status = _curle_bracket_Status ;
            bracket_S_Status = _square_bracket_Status ;
            _closed = _closed + 1;
            push(c) ;
        }

        void push_open_curle_bracket(char c)
        {   
            _curle_bracket_Status = _curle_bracket_Status + 2 ;
            curle_bracket_B_Status = _bracket_Status ;
            curle_bracket_C_Status = _curle_bracket_Status ;
            curle_bracket_S_Status = _square_bracket_Status ;
            _closed = _closed + 2;
            push(c) ;
        }

        void push_open_square_bracket(char c)
        {   
            _square_bracket_Status = _square_bracket_Status + 3 ;
            square_bracket_B_Status = _bracket_Status ;
            square_bracket_C_Status = _curle_bracket_Status ;
            square_bracket_S_Status = _square_bracket_Status ;
            _closed = _closed + 3;
            push(c) ;
        }

    public:
        Solution()
        {
            _top = -1 ;
            _closed = 0 ;
            bracket_B_Status = 0 ;
            bracket_C_Status = 0 ;
            bracket_S_Status = 0 ;

            curle_bracket_B_Status = 0 ;
            curle_bracket_C_Status = 0 ;
            curle_bracket_S_Status = 0 ;

            square_bracket_B_Status = 0 ;
            square_bracket_C_Status = 0 ;
            square_bracket_S_Status = 0 ;
        }

        bool isValid(string s)
        {

            if (s.length() > max_size)
            {
                cerr<<"invalid input\n" ;
                return false ; 
            }
            
            for(int i = 0 ; i < s.length() ; i++)
            {
                if(s[i] == '(' ) 
                {   
                    push_open_bracket(s[i]) ;
                }

                else if(s[i] == '{')
                {
                    push_open_curle_bracket(s[i]) ;
                }

                else if (s[i] == '[')
                {
                    push_open_square_bracket(s[i]) ;
                }
                

                else if (s[i] == ')')
                {   
                    if(is_empty() || bracket_B_Status != _bracket_Status || bracket_C_Status != _curle_bracket_Status || bracket_S_Status != _square_bracket_Status)
                    {
                        return false ;
                    }

                    if (_chars_stack[_top] == '(' || _chars_stack[_top] == '}' || _chars_stack[_top] == ']' || _chars_stack[_top] == ')')
                    {
                        _bracket_Status = _bracket_Status - 1 ;
                        _closed = _closed - 1 ;
                        push(s[i]) ;
                    }

                    else
                    {
                        return false ;
                    }
                }

                else if (s[i] == '}')
                {
                    if(is_empty() || curle_bracket_B_Status != _bracket_Status || curle_bracket_C_Status != _curle_bracket_Status || curle_bracket_S_Status != _square_bracket_Status)
                    {
                        return false ;
                    }

                    if (_chars_stack[_top] == '{' || _chars_stack[_top] == ')' || _chars_stack[_top] == ']' || _chars_stack[_top] == '}')
                    {   
                        _curle_bracket_Status = _curle_bracket_Status - 2 ;
                        _closed = _closed - 2 ;
                        push(s[i]) ;
                    }

                    else
                    {
                        return false ;
                    }

                }

                else if(s[i] == ']')
                {
                    if(is_empty() || square_bracket_B_Status != _bracket_Status || square_bracket_C_Status != _curle_bracket_Status || square_bracket_S_Status != _square_bracket_Status)
                    {
                        return false ;
                    }

                    if(_chars_stack[_top] == '[' || _chars_stack[_top] == '}' || _chars_stack[_top] == ')' || _chars_stack[_top] == ']')
                    {
                        _square_bracket_Status = _square_bracket_Status - 3 ;
                        _closed = _closed - 3 ;
                        push(s[i]) ;
                    }

                    else
                    {
                        return false ;
                    }
                }
                
            }
            
            if(_chars_stack[_top] == '(' || _chars_stack[_top] == '[' ||_chars_stack[_top] == '{' || _closed != 0)
            {
                return false ;
            }
            return true ;
        }

        void print_stack()
        {
            for(int i = 0 ; i <= _top ; i++)
            {
                cout<<_chars_stack[i] ;
            }
        }
};

int main() 
{
    Solution s1 ;
    s1.isValid("(([]){})") ; //id
    s1.print_stack() ;
    cout<<endl ;
    return 0;
}
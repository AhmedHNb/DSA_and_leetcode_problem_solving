#include <iostream>

using namespace std ;

#define max_size 10000

class Solution {
    private :
        char _chars_stack [max_size] ;
        int _top ;
        int _closed ;
        int _bracket_status ;
        int _curle_bracket_status ;
        int _square_bracket_status ;

        

        bool is_empty()
        {
            return _top == -1 ;
        }

        bool is_full()
        {
            return _top == max_size - 1 ;
        }

        void push_open_bracket(char c)
        {
            push(c) ;
        }

    
    public :
        Solution()
        {
            _top = -1 ;
            _closed = 0 ;
            _bracket_status = 0 ;
            _curle_bracket_status = 0 ;
            _square_bracket_status = 0 ;
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

        bool isValid(string s)
        {
            for (int i = 0 ; i < s.length() ; i++)
            {
                if (s[i] == '(')
                {
                    _bracket_status = _bracket_status + 1 ;
                    _closed = _closed + 1 ;
                    push_open_bracket(s[i]) ;
                }

                else if(s[i] == '{')
                {
                    _curle_bracket_status = _curle_bracket_status + 1 ;
                    _closed = _closed + 2 ;
                    push_open_bracket(s[i]) ;
                }              
                
                else if(s[i] == '[')
                {
                    _square_bracket_status = _square_bracket_status + 1 ;
                    _closed = _closed + 3 ;
                    push_open_bracket(s[i]) ;
                }

                else if (s[i] == ')')
                {
                    if(is_empty() || _bracket_status != 0 || _curle_bracket_status != 0 || _square_bracket_status != 0)
                    {
                        return false ;  
                    }

                    if (_chars_stack[_top] == '(' || _chars_stack[_top] == '}' || _chars_stack[_top] == ']' || _chars_stack[_top] == ')')
                    {
                        _bracket_status = _bracket_status - 1 ;
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
                    if(is_empty() || _bracket_status != 0 || _curle_bracket_status != 0 || _square_bracket_status != 0)
                    {
                        return false ;  
                    }

                    if (_chars_stack[_top] == '{' || _chars_stack[_top] == ')' || _chars_stack[_top] == ']' || _chars_stack[_top] == '}')
                    {
                        _curle_bracket_status = _curle_bracket_status - 1 ;
                        _closed = _closed - 2 ;
                        push(s[i]) ;
                    }

                    else
                    {
                        return false ;
                    }
                }

                else if (s[i] == ']')
                {
                    if(is_empty() || _bracket_status != 0 || _curle_bracket_status != 0 || _square_bracket_status != 0)
                    {
                        return false ;  
                    }

                    if (_chars_stack[_top] == '[' || _chars_stack[_top] == '}' || _chars_stack[_top] == ')' || _chars_stack[_top] == ']')
                    {
                        _square_bracket_status = _square_bracket_status - 1 ;
                        _closed = _closed - 3 ;
                        push(s[i]) ;
                    }

                    else
                    {
                        return false ;
                    }
                }   
            }
            if(_closed != 0 || _chars_stack[_top] == '(' || _chars_stack[_top] == '{' || _chars_stack[_top] == '[')
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
            cout<<endl ;
            cout << _closed ;
        }
};

int main() 
{
    Solution s1 ;
    s1.isValid("[([]])") ;
    s1.print_stack() ;
    cout<<endl ;
    return 0;
}
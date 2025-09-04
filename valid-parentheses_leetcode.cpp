#include <iostream>

using namespace std ;

#define max_size 10000

class Solution {
    private :
        char _chars_stack [max_size] ;
        int _top ;
        int _closed ;

    public:
        Solution()
        {
            _top = -1 ;
            _closed = 0 ;
        }

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
                    _closed = _closed + 1;
                    push(s[i]) ;
                }

                else if(s[i] == '{')
                {
                    _closed = _closed + 2;
                    push(s[i]) ;
                }

                else if (s[i] == '[')
                {
                    _closed = _closed + 3;
                    push(s[i]) ;
                }
                

                else if (s[i] == ')')
                {   
                    if(is_empty())
                    {
                        return false ;
                    }

                    if (_chars_stack[_top] == '(' || _chars_stack[_top] == '}' || _chars_stack[_top] == ']' || _chars_stack[_top] == ')')
                    {
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
                    if(is_empty())
                    {
                        return false ;
                    }
                    if (_chars_stack[_top] == '{' || _chars_stack[_top] == ')' || _chars_stack[_top] == ']' || _chars_stack[_top] == '}')
                    {
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
                    if(is_empty())
                    {
                        return false ;
                    }

                    if(_chars_stack[_top] == '[' || _chars_stack[_top] == '}' || _chars_stack[_top] == ')' || _chars_stack[_top] == ']')
                    {
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
    s1.isValid("[([]])") ; //id
    s1.print_stack() ;
    cout<<endl ;
    return 0;
}
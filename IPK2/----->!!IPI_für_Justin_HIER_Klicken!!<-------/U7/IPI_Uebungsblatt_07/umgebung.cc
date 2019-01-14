int g = 0;

int a_mod_b( int a, int b )
{
    int m = a % b; 
    return m; //1
}

int ggT( int a, int b )
{
    g = g + 1;
    int Null = 0;
    if ( b == Null )
        return a; //2
    else
        return ggT( b, a_mod_b( a, b ) );
}

int main( void )
{
    int a = 2;
    int b = 14;
    {
        int a = 7;
        int g = ggT( b, a );
        b = g;
    }
    a = g;
    return 0; //3
}

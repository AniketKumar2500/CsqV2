#if !defined(TOKEN_H)
#define TOKEN_H
    // using namespace std;
    //Tokens functions
    #define var auto
    #define def auto
    #define lam =[]

    #define constructor(classname) classname
    #define as =
    //Related to operator overloading
    #define __add__ def operator +
    #define __gt__ def operator >
    #define __lt__ def operator <
    #define __equal__ def operator ==
    #define __assign__ def operator =
    #define __subt__ def operator -
    #define __mul__ def operator *
    #define __div__ def operator /
    #define __pow__ def operator ^
    #define __powassign__ def operator ^=
    #define __brac__ def operator []
    #define __cbrac__ def operator ()
    #define __gteq__ def operator >=
    #define __lteq__ def operator <=
    #define __noteq__ def operator !=
    #define __addassign__ def operator +=
    #define __subtassign__ def operator -=
    #define __mulassign__ def operator *=
    #define __divassign__ def operator /=
    #define __increment__ def operator ++
    #define plus +
    #define minus -
    #define multiply *
    #define divide /
    #define mod %
    #define be =
    #define when if(
    #define so )
    #define starts {
    #define ends };
    #define rather else if(
    #define altern else
    // #define call 
    ///////////////for OOPs////////////////
    #define inherits :
    #define pub  public:
    #define priv private:
    #define prot protected:
#endif // TOKEN_H
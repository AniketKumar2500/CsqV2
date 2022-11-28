#if !defined(IO_H)
#define IO_H
    #include "dict.h"
    def tostr(str s){return s;}
        def tostr(int i){return to_str(i);}
        def tostr(double i){return to_str(i);}
        def tostr(long double i){return to_str(i);}
        def tostr(array<int> arr){
            str s;
            for(var i : arr){
                s+=to_str(i)+",";
            }
            return s;
        }
        def tostr(array<str> arr){
            str s;
            for(var i : arr){
                s+=to_str(i)+",";
            }
            return s;
        }
        def tostr(array<double> arr){
            str s;
            for(var i : arr){
                s+=to_str(i)+",";
            }
            return s;
        }
        def tostr(array<long double> arr){
            str s;
            for(var i : arr){
                s+=to_str(i)+",";
            }
            return s;
        }
        def tostr(dict<str,int> d){
            return d.readall();
        }
        def tostr(dict<str,double> d){
            return d.readall();
        }
        def tostr(dict<str,str> d){
            return d.readall();
        }
        def tostr(dict<int,int> d){
            return d.readall();
        }
        def tostr(dict<int,double> d){
            return d.readall();
        }
        def tostr(dict<int,str> d){
            return d.readall();
        }
        def tostr(dict<double,int> d){
            return d.readall();
        }
        def tostr(dict<double,double> d){
            return d.readall();
        }
        def tostr(dict<double,str> d){
            return d.readall();
        }
        def tostr(dict<int,long double> d){
            return d.readall();
        }
        def tostr(dict<str,long double> d){
            return d.readall();
        }
        def tostr(dict<double,long double> d){
            return d.readall();
        }
        def tostr(array<array<str>> arr){
            str s = "(";
            for(var i : arr){
                s+="{";
                for(var j : i){
                    s += j + ", ";
                }
                s+="},";
            }
            return s;
        }
        def tostr(dict<str,array<str>> d){
            str s = "{\n";
            for(int i=0;i<d.keys.len();i++){
                s += to_str(d.keys[i]) + ":[";
                s += to_str(tostr(d.values[i]))+"],\n";
            }
            return str(s+"}");
        }
        def tostr(dict<str,array<int>> d){
            str s = "{\n";
            for(int i=0;i<d.keys.len();i++){
                s += to_str(d.keys[i]) + ":[";
                s += to_str(tostr(d.values[i]))+"],\n";
            }
            return str(s+"}");
        }
        def tostr(dict<str,array<double>> d){
            str s = "{\n";
            for(int i=0;i<d.keys.len();i++){
                s += to_str(d.keys[i]) + ":[";
                s += to_str(tostr(d.values[i]))+"],\n";
            }
            return str(s+"}");
        }

        def tostr(basic_array<str> arr){
            array<str> arr2;
            for(var i : arr){
                arr2 += i;
            }
            return tostr(arr2);
        }

        def tostr(long unsigned int val){
            return to_str(val);
        }
    template<typename T>
    def println(T t){
        printf("%s\n",tostr(t).Str);
    }
    template<typename T,typename... Args>
    def println(T t,Args... args){
        printf("%s\n",tostr(t).Str);
        println(args...);
    }
    template<typename T>
    def print(T t){
        printf("%s",tostr(t).Str);
    }
    template<typename T,typename... Args>
    def print(T t,Args... args){
        printf("%s",tostr(t).Str);
        print(args...);
    }

    //Function to take input
    str input(str prompt = ""){
        printf("%s",prompt.Str);
        char i[500000];
        scanf("%[^\n]s",i);
        return str(i);
    }
#endif // IO_H
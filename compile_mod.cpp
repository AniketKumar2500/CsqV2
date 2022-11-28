#include "utils/str.h"
#include "utils/array.h"
#include "utils/code_manup.h"
#include "utils/file_hand.h"
#include "utils/IR.h"
//Intermediate code conversion::
str IR_Mod(basic_array<str> code){
    str imports,code_;
    int ln = 1;
    for(str& i : code){
        if(find_str(i.Str,str("import").Str)!=0 && find_str(i.Str,str(".").Str) == 0 && find_str(i.Str,str("//").Str)==0){
            replace(i.Str,str("import ").Str,(str("#include \"")).Str);
            i.pop_bk();
            i+=".csqm\"";
            imports += i;
            imports += "\n";
        }
        else if(find_str(i.Str,str("import").Str)!=0 && find_str(i.Str,str(".").Str) != 0 && find_str(i.Str,str(".csqm").Str) != 0 && find_str(i.Str,str("//").Str)==0){
            printf("\033[31mTrackback:\nAt line:%d includes import statement with .csqm extension which is not needed just write without extension or use #include.",ln);
            //abort();
        }
        else if(find_str(i.Str,str("import").Str)!=0 && find_str(i.Str,str(".").Str) != 0 && find_str(i.Str,str("//").Str)==0){
            replace(i.Str,str("import ").Str,(str("#include \"")).Str);
            replace(i.Str,str(".").Str,(str("/")).Str);
            i.pop_bk();
            i+=".csqm\"";
            imports += i;
            imports += "\n";
        }
        
        else if(find_str(i.Str,str("//").Str)==1){}
        else{
            code_ += i;
        }
        ln++;
    }
    str new_code = imports+code_;
    return new_code;
}

int main(int argc, char const *argv[])
{
    if(argc < 4){
        printf("Please provide\n <name> <path> <current-dir>\n");
        abort();
    }
    generate_IR_file(argv[3],argv[1],IR_Mod(read(argv[2])));

    return 0;
}
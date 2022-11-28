#if !defined(IR_H)
#define IR_H

    #include "file_hand.h"
    #include "code_manup.h"

    //Intermediate code conversion::
    str IR(basic_array<str> code, str compiler_path){
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
            else if(find_str(i.Str,str("#include").Str)!=0  && find_str(i.Str,str("//").Str)==0){
                imports += i;
                imports += "\n";
            }
            else if(find_str(i.Str,str("for").Str) == 0 && find_str(i.Str,str("class").Str) == 0 && find_str(i.Str,str("#include").Str) == 0 && find_str(i.Str,str("//").Str) == 0 && find_str(i.Str,str(";").Str) == 0){
                code_ += i;
                code_ += ";";
            }
            else{
                code_ += i;
            }
            ln++;
        }
        str new_code = "#include \"";
        new_code += compiler_path + "/Modules/fmt/builtins.csqm\"\n";
        new_code += imports;
        new_code += "int main(){\n";
        new_code += code_;
        new_code += "\nreturn 0;}";
        return new_code;
    }

    void generate_IR_file(str current_dir, str name, str code){
        write((current_dir+name+".csqm").Str,code);
    }

#endif // IR_H

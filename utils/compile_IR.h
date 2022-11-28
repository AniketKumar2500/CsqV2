#if !defined(COMPILE_IR_H)
#define COMPILE_IR_H

    #include "str.h"
    #include "file_hand.h"
    str read(str file_path){
        char ln[1000];
        FILE *f = NULL;
        // str ret;
        str ret;
        f = fopen(file_path.Str,"r+");

        if(f == NULL){
            /*If file opening fails return from here itself*/
            printf("Error, Can't open file\n");
        }

        /*File is opened. Start reading the file line by line*/
        while ( fgets ( ln, 1000, f) != NULL )
        {
            ret+=str(ln)+"\n";
        }
        /*close the file*/
        fclose (f);
        return ret;
    }
    void compile_IR(str current_path, str path, str name){
        str code = read(path);
        write((current_path+name+".cpp").Str,code);
        str command = "cd ";
        command += current_path;
        command += " && clang++ ";
        command += current_path+name+".cpp -o ";
        command += name;
        system(command.Str);
        system((str("rm ")+current_path+name+".cpp").Str);
    }

#endif // COMPILE_IR_H

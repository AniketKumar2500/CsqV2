#include "utils/IR.h"
#include "utils/compile_IR.h"
void run(str current_dir, str name){
    system((str("cd ")+current_dir+str("&& ./")+name + str(" && mv ")+name+str(" ")+name+"so").Str);
}
// Driver code
int main(int argc, char const *argv[])
{
    if(argc < 4){
        printf("Need 3 arguments <name> <path> <current-dir> <compiler_path> \n");
        abort();
    }
    else{
        str IR_code = IR(read(argv[2]),argv[4]);
        generate_IR_file(argv[3],argv[1],IR_code);
        compile_IR(argv[3],str(argv[3])+str(argv[1])+".csqm",argv[1]);
        run(argv[3],argv[1]);
    }
    
    // str s = .arr[0];
    // replace(s.Str,str("import").Str,str("#include").Str);
    // generate_IR_file("/media/aniket/disk/CsqTest/test/","hi",IR(read("/media/aniket/disk/CsqTest/test/hi.csq"),"/media/aniket/disk/CsqTest/"));
    // // printf("%s\n",IR(read("hi.csq"),"f").Str);
    // compile_IR("/media/aniket/disk/CsqTest/test/","/media/aniket/disk/CsqTest/test/hi.csqm","hi");
    return 0;
}
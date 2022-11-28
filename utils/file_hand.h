#if !defined(FILE_HAND_H)
#define FILE_HAND_H

    #include "str.h"
    #include "array.h"
    //READ FUNCTION FOR READING THE SOURCE FILE
    basic_array<str> read(const char* file_name){
        char ln[1000];
        FILE *f = NULL;
        // str ret;
        basic_array<str> ret;
        f = fopen(file_name,"r+");

        if(f == NULL){
            /*If file opening fails return from here itself*/
            printf("Error, Can't open file\n");
        }

        /*File is opened. Start reading the file line by line*/
        while ( fgets ( ln, 1000, f) != NULL )
        {
            ret.push(ln);
        }
        /*close the file*/
        fclose (f);
        return ret;
    }

    void write(const char* path,str code){
        FILE* file;
        file = fopen(path, "w") ;
        
        // Check if this filePointer is null
        // which maybe if the file does not exist
        if ( file == NULL )
        {
            printf( "failed to open." ) ;
        }
        else{    
            // Write the dataToBeWritten into the file
            fputs(code.Str,file);
            fclose(file);
        }
    }

#endif // FILE_HAND_H
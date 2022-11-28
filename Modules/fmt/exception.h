#if !defined(EXCEPTION_H)
#define EXCEPTION_H

    #include "io.h"
    #include<stdlib.h>
    #include<stdio.h>
    namespace warning{

    }
    def warn(const char* ch){
        printf("\n\033[33m Warning : %s \033[0m",ch);
    }
    #if defined(STR_H)
        //This function shows an error and terminate the program.
        def error(str class_,str err){
            print("\033[31m","fatal exception thrown by class \033[0m",class_," : ",err);
            exit(EXIT_FAILURE);
        }
        namespace exception{
                //This class will throw return an exception when division with zero occured.
                class division_by_zero{
                    public: 
                        def get_error(){
                            error("division_by_zero","can't perform division by zero :(");
                        }
                };
                //This class will throw return an exception when index not found in any collection.
                class index_bound{
                    public:
                        def get_error(){
                            error("index_invalid","index out of the collection, used index not belongs to the object😵");
                        }
                };
        };

        //This function will raise the exception but note that you have to pass an object of any exception class and have to overide if you created a new one.
        //overloading for division_by_zero exception.
        def raise(exception::division_by_zero ex_div_zero){
            ex_div_zero.get_error();
        }
        //overloading for index_invalid exception.
        def raise(exception::index_bound exc){
            exc.get_error();
        } 
    #elif !defined(STR_H)
        //This function shows an error and terminate the program.
        def error(const char* class_,const char* err){
            printf("\033[31m fatal exception thrown by class %s : %s \033[0m",class_,err);
            exit(EXIT_FAILURE);
        }
        namespace exception{
                //This class will throw return an exception when division with zero occured.
                class division_by_zero{
                    public: 
                        def get_error(){
                            error("division_by_zero","can't perform division by zero :(");
                        }
                };
                //This class will throw return an exception when index not found in any collection.
                class index_bound{
                    public:
                        def get_error(){
                            error("index_invalid","index out of the collection index, not belongs to the object😵");

                        }
                };
        };

        //This function will raise the exception but note that you have to pass an object of any exception class and have to overide if you created a new one.
        //overloading for division_by_zero exception.
        def raise(exception::division_by_zero ex_div_zero){
            ex_div_zero.get_error();
            // exit(EXIT_FAILURE);
        }
        //overloading for index_invalid exception.
        def raise(exception::index_bound exc){
            exc.get_error();
            // exit(EXIT_FAILURE);
        }
    #endif
#endif // EXCEPTION_H

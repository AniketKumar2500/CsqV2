/**
 * @file array.h
 * @author Aniket Kumar (geek.aniket.coder@gmail.com)
 * @brief A module which helps in creation of dynamic array.
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#if !defined(ARRAY_H)
#define ARRAY_H
    #include "../token.h"
    #include "exception.h"
    // #include
    #include "str.h"
    #include <initializer_list>


    //Exception for dframe class.
    namespace exception{
        class data_len_exception{
            public:
                def get_exc(){
                    error("data_len_exception","Data len unequal or data in columns is not of same length😵");
                    // return exc;
                }
        };
    }
    //override for dframe errors.
    def raise(exception::data_len_exception dle){
        dle.get_exc();
    }
    
    //This is the class which have the features of dynamic array.
    template<typename T>
    class basic_array{
         public:
            T* arr;
            // capacity is the total storage
            int capacity;
            // current is the number of elements
            int current;
         public:
            constructor(basic_array)(){
                arr = new T[1];
                capacity = 1;
                current = 0;
            }
            def update(int index, T value){
                arr[index] = value;
            }
            def push(T data){
                // if the number of elements is equal to the
                // capacity, that means we don't have space to
                // accommodate more elements. We need to double the
                // capacity
                if (current == capacity) {
                    T* temp = new T[2 * capacity];
        
                    // copying old array elements to new array
                    for (int i = 0; i < capacity; i++){
                        temp[i] = arr[i];
                    }
        
                    // deleting previous array
                    delete[] arr;
                    capacity *= 2;
                    arr = temp;
                }
                // Inserting data
                arr[current] = data;
                current++;
            }
            __brac__(int index){
                return this->arr[index];
            }
            def erase(T e){
                int i;
                for (i=0; i<this->current; i++)
                    if (this->arr[i] == e)
                        break;
                // If element found in array
                if (i < this->current)
                {
                    // reduce size of array and move all
                    // elements on space ahead
                    this->current = this->current - 1;
                    for (int j=i; j<this->current; j++)
                        arr[j] = arr[j+1];
                }
            }
            def pop(){current--;}
            T* begin() { return &this->arr[0];}
            const T* begin() const { return &this->arr[0];}
            T* end() { return &this->arr[this->current]; }
            const T* end() const { return &this->arr[this->current];}
            // ~basic_array(){delete[] arr;}
    };//basic_array

    /*This class is extended version for basic_array class, this class own many features which can be used to work with dynamic array easily. but note array are not dynamic but as i like the name array i named it array.*/
    template<typename T>
    class array{
         private:
            def abs(double value){
                double nv = value;
                if(value < 0){
                    nv = nv*(-1);
                }
                return nv;
            }
         public:
            basic_array<T> arr;
         public:
            array(){}
            array(std::initializer_list<T> il){
                for(var i : il){
                    this->arr.push(i);
                }
            }
            array(const array<T>& arr){
                for(var i : arr){
                    this->arr.push(i);
                }
            }  
            array(T arr[],int size){
                for(int i=0;i<(size);i++){
                    this->arr.push(arr[i]);
                }
            }
            //Iterators for for each loop.
            T* begin() { return &this->arr.arr[0];}
            const T* begin() const { return &this->arr.arr[0];}
            T* end() { return &this->arr.arr[this->arr.current]; }
            const T* end() const { return &this->arr.arr[this->arr.current];}
            //This method returns the length of the array.
            def len(){return this->arr.current;}
            //Reading data
            def operator[](int index){
                T ret;
                if(index<arr.current){
                    ret = arr[index];
                }
                else{
                    raise(exception::index_bound());
                }
                return ret;
            }
            //Adding data
            def operator+=(T element){arr.push(element);}
            def operator=(array<T> arr){
                for(int i = 0; i<arr.len();i++){
                   this->arr.push(arr[i]);
                }
            }
            def operator==(array<T> arr){
                bool state = 1;
                for(int i=0;i<arr.len();i++){
                    if(this->arr[i]!=arr[i]){state = 0;}
                }
                return state;
            }
            def add(T element){arr.push(element);}
            template<typename... Args>
            def add(T e1,Args... args){
                arr.push(e1);
                add(args...);
            }
            //Operator for slicing
            __cbrac__(int from,int till,int steps=1){
                array<T> n;
                for(int i=from-1;i<till;i+=steps){
                    n.add(this->arr[i]);
                }
                return n;
            }
            __cbrac__(int till,int steps=1){
                array<T> n;
                for(int i=0;i<till;i+=steps){
                    n.add(this->arr[i]);
                }
                return n;
            }
            //This method will allocate the memory.
            def allocate(int size){
                arr.capacity = size;
                arr.current = size;
            }
            //Update data
            def update(int index,T element){
                if(index > arr.current){
                    raise(exception::index_bound());
                }
                else{
                    arr.update(index,element);
                }
            }
            //This method returns the count of the element inside the array.
            def count(T element){
                int count = 0;
                for(int i = 0; i < this->arr.current; i++){
                    switch (this->arr[i] == element)
                    {
                        case 1:
                            count++;
                        case 0:
                            continue; 
                    }
                }
                return count;
            }
            //This method returns the sum of all elements in the array.
            def sum(){
                T sum_ = 0;
                for(var i : this->arr){
                    sum_ += i;
                }
                return sum_;
            }
            //This method returns the product of all elements in the array.
            def product(){
                T product_ = 1;
                for(var i : this->arr){
                    product_ = product_ * i;
                }
                return product_;
            }
            //This method returns the mean of all elements in the array.
            def mean(){
                return this->sum()/this->arr.current;
            }
            //This method sorts the array in ascending order.
            def sort(){
                for (int j = 0; j < this->arr.current - 1; j++)
                    {
                        // Checking the condition for two
                        // simultaneous elements of the array
                        if (arr[j] > arr[j + 1])
                        {
                            // Swapping the elements.
                            T temp = arr[j];
                            arr.update(j,arr[j + 1]);
                            arr.update(j + 1,temp);
                            
                            // updating the value of j = -1
                            // so after getting updated for j++
                            // in the loop it becomes 0 and
                            // the loop begins from the start.
                            j = -1;
                        }
                    }
            }
            //This method returns the median of all elements in the array
            def median(){
                this->sort();
                // the variable which holds the magnitude of median
                double med;
                /*if number of elements is even then formula
                median = ((n/2)th + (n/2+1)th)/2*/
                if(this->arr.current % 2 == 0){
                    med = (arr[(this->arr.current/2)]+arr[(this->arr.current/2)-1])/2.0;
                }
                //else number of elements is odd so formula n+1/2 th term.
                else{
                    med = arr[((arr.current+1)/2)-1];
                }
                //returning the median.
                return med;
            }

            //This method let you know the maximum value in the array.
            def max(){
                //assume that the maximum value is at arr[0];
                T max__= this->arr[0];
                //for each loop to work with every element.
                for(var i : arr){
                    if(i > max__){
                        max__ = i;
                    }
                }
                //returning the maximum value.
                return max__;
            }
            //This method let you know the minimum value in the array.
            def min(){
                //assume that the minimum value is at arr[0];
                T max__= this->arr[0];
                //for each loop to work with every element.
                for(var i : arr){
                    if(i < max__){
                        max__ = i;
                    }
                }
                //returning the minimum value.
                return max__;
            }
            //This method let you know the mode magnitude of the array.
            def mode(){
                array<int> e2;
                //Assigning counts of elements to the new array.
                for(var i : arr){
                    e2.add(this->count(i));
                }
                T ret;
                for(int i=0;i<e2.len();i++){
                    //Getting at what the element is equal to max count.
                    if(e2[i] == e2.max()){
                        ret = arr[i];
                    }
                }
                return ret;
            }
            //This method pop the elements.
            def pop(){return this->arr.pop();}
            //This method erase the given element from the array.
            def erase(T element){
                this->arr.erase(element);
            }

            //This method returns an array of indexes on which the given element is present.
            def find(T element){
                array<int> index;
                for(int i=0;i<this->len();i++){
                    if(this->arr[i] == element){
                        index.add(i);
                        // break;
                    }
                }
                return index;
            }
            //This method replaces the occurence of element in the array.
            def replace(T real_element, T new_element){
                for(int i=0;i<this->arr.current;i++){
                    if(this->arr[i] == real_element){
                        this->arr.update(i,new_element);
                    }
                }
            }

            //Typecasting array to int
            //But only works for str to int conversion.
            // def toint(){
            //     array<int> arr;
            //     for(var i : this->arr){
            //         arr.add(toint(str(i)));
            //     }
            //     return arr;
            // }
            //But only works for str to double conversion.
            def todouble(){
                array<double> arr;
                for(var i : this->arr){
                    arr.add(to_double(i));
                }
                return arr;
            }
            //This method converts numeric array to str array.
            def tostr(){
                array<str> ret;
                for(var i : arr){
                    ret.add(to_str(i));
                }
                return ret;
            }

            /*NaN value handling*/

            /**
             * @brief This method returns an array in which all NaN values are replaced.
             * @param substr The substr which will be placed in the array where NaN values are.
             * @param notation This param is made to find how NaN values are represented by default it's NaN.
             */
            def fillna(str subtr,str notation = "NaN"){
                array<T> a;
                for(var i : arr){
                    a += i;
                }
                for(int i=0;i<a.len();i++){
                    if(a[i] == notation){
                        a.update(i,subtr);
                    }
                }
                return a;
            }
            /**
             * @brief This method returns the count of null values in the array.
             * @param notation The notation to be counted by default it is NaN.
             */
            def isnull(str notation = "NaN"){
                int len = 0;
                for(var i : this->arr){
                    if(i == notation){
                        len++;
                    }
                }
                return len;
            }
            //This method will return unique values.
            def unique(){
                int res = 1;
                array<T> e;
                // Pick all elements one by one
                for (int i = 0; i < this->len(); i++) {
                    int j = 0;
                    for (j = 0; j < i; j++)
                        if (arr[i] == arr[j])
                            break;

                    // If not printed earlier, then print it
                    if (i == j)
                        e.add(arr[i]);
                }
                return e;
            };
    };// array

#endif // ARRAY_
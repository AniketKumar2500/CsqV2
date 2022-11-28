#if !defined(ARRAY_H)
#define ARRAY_H

    template<typename T>
    class basic_array{
        public:
            T* arr;
            
            // capacity is the total storage
            int capacity;
            // current is the number of elements
            int current;
        public:
            basic_array(){
                arr = new T[1];
                capacity = 1;
                current = 0;
            }
            void push(T data){
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
            // auto operator[](int index){
            //     return this->arr[index];
            // }
            void pop(){current--;}
            int len(){return current;}
            T* begin() { return &this->arr[0];}
            const T* begin() const { return &this->arr[0];}
            T* end() { return &this->arr[this->current]; }
            const T* end() const { return &this->arr[this->current];}
            // ~basic_array(){delete[] arr;}
    };
#endif // ARRAY_H
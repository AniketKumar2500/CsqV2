#if !defined(DICT_H)
#define DICT_H
    #include "array.h"
    //Exception for key not found.
    namespace exception{
        class KeyNoWhere{
            public:
                KeyNoWhere(){}
                def get(){
                    error("KeyNoWhere","Key not found in the dict.");
                }
        };
    }
    //overloading raise function
    def raise(exception::KeyNoWhere knw){
        knw.get();
    }
    //This class stores data in the form of key-value pair same as map.
    template<typename K,typename V>
    class dict{
        public:
            array<K> keys;
            array<V> values;
            //Constructors
            dict(){}
            constructor(dict)(array<K> keys,array<V> values){
                this->keys = keys;
                this->values = values;
            }
            //This operator reads the value on the basis of key.
            def operator[](K key){
                V val;
                bool in__ = false;
                for(int i=0;i<this->keys.len();i++){
                    if(key == this->keys[i]){
                        val = this->values[i];
                        in__ = true;
                        break;
                    }
                }
                if(in__ == false){
                    raise(exception::KeyNoWhere());
                }
                return val;
            }
            def operator=(dict<K,V> d){
                this->keys = d.keys;
                this->values = d.values;
            }
            //This method adds the pair.
            def add(K key,V val){keys.add(key),values.add(val);}
            //This method updates the value.
            def update(K key,K val){
                bool there = 0;
                for(int i=0;i<keys.len();i++){
                    if(key == keys[i]){
                        values.update(i,val);
                        there = 1;
                    }
                }
                if(there == 0){
                    keys.add(key);
                    values.add(val);
                }
            }
            //This method returns a str representation of the dictionary
            def readall(){
                str s = "{ ";
                for(int i=0;i<this->keys.len();i++){
                    s += to_str(keys[i]) + ":";
                    s += to_str(values[i])+",";
                    s += " ";
                }
                return str(s+"}");
            }

            def pop(){
                this->keys.pop();
                this->values.pop();
            }
    };
#endif // DICT_H

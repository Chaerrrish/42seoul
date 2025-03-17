#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

typedef struct s_data {
	char    data_char;
	int	    data_int;
}   Data;


class Serializer {
    private : 
        Serializer();
        Serializer(const Serializer& Serializer);
        Serializer& operator=(const Serializer& Serializer);
    
    public:
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
       static Data* deserialize(uintptr_t raw);

};

#endif
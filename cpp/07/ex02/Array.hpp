#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
    private:
        T*  array;
        unsigned int len;

    public:
        Array() : len(0)
        {
            array = new T[len];
            std::cout << "Array :: default Constructor called" << std::endl;
        }

        Array(unsigned int n) : len(n)
        {
            array = new T[len];
            std::cout << "Array :: Constructor called" << std::endl;
        }

        Array(const Array& Array)
        {
            len = Array.size();
            array = new T[len];
            for (unsigned int i=0; i<len; i++)
                array[i] = Array.array[i];
            std::cout << "Array :: Copy Constructor called" << std::endl;
        }

        Array& operator=(const Array& Array)
        {
            if (this != &Array)
            {
                delete[] array;
                len = Array.size();
                array = new T[len];
                for (unsigned int i=0; i<len; i++)
                    array[i] = Array.array[i];
            }
            std::cout << "Array :: Copy assignment operator called" << std::endl;
            return *this;
        }

        ~Array()
        {
            std::cout << "Array :: Destructor called" << std::endl;
            delete[] array;
        }

        T& operator[] (unsigned int idx)
        {
            if (idx < 0 || idx >= len)
                throw std::exception();
            return array[idx];
        }

        const T& operator[] (unsigned int idx) const
        {
            if (idx < 0 || idx >= len)
                throw std::exception();
            return array[idx];
        }

        size_t size(void) const
        {
            return len;
        }
};

#endif
#include "Serializer.hpp"

int main() {
    Data data;
    data.data_char = 'S';
    data.data_int = 42;

    std::cout << "[ data_char ] : " << data.data_char << std::endl;
    std::cout << "[ data_int ] : " << data.data_int << "\n\n";
    std::cout << "[ Before Serialization ] : " << &data << "\n\n";

    uintptr_t serialize = Serializer::serialize(&data);
    std::cout << std::hex << "[ After Serialization (Hex) ] : " << serialize << std::endl;

    Data *deserialize = Serializer::deserialize(serialize);
    std::cout << "[ After Deserialization ] : " << deserialize << std::endl;
    std::cout << "[ deserialize data_char ] : " << deserialize->data_char << std::endl;
    std::cout << std::dec << "[ deserialize data_int ] : " << deserialize->data_int << std::endl;

    if (deserialize == &data)
        std::cout << "✅ Success: Pointers match!" << std::endl;
    else
        std::cout << "❌ Error: Pointers do not match!" << std::endl;

    return 0;
}

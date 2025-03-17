#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>\n";
        return 1;
    }

    BitcoinExchange exchange("data.csv"); // 비트코인 환율 데이터 로드
    exchange.processInputFile(argv[1]);   // 입력 파일 처리

    return 0;
}

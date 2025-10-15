#include "freqCounter.cpp"
#include "initializer.cpp"
#include <fstream>

void writeTable(const std::unordered_map<std::string, size_t>& map){
    std::ofstream outfile;

    outfile.open("FreqTable.txt");

    if(outfile.is_open()){
        for (const auto& par : map) {
            outfile << par.first << ": " << par.second << std::endl;
        }
    }
    outfile.close();
}

int main(int argc, char *argv[]){
    initializer* init = new initializer();
    freqCounter* counter = new freqCounter();

    init->check_amount_of_inputs(argc);

    if (init->ready_to_read){
        auto freqtable = counter->readFile(argv[1]);
        writeTable(freqtable);
        std::cout << "Created Frequency Table!";
    }



    return 0;

}
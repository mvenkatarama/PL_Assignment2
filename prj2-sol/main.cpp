#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{   
    if(argc != 3) {
        std::cout << "argc : "+to_string(argc)+"\n";
        std::cout << "Usage: ./<program_name> <N_OPS> <N_ENTRIES>\n";
        return 1;
    }

    int N_OPS = atoi(argv[1]);
    int N_ENTRIES = atoi(argv[2]);

    // std::cout << N_OPS << "\n";
    // std::cout << N_ENTRIES << "\n";

    int arr1[N_ENTRIES], arr2[N_ENTRIES], result[N_ENTRIES];


    for(int i=0; i<N_OPS; i++) {
        for(int j=0; j<N_ENTRIES; j++) {
            std::cin >> arr1[j];
        }
        for(int j=0; j<N_ENTRIES; j++) {
            std::cin >> arr2[j];
        }
        for(int j=0; j<N_ENTRIES; j++) {
            result[j] = arr1[j] + arr2[j];
        }
        for(int j=0; j<N_ENTRIES; j++) {
            std::cout << result[j] << " ";
        }
        std::cout <<"\n\n\n";
    }

    std::cout << "\n";
    return 0;
}
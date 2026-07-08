#include <iostream>
#include <vector>
#include <string>


void removeCopies(std::vector<int>& data){

    if (data.empty())
    return;
    
    int write = 0;

    for (int read = 1; read < data.size(); read++) {
        if (data[read] != data[write]) {
            write++;
            data[write] = data[read];
        }
    }
    data.resize(write + 1);
}

void isAnagram(std::string officer_name, std::string spy_name){
    
    if (officer_name.length() != spy_name.length()) {
        std::cout << "Imposter!" << std::endl;
        return;
    }

    std::vector<int> letters(26, 0);

    for (char c : officer_name) {
        letters[c - 'a']++;
    }

    for (char c : spy_name) {
        letters[c - 'a']--;
    }

    for (int count : letters) {
        if (count != 0) {
            std::cout << "Imposter!" << std::endl;
            return;
        }
    }

    std::cout << "No imposter found!" << std::endl;

}

int main(){

    /*Use other test cases to make sure you program works*/
    std::vector<int> server = {1,1,2,2,2,3,3,4,5,6,6,6};

    /*Print out the original server vector before function called*/
     for (auto data : server){
        std::cout << data << " "; // 1,1,2,2,2,3,3,4,5,6,6,6
    }

    removeCopies(server);
    
    /*Print out the modification of the server vector after function called*/
    for (auto data : server){
        std::cout << data << " ";
    }

    std::cout << std::endl;

    /****************************TEST ANAGRAM*************************************/

    isAnagram("syeda", "aysed"); // No imposter detected!
    isAnagram("angelo", "annabeth"); // IMPOSTER! IMPOSTER!

    return 0;

}

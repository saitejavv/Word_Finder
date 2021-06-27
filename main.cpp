///
//Word Searcher
///
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


bool search(const std::string &word, const std::string &target){
    std::size_t found = target.find(word);
    if (found == std::string::npos)
        return false;
        else
        return true;
}


int main(){
    std::ifstream in_file{};
    std::string word{};
    std::string word_read{};
    int word_count{0};
    int match_count{0};
    
    in_file.open("../romeoandjuliet.txt");
    if(!in_file){
        std::cerr<<"Invalid file name"<<std::endl;
        return 1;
    }
    
    std::cout<<"What do you me want to search for?:"<<std::endl;
    std::cin>>word;
    while(in_file>>word_read){
        ++word_count;
        if(search(word,word_read)){
            ++match_count;
        }
    } 

    std::cout<<word_count<<" words were searched..."<<std::endl;
    std::cout<< word<<" "<< " was found "<< match_count <<" "<< " times"<< std::endl;
    
    in_file.close();
    std::cout << std::endl;
    return 0;
}

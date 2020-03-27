#include<string>
#include<stdexcept>
#include<iostream>
#include "PhoneticFinder.hpp"

using namespace std;
string phonetic::find(string text, string word){

    text = text + " ";
    string newWord = "";

    for(auto it = text.begin(); it != text.end(); it++){
        
        if(*it == ' '){
            if(word.size() == newWord.size()){
                int counter = 0;
                for(int i = 0; i < newWord.size(); i++){
                    if(newWord.at(i) == word.at(i)){
                        counter++;
                    }

                    else if(newWord.at(i) == word.at(i) + 32 || newWord.at(i) == word.at(i) - 32){
                        counter++;
                    }

                    else if(newWord.at(i)=='v' || newWord.at(i)=='V' || newWord.at(i)=='w' || newWord.at(i)=='W'){
                        if(word.at(i)=='v' || word.at(i)=='V' || word.at(i)=='w' || word.at(i)=='W'){
                            counter++;
                        }
                    }

                    else if(newWord.at(i)=='b' || newWord.at(i)=='f' || newWord.at(i)=='p' || newWord.at(i)=='B' || newWord.at(i)=='F' || newWord.at(i)=='P'){
                        if(word.at(i)=='b' || word.at(i)=='f' || word.at(i)=='p' || word.at(i)=='B' || word.at(i)=='F' || word.at(i)=='P'){
                            counter++;
                        }
                    }

                    else if(newWord.at(i)=='j' || newWord.at(i)=='J' || newWord.at(i)=='g' || newWord.at(i)=='G'){
                        if(word.at(i)=='j' || word.at(i)=='J' || word.at(i)=='g' || word.at(i)=='G'){
                            counter++;
                        }
                    }

                    else if(newWord.at(i)=='c' || newWord.at(i)=='k' || newWord.at(i)=='q' || newWord.at(i)=='C' || newWord.at(i)=='K' || newWord.at(i)=='Q'){
                        if(word.at(i)=='c' || word.at(i)=='k' || word.at(i)=='q' || word.at(i)=='C' || word.at(i)=='K' || word.at(i)=='Q'){
                            counter++;
                        }
                    }

                    else if(newWord.at(i)=='s' || newWord.at(i)=='z' || newWord.at(i)=='S' || newWord.at(i)=='Z'){
                        if(word.at(i)=='s' || word.at(i)=='z' || word.at(i)=='S' || word.at(i)=='Z'){
                            counter++;
                        }
                    }

                    else if(newWord.at(i)=='d' || newWord.at(i)=='t' || newWord.at(i)=='D' || newWord.at(i)=='T'){
                        if(word.at(i)=='d' || word.at(i)=='t' || word.at(i)=='D' || word.at(i)=='T'){
                            counter++;
                        }
                    }

                    else if(newWord.at(i)=='o' || newWord.at(i)=='u' || newWord.at(i)=='O' || newWord.at(i)=='U'){
                        if(word.at(i)=='u' || word.at(i)=='o' || word.at(i)=='U' || word.at(i)=='O'){
                            counter++;
                        }
                    }

                    else if(newWord.at(i)=='i' || newWord.at(i)=='y' || newWord.at(i)=='I' || newWord.at(i)=='Y'){
                        if(word.at(i)=='y' || word.at(i)=='i' || word.at(i)=='I' || word.at(i)=='Y'){
                            counter++;
                        }
                    }
                }

                if(counter == newWord.size()){
                    return newWord;
                }
                       
            }

            newWord = "";

        }else{
            newWord += *it;
        }

    }
    if(newWord=="") throw std::out_of_range{"invalid word"};
    return newWord;
}
#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string, std::size_t;
//this function would return true or false ny checking if the given word with match with a word at the given poistion. 
bool AtListPosition(string const &word_list, string const &word, size_t position ) {
    int counter=0;
    for (int i =0; i < static_cast<int>(word.size()); i++){counter++;} // this for loop would get how many letters are in the word
    // this if-statement would check if the poistion at 0 and if it was,
    // it will not check if there is a ',' before the world and would only check if there is a ',' after
    if ((position==0)) { 
        // this if statment bwlow would check if the word characters larger or equalt to the word_list size and if it was true,
        // it wouldn't check if there is a ',' after
        if (((position+counter) >= word_list.size())){ 
            if ((word_list.substr(position, counter)) == word){return true;} // if the word is a match it would return true
            else{return false;}}
        if (((word_list.substr(position, counter)) == word)&& (word_list.at(position+counter))==',' ){return true;} // check if the word match 
        else {return false;}}
    if (word_list.size() - (position+counter) >=1){ // check if the word is not at the beginning or the end
        if (((word_list.substr(position, counter)) == word)&&(word_list.at(position-1) == ',') && (word_list.at(position+counter) == ',')){
            return true;}
        else {return false;}} 
    else { // check if the word was at the end of the list and if it was, it wouldn't check if there is ',' after the word
        if (((word_list.substr(position, counter)) == word)&&(word_list.at(position-1) == ',')) {return true;}
        else {return false;}
    } 
}
//this function return the first poistion of a given word and takes a word list and a word to look for and an optional position
 size_t FindInList(string const &word_list, string const &word, size_t position =0){
    size_t result;
    result = word_list.find(word,position); // this line would check the word wasn't in the word_list, it would store sting:npos
    if (result == string::npos) {
        return string::npos;}
    // this would loop on the word_list and check if the word is a match and not part of other word
    for (int i =position; i  < static_cast<int> (word_list.size()); i++){ 
        if (AtListPosition(word_list,word,i)) { // if it was a match it would store the poisiton in a variable called result
            result = i;
            break;}
    }
    if (AtListPosition(word_list,word,result)){  //check if the word is a match, it would return the poistion
        return result;
    }
    return string::npos; 
}
// this function would take a list of word and two other words and check which one of these two words come first in the word list
string GetFirstInList(string const &word_list, string *word1,  string *word2) {
    size_t first_word_index=  FindInList(word_list,(*word1));
    size_t second_word_index=  FindInList(word_list,(*word2));
    if (first_word_index < second_word_index) {// this if statment would evaluate if the first word appeared before the second word
        // this if statement below  would check if the word is not part of another word, 
        //if it was true it would return true otherwise "N/A".
        if (AtListPosition(word_list,*word1,first_word_index)){return (*word1);} 
        else {return "N/A";}
    }
    else if (first_word_index > second_word_index){// this if statment would evaluate if the second word appeared before the first word
        if (AtListPosition(word_list,*word2,second_word_index)){
            return (*word2);}
        else {return "N/A";}
    }
    else{return "N/A";} // it would return "N/A" if the words were not in the list
}
// this function would take a word list and a word and return how many times the word were in the list
size_t CountInList( string const &word_list, string const &word) {
    size_t count = 0;
    size_t position=0;
    // this loop would check if the word was in the list at the given position starting from 0 and if it found the word,
    //it would take the poistion of the word and add 1 to the poistion of where that word were found and keep repeting the process.
    while (FindInList(word_list,word,position) != string::npos ) { 
        position = FindInList(word_list,word,position) +1;
        count++;
    }
    return count;
}
int main(){
    string first_word, second_word, word_list;
    cin >> first_word >> second_word;
    while (cin >> word_list){ // this loop would  keep asking for a list until it it hit EOF
        cout << GetFirstInList(word_list , &first_word, &second_word) << ' ' << CountInList(word_list, first_word) << ' ';
        cout << CountInList(word_list, second_word) <<endl;
    }
}

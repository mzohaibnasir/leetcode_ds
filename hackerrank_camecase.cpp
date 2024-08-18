#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;



void parsingInput(const string &input_txt){
    cout << "input_txt: " << input_txt << std::endl;
    

    string input_txt_operation = input_txt.substr(0,1);
    cout<< "input_txt_operation: |" << input_txt_operation<<"|"<<endl;

    string input_txt_type = input_txt.substr(2,1);
    cout<<"input_txt_type: "<<input_txt_type<<endl;

    string input_txt_name = input_txt.substr(4);
    cout<<"input_txt_name: "<< input_txt_name<<endl;



    if(input_txt_operation == "C"){
        cout<<"we'll be combining..."<<endl;
        
    }
    if(input_txt_operation == "S"){
        cout<<"we'll be spliting..."<<endl;
        // split(input_txt_name);
    }



    // return "000"
}


// void split(string &name )




int main() {
    // string input;
    // while (getline(cin, input)) {
    //     char operation = input[0];

    //     char type = input[2];
    //     string data = input.substr(4);

    //     if (operation == 'S') {
    //         // Split Camel Case
    //         if (type == 'M') {
    //             data = data.substr(0, data.size() - 2); // Remove the '()'
    //         }
    //         splitCamelCase(data);
    //     } else if (operation == 'C') {
    //         // Combine to Camel Case
    //         createCamelCase(data, type);
    //     }
    // }
    // cout<<"Input: "<<endl;
    // cin >> input;  // Reads a single word
    // string input_txt =  "C;V;mobile phone";
    string input_txt = "S;M;plasticCup()";
    // cout << "You entered: " << input_txt << std::endl;
    parsingInput(input_txt);

    /* split/combine:  Method/Vaariable/Class: string
    S;M;plasticCup()
    C;V;mobile phone
    */
    return 0;
}

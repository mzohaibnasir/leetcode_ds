#include<iostream>
#include<vector>
#include<string>
#include <limits> // Include the limits header

using namespace std;


vector<int> breakingRecords(vector<int> scores) {
    
    // int min_score = 999, max_score = 0;
    // int min_score = -numeric_limits<int>::infinity();
    // int max_score = numeric_limits<int>::infinity();

    int max_score = scores[0];
    int min_score = scores[0];
    int count_min_record_broke=0;
    int count_max_record_broke=0;


    
    for(int i=0; i< scores.size(); i++ ){
        int current_score = scores[i];
        if(current_score > max_score){
            max_score = current_score;
            count_max_record_broke++;
        }
        if(current_score < min_score){
            min_score = current_score;
            count_min_record_broke++;
        }
    }

    // cout<<"max_score: "<<max_score<<"  min_score: "<<min_score<<endl;
        cout<<"count_max_record_broke: "<<count_max_record_broke<<"  count_min_record_broke: "<<count_min_record_broke<<endl;

    return scores;

}


int main()
{
    vector<int> scores;
    scores = {10, 5, 20, 20, 4, 5,2, 25,1}; // Initialize with a list of values
    // for(int i=0; i<scores.size(); i++){
    //     cout<<scores[i]<<"\t";
    // }
    
    breakingRecords(scores);
    return 0;
}

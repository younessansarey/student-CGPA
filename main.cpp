#include <iostream>  
#include <vector> // Include to use std::vector  
#include <string> // Include to use std::string  
#include <map>
#include <numeric>








#include <fstream> // For file operations  









using namespace std;  

int main() {  
    // Get the count of courses from user  
    int course_count;  
    cout << "How many courses? ";  
    cin >> course_count;  

    // Use a vector to hold course names  
    vector<string> course_names(course_count); 
    vector<int> course_scores(course_count);
    vector<int> course_weights(course_count);
    vector<int> course_values(course_count);

    // Input course names from the user  
    for (int i = 0; i < course_count; ++i) {  
        cout << "Enter name for course no. " << (i + 1) << " name: ";  
        cin >> course_names[i];
        
        cout << "Enter name for course " << course_names[i] << " score: ";
        cin >> course_scores[i];
        
        cout << "Enter name for weight " << course_names[i] << " weight: ";
        cin >> course_weights[i];
        
        course_values [i] = (course_scores[i])*(course_weights[i]);
    }

    // Output the course names  
    cout << endl << "Your course names are: { ";  
    for (const auto& name : course_names) { // Range-based for loop  
        cout << name << ", ";  
    }  
    cout << "}" << endl;

    // Output the course scores  
    cout << endl << "Your course names are: { ";  
    for (const auto& score : course_scores) { // Range-based for loop  
        cout << score << ", ";  
    }  
    cout << "}" << endl;

    // Output the course weights  
    cout << endl << "Your course names are: { ";  
    for (const auto& weight : course_weights) { // Range-based for loop  
        cout << weight << ", ";  
    }  
    cout << "}" << endl;

    // Output the course values
    cout << endl << "Your course names are: { ";  
    for (const auto& value : course_values) { // Range-based for loop  
        cout << value << ", ";  
    }  
    cout << "}" << endl;

    // Create a map (dictionary) to store the assignments  
    map<string, int> assignmentMap;  

    // Assuming both vectors are of equal length  
    size_t size = min(course_names.size(), course_scores.size());  
    for (size_t i = 0; i < size; ++i) {  
        assignmentMap[course_names[i]] = course_scores[i]; // Assigning elements to the map  
    }  

    // Output the assignments  
    cout << "Assignments:" << endl;  
    for (const auto& pair : assignmentMap) {  
        cout << pair.first << " is paired with " << pair.second << endl;  
    }

    // calculate the average of scores
    int scores_sum = accumulate(course_scores.begin(),course_scores.end(),0);
    cout << "The sum of scores is: "<< scores_sum << endl;

    int scores_values_sum = accumulate(course_values.begin(),course_values.end(),0);
    cout << "The sum of values is: "<< scores_values_sum << endl;

    int weights_sum = accumulate(course_weights.begin(),course_weights.end(),0);
    cout << "The sum of scores is: "<< scores_sum << endl;
    
    int score_average = scores_values_sum / weights_sum;
    cout << "The sum of scores is: "<< score_average << " out of 20" << endl;








    // Create and open a CSV file  
    ofstream csvFile("student_results.csv");  
    if (!csvFile) {  
        cout << "Error opening file for writing." << endl;  
        return 1; // Exit if file cannot be opened  
    }  

    // Write headers to the CSV file  
    csvFile << "Course Name,Score,Weight,Value\n";  

    // Write course information to CSV file  
    for (int i = 0; i < course_count; ++i) {  
        csvFile << "course count: " << course_count << ","
                << "course name: " << course_names[i] << ","   
                << "course score: " << course_scores[i] << ","   
                << "course weight: " << course_weights[i] << ","   
                << "course value: " << course_values[i] << ",\n";  
    }  
    csvFile << "Average: " << score_average << "\n";

    csvFile.close(); // Close the file  
    cout << "Results saved to student_results.csv." << endl;
















    return 0;  
}
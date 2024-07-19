# student-CGPA
This program has been written by using C++. in (.\vscode) folder there are some .json configuration files which can help you to compile .cpp project in vscode easily.

### Explanation of the Code

#### 1. **Header Files**
```cpp
#include <iostream>
#include <vector> // Include to use std::vector
#include <string> // Include to use std::string
#include <map>
#include <numeric>
#include <fstream> // For file operations  
```
- **`<iostream>`**: Includes the standard input-output stream library. It is necessary for using `cout` and `cin`.
- **`<vector>`**: Includes functionality for dynamic arrays (vectors).
- **`<string>`**: Includes functionality for using the `std::string` class.
- **`<map>`**: Includes the functionality to use maps (associative arrays).
- **`<numeric>`**: Includes functions for numeric operations, particularly for accumulation.
- **`<fstream>`**: Enables file input and output operations.

#### 2. **Namespace Declaration**
```cpp
using namespace std;
```
- This line allows you to use members of the `std` namespace without explicitly prefixing them with `std::`. For example, you can use `cout` instead of `std::cout`.

#### 3. **Main Function**
```cpp
int main() {
```
- This is the entry point of the program.

#### 4. **Get Course Count from User**
```cpp
int course_count;  
cout << "How many courses? ";  
cin >> course_count;  
```
- **`course_count`**: Variable to store the number of courses the user wishes to input. The program prompts the user for this number.

#### 5. **Vectors Initialization**
```cpp
vector<string> course_names(course_count); 
vector<int> course_scores(course_count);
vector<int> course_weights(course_count);
vector<int> course_values(course_count);
```
- Four vectors are declared to store:
  - **Course names** as strings.
  - **Scores** as integers.
  - **Weights** as integers.
  - **Values** calculated from scores and weights.

#### 6. **Input Course Data**
```cpp
for (int i = 0; i < course_count; ++i) {
    cout << "Enter name for course no. " << (i + 1) << " name: ";  
    cin >> course_names[i];
    
    cout << "Enter name for course " << course_names[i] << " score: ";
    cin >> course_scores[i];
    
    cout << "Enter name for weight " << course_names[i] << " weight: ";
    cin >> course_weights[i];
    
    course_values[i] = (course_scores[i]) * (course_weights[i]);
}
```
- A loop runs for `course_count` iterations, prompting the user to input:
  - Name of each course.
  - Score for each course.
  - Weight for each course.
- **Course Value Calculation**: Each course's value is calculated as the product of its score and weight and stored in the `course_values` vector.

#### 7. **Output Course Data**
```cpp
// Output the course names  
cout << endl << "Your course names are: { ";  
for (const auto& name : course_names) {  
    cout << name << ", ";  
}  
cout << "}" << endl;

// Similar blocks for course scores, weights, and values...
```
- The program outputs the names, scores, weights, and values of the courses. Each output is formatted by iterating over the respective vector and printing each element.

#### 8. **Create a Map for Assignments**
```cpp
map<string, int> assignmentMap;  
size_t size = min(course_names.size(), course_scores.size());  
for (size_t i = 0; i < size; ++i) {  
    assignmentMap[course_names[i]] = course_scores[i]; // Assigning elements to the map  
}
```
- A map (`assignmentMap`) is created to link course names (as keys) to their scores (as values).
- A loop populates this map by associating each course name with its corresponding score.

#### 9. **Output Assignments**
```cpp
cout << "Assignments:" << endl;  
for (const auto& pair : assignmentMap) {  
    cout << pair.first << " is paired with " << pair.second << endl;  
}
```
- This section outputs the course assignments, showing the mapping of each course name with its score.

#### 10. **Calculate Averages**
```cpp
int scores_sum = accumulate(course_scores.begin(), course_scores.end(), 0);
...
int score_average = scores_values_sum / weights_sum;
```
- **Accumulating Scores**: The program calculates the sum of all scores and values using the `accumulate` function.
- It computes the average score based on the total weighted score and the sum of weights.

#### 11. **Creating and Writing to CSV File**
```cpp
ofstream csvFile("student_results.csv");  
if (!csvFile) {  
    cout << "Error opening file for writing." << endl;  
    return 1; // Exit if file cannot be opened  
}  
```
- Open a file named `student_results.csv` for writing. If it fails, an error message is displayed, and the program exits.

```cpp
// Write headers and course information
csvFile << "Course Name,Score,Weight,Value\n";  
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
```
- The program writes the headers and the collected data for each course into the CSV file.
- Finally, it appends the average score and closes the file, confirming the results have been saved.

#### 12. **Returning from Main**
```cpp
return 0;  
```
- This line indicates successful completion of the program. `0` is returned to the operating system.

### Summary
The code creates a simple console-based program that:
1. Prompts the user for the number of courses.
2. Collects course names, scores, and weights for a specified number of courses.
3. Calculates course values (score multiplied by weight).
4. Outputs all entered data and calculated values.
5. Saves the data to a CSV file for further use.

Overall, this program effectively demonstrates the use of vectors, maps, loops, and file handling in C++.

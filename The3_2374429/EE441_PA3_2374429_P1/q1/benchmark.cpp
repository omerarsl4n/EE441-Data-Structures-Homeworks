#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "class.hpp"
#include <chrono>

using namespace std;

extern int count_BST_items;



// Function to read a matrix from a text file and store it in a 2D vector, ignoring white spaces
Matrix readMatrixFromFile(string filename)
{
	// open the file
	ifstream file(filename);

	// create a 2D vector to store the matrix
	vector<vector<int>> matrix;

	// read the file line by line
	string line;
	while (getline(file, line))
	{
		// create a vector to store the row
		vector<int> row;

		// parse the line and extract the elements of the row
		stringstream ss(line);
		int element;
		while (ss >> element)
			row.push_back(element);

		// add the row to the matrix
		matrix.push_back(row);
	}

	// close the file
	file.close();
    Matrix temp(matrix.size());
    for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)temp.setelement(i,j,matrix[i][j]);
	}
	return temp;
}


int main()
{
    string main_location = "C:/Users/omarf/Desktop/EEE/4.1SINIF/EE441/Codes/The3_2374429/matrices/";
     BST_Node* root = NULL;
     int ct = 0;
     double result_time;
     double average_time=0;
     double avg_time[30];
     long average_count_BST=0;
     long avg_count[30];
	std::ofstream out("Output_BST.txt");
	for(int i=11;i<=15;i++){
        for(int j=0;j<=4;j++){
            ct++;
            Matrix A(i);
            Matrix root_mat(1);//just for simple root creation, it is required for proper operation in my algorithm!
            count_BST_items=0;//for each operation reset the counter
            int N=i;
            root = GetNode(root_mat,NULL,NULL,1);

            string x = main_location + to_string(i) + "/" + to_string(j) + ".txt";
            out << x<<endl;

            A = readMatrixFromFile(x);
            A.Info();

            auto start = std::chrono::steady_clock::now();
            out << "det: "<<find_det(A,A.SIZE,root)<<endl;
            auto finish = std::chrono::steady_clock::now();

            result_time = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count();
            average_time += result_time; // add samples to average time
            average_count_BST += count_BST_items; //add  memory usages to average memory
            out << "Time to compute the determinant: " << result_time << endl;
            out << "Memory usage to compute the determinant: " << count_BST_items << endl;
            avg_time[ct] = (average_time/ct);
            avg_count[ct] = (average_count_BST/ct);
            out << "Average time to compute any matrices determinant: " << (average_time/ct) << endl;   //scale it in every loop, ct counts number of data averaging
            out << "Average memory usage to compute the determinant: " << (average_count_BST/ct) << endl;  //scale it in every loop, ct counts number of data averaging
            out << endl;
        }
	}
	out <<"Average time samples" << endl;
    for(int i=1;i<=25;i++)out << avg_time[i]<<", ";
    out << endl;
    out <<"Average count samples" << endl;
    for(int i=1;i<=25;i++)out << avg_count[i]<<", ";

	out.close();
	return 0;
}

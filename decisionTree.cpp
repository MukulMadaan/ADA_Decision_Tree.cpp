#include <bits/stdc++.h>

using namespace std;

//Class to create the node of decision tree
class decisionTree {
	
	public:
		decisionTree *group[10];
		string groupName;
		vector<int> element;
		
};

//Create New Node
decisionTree *newNode() 
{ 

    decisionTree *temp = new decisionTree(); 
    return temp;
	 
}
 
//Print the group
void printInfo(decisionTree* root, int x) {
	
	decisionTree* current = root->group[x];
	for(int i = 0;i < current->element.size(); i++){
		cout<<current->element[i]<<" ";
	}
	
}

//Print the group in sorted order
void sortedprintInfo(decisionTree* root, int x) {
	
	decisionTree* current = root->group[x];
	sort(current->element.begin(), current->element.end());
	for(int i = 0;i < current->element.size(); i++){
		cout<<current->element[i]<<" ";
	}
	
}

//Find the group number
void findGroup(int number) {
	
	cout<<"The Group Number in which the element is: "<<number%10;
	
}

//Enter a New number
void newElement(decisionTree* root, int number){
	
	int groupNumber = number%10;
	root->group[groupNumber]->element.push_back(number);
	
}

//Logic to create the group
void createGroup(decisionTree* root, int input[32][32]) {

	for(int i = 0; i < 10; i++){
		root->group[i] = newNode();
	}
	
	int groupNumber;
	
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 32; j++) {
			groupNumber = input[i][j]%10;
			root->group[groupNumber]->element.push_back(input[i][j]);
		}
	}
	
}

//Main Funtion call
int main() { 

	int input[32][32];
	
	decisionTree* root = new decisionTree();
	root->groupName = "Decision Tree";
	
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 32; j++) {
			input[i][j] = rand()%1025;
			
		}
	}
	
	createGroup(root, input);
	findGroup(33);
	int gNumber;
	int flag = 1;
	while(flag){
		cout<<"\nEnter the Group that you want to display:\t";
		cin>>gNumber;
		printInfo(root,gNumber);
		cout<<"\nOkay. Now in an organised fashion\n";
		sortedprintInfo(root,gNumber);
		cout<<"\nDo you Wish to Continue?\t";
		cin>>flag;
	}
}

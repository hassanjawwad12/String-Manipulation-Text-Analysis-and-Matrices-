// Hassan Jawwad 20L-1122 F Assignment 1
#include<iostream>
#include<string>
using namespace std;

void CountLetters(char* arr, int*& alph, int& size)
{
	char capital = 65;//It is the ASCII of capitalized A 
	char small = 97;//It is the ASCII OF small a

	int frequency = 0, number = 0;//initialized 2 variables to be used later 
	size = 26;//the number of English Alphabets are 26 so size is taken as 26

	while (capital < 91)// A to Z the ASCII is 65-90 that's why this condition is used inside the loop
	{
		int i = 0;
		frequency = 0;
		while (arr[i] != '\0')
		{
			if (arr[i] == capital || arr[i] == small)// the alphabtes of array are compared with the English Alphabets 
			{
				frequency++;// the frequency of alphabets is incremented 
			}
			i++;
		}
		alph[number] = frequency;//the array to store frequency is made equal to the frequency
		number++;

		capital++;// the capital and small english alphabets are incremented using their ASCII 
		small++;

	}
	small = 97;

	cout << endl;

	int i = 0;
	while (i < size)//Loop to display the frequency of each alphabet in the string entered by the user 
	{
		cout << "Frequency of " << small << " : " << alph[i] << endl;
		small++;//alphabtes are incremented 
		i++;
	}
}

int main()
{
	int choice = 0;
	cout << " Enter your coice: ";
	cin >> choice;//choice is taken by the user 
	cin.ignore();
	if (choice == 1)
	{
		char* msg = new char[100];//pointer is assigned and a dynamic array is created in heap
		int* alphabets = new int[27];//another integer dynamic array is created in heap
		int length = 50;//randomly set the length to 50
		cout << "Enter the message: ";//message is enytered by the user 
		cin.getline(msg, 100);
		CountLetters(msg, alphabets, length);//function is called 
	}
	

	system("pause");
	return 0;
}
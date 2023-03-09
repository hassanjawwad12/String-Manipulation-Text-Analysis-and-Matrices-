//Hassan Jawwad 20L-1122 Assignment 1 
#include<iostream>
#include<cstring>
using namespace std;

int Strlen(char* s1)
{
    int length = 0;
    //we calculate the length of the string manually by running the loop till its end
    for (int i = 0; s1[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}
char* Strcpy(char* s1, const char* s2)
{
    //we copy the second string into first string 
    for (int i = 0; s1[i] != '\0'; ++i)
    {
        s1[i] = s2[i];
    }
    return s1;

}
char* StrCat(char* s1, const char* s2)
{
    int length = 0;
    //we copy the second string into first string from the point wher it ends 
    for (int i = 0; s1[i] != '\0'; i++)
    {
        length++;
    }
    int j = 0;
    int i = 0;
    s1[length] = ' ';
    for (i = length + 1; s2[j] != '\0'; i++)
    {
        s1[i] = s2[j];
        j++;
    }
    s1[i] = '\0';
    return s1;

}

int StrCmp(char* s1, const char* s2)
{
    int flag = 0;


    //run loop for both strings till the end 
    while (*s1 != '\0' || *s2 != '\0')
    {
        if (*s1 == *s2)
        {
            s1++;
            s2++;
        }

        // If two characters are not same then find which is big 
        else if ((*s1 == '\0' && *s2 != '\0') || (*s1 != '\0' && *s2 == '\0') || *s1 != *s2)
        {
            flag = 1;
            if (*s1 > * s2)
            {
                return 1;
            }
            else if (*s1 < *s2)
            {
                return -1;
            }
        }
    }

    // If two strings are equal then
    if (flag == 0)
    {
        return 0;
    }

}
char** StrTok(char* str1, const char s2)
{
    char token[20];
    int i = 0, j = 0;
    for (i = 0; str1[i]; i++)
    {
        if (str1[i] == s2)
            continue;
        j = 0;
        while (1)
        {
            token[j] = str1[i];
            i++;
            j++;
            if (str1[i] == s2 || str1[i] == '\0')
            {
                token[j] = '\0';
                cout << token;
                break;
            }
        }
        if (str1[i] == '\0')
            break;
    }
    return 0;
}
int StarFind(char* s1, char* s2)
{

    int l = 0; //Hold length of second string

    //finding length of second string
    for (l = 0; s2[l] != '\0'; l++);

    int i, j;

    for (i = 0, j = 0; s1[i] != '\0' && s2[j] != '\0'; i++)
    {
        if (s1[i] == s2[j])
        {
            j++;
        }
        else
        {
            j = 0;
        }
    }//we find the position of substring in a string
    int position = (i - j + 1);
    if (j == l)
        cout << "Substring found ";
    return position;
    if (j != l)
        cout << "Substring not found";
    return -1;

}

char* Substr(char* s1, int pos, int len)
{
    //we distract the substring from a string 
    char* substr = new char[100];
    int length = 0;

    for (int i = 0; s1[i] != '\0'; i++)
    {
        length++;
    }
    if (pos > 0 && pos < 30 && len < length)
    {
        int i = pos, stopping_position;
        cout << "\n";
        for (int j = 0; i < length && len > 0; i++, j++)
        {
            substr[j] = s1[i];
            len--;
            stopping_position = j;
        }
        substr[stopping_position + 1] = '\0';

        for (int k = 0; substr[k] != '\0'; k++)
            return substr;
    }
    else
        cout << "Values are invalid\n";
}
char* Strncpy(char* s1, const char* s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        s1[i] = s2[i];
    }
    return s1;
}
char* StrnCat(char* s1, char* s2, int n)
{
    int len = Strlen(s1);
    for (int i = len, j = 0; j < n; i++, j++)
    {
        s1[i] = s2[j];
    }
    return s1;
}
int main()
{
    int choice = 0;
    cout << "Enter 1 to find length of a string!" << endl;
    cout << "Enter 2 to copy string!" << endl;
    cout << "Enter 3 to concatenate strings!" << endl;
    cout << "Enter 4 to compare strings!" << endl;
    cout << "Enter 5 to tokenize a string!" << endl;
    cout << "Enter 6 to find occurence of substring in a string!" << endl;
    cout << "Enter 7 to distract substring from a string! " << endl;
    cout << "Enter 8 to copy strings upto n characters!" << endl;
    cout << "Enter 9 to concatenate strings upto n characters!" << endl;
    cin >> choice;
    if (choice == 1)
    {
        char* msg = new char[100];//we have assigned pointer
        cin.ignore();
        cout << "Enter the string: ";
        cin.getline(msg, 100);//string is input by the user 
        cout << "The entered string is: " << msg << endl;
        cout << "The lengh of the string is: " << Strlen(msg);
    }
    if (choice == 2)
    {
        char* msg1 = new char[100];//we have assigned pointer
        char* msg2 = new char[100];
        cin.ignore();
        cout << "Enter the first string: ";
        cin.getline(msg1, 100);//string is input by the user 
        cout << "Enter the second string: ";
        cin.getline(msg2, 100);
        cout << "After copying string 2 in string 1 the string 1 has now become: " << Strcpy(msg1, msg2);
    }

    if (choice == 3)
    {

        char* msg1 = new char[100];//we have assigned pointer
        char* msg2 = new char[100];
        cin.ignore();
        cout << "Enter the first string: ";
        cin.getline(msg1, 100);//string is input by the user 
        cout << "Enter the second string: ";
        cin.getline(msg2, 100);
        cout << endl;
        cout << "String before concatenation: " << endl;
        cout << "string 1= " << msg1 << endl;//original strings are shown
        cout << "string 2= " << msg2 << endl;
        cout << "String after concatenation becomes :" << endl;
        cout << StrCat(msg1, msg2);
    }

    if (choice == 4)
    {
        char* msg1 = new char[100];//we have assigned pointer
        char* msg2 = new char[100];
        cin.ignore();
        cout << "Enter the first string: ";
        cin.getline(msg1, 100);//string is input by the user 
        cout << "Enter the second string: ";
        cin.getline(msg2, 100);
        cout << endl;
        int result = StrCmp(msg1, msg2);
        if (result == 0)
        {
            cout << "Strings are equal" << endl;
        }
        if (result == 1)
        {
            cout << "String 1 is greater than string 2" << endl;
        }
        if (result == -1)
        {
            cout << "String 1 is samller than string 2" << endl;
        }

    }
    if (choice == 5)
    {
        char* msg1 = new char[100];//we have assigned pointer
        char msg2 = ' ';

        cin.ignore();
        cout << "Enter the first string: ";
        cin.getline(msg1, 100);//string is input by the user 

        cout << endl;
        StrTok(msg1, msg2);
    }
    if (choice == 6)
    {
        char* msg1 = new char[100];//we have assigned pointer
        char* msg2 = new char[100];
        cin.ignore();
        cout << "Enter the first string: ";
        cin.getline(msg1, 100);//string is input by the user 
        cout << "Enter the second string: ";
        cin.getline(msg2, 100);
        cout << endl;
        cout << "  The occurence is at " << StarFind(msg1, msg2);
    }
    if (choice == 7)
    {
        int position, length;
        char* msg1 = new char[100];// we have assigned the pointer 
        cin.ignore();
        cout << "Enter the string: ";
        cin.getline(msg1, 100);
        cout << "Enter position: ";
        cin >> position;
        cout << "Enter the length: ";
        cin >> length;
        cout << Substr(msg1, position, length);
    }
    if (choice == 8)
    {
        int num;
        cout << "Enter the amount of characters you want to copy: ";
        cin >> num;
        char* msg1 = new char[100];//we have assigned pointer
        char* msg2 = new char[100];
        cin.ignore();
        cout << "Enter the first string: ";
        cin.getline(msg1, 100);//string is input by the user 
        cout << "Enter the second string: ";
        cin.getline(msg2, 100);
        cout << "After copying string 2 in string 1 the string 1 has now become: " << Strncpy(msg1, msg2, num);
    }

    if (choice == 9)
    {
        int num;
        cout << "Enter the number of characters: ";
        cin >> num;
        char* msg1 = new char[100];//we have assigned pointer
        char* msg2 = new char[100];
        cin.ignore();
        cout << "Enter the first string: ";
        cin.getline(msg1, 100);//string is input by the user 
        cout << "Enter the second string: ";
        cin.getline(msg2, 100);
        cout << endl;
        cout << "String before concatenation: " << endl;
        cout << "string 1= " << msg1 << endl;//original strings are shown
        cout << "string 2= " << msg2 << endl;
        cout << "String after concatenation becomes :" << endl;
        cout << StrnCat(msg1, msg2,num);
    }

    system("pause");
    return 0;
}